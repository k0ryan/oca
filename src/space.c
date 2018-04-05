/**
 * @brief It implements the space interface
 *
 * @file space.c
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 09-02-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/space.h"

/**
*
* @struct _Space
* @brief Representa un espacio
*/

struct _Space {
  Id id; /*!< identificador del espacio */
  char name[WORD_SIZE + 1]; /*!< nombre del espacio */
  Id north; /*!< identificacdor del link del norte */
  Id south; /*!< identificacdor del link del sur */
  Id east; /*!< identificacdor del link del este */
  Id west; /*!< identificacdor del link del oeste */
  Set *objects; /*!< conjunto de objetos */
  char gdesc[MAX_CADENA];/*!< cadena que guarda los dibujos */
  char description[WORD_SIZE + 1]; /*!< cadena que guarda la descripcion del espacio */
};

Space* space_create(Id id) {

  Space *newSpace = NULL;

  if (id == NO_ID)
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));

  if (newSpace == NULL) {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;

  newSpace->objects =set_create();

  newSpace->gdesc[0]= '\0';
  newSpace->description[0]= '\0';

  return newSpace;
}

STATUS space_destroy(Space* space) {

  if (!space) {
    return ERROR;
  }

  if(set_destroy(space->objects)==ERROR){
    return ERROR;
  }

  free(space);
  space = NULL;

  return OK;
}

STATUS space_set_cadena(Space *space, char *cadena){

  if(space==NULL || cadena==NULL){
    return ERROR;
  }

  if(strlen(cadena)>0){
    strcat(space->gdesc,cadena);
  }else{
    strcpy(space->gdesc,cadena);
  }

  return OK;

}

char* space_get_cadena(Space *space){

  if(space==NULL){
    return NULL;
  }

  return space->gdesc;

}

STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

STATUS space_set_object(Space* space, Set *objects) {
  if (space==NULL || objects==NULL) {
    return ERROR;
  }
  space->objects = objects;

  return OK;
}

STATUS space_add_object(Space* space, Id id) {
  if (space==NULL || id==NO_ID) {
    return ERROR;
  }

  if(set_add(space->objects,id)==ERROR){
    return ERROR;
  }

  return OK;

}

STATUS space_del_object(Space* space, Id id){

  if(space==NULL || id==NO_ID ){
    return ERROR;
  }

  if(set_del(space->objects,id)==ERROR){
    return ERROR;
  }

  return OK;

}

const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

Id space_get_id_next(Space *space){

  Id aux;

  if(space==NULL){
    return NO_ID;
  }

  aux=space_get_id(space);

  aux=aux+1;

  if(aux==26){
    return NO_ID;
  }

  return aux;

}

Id space_get_id_back(Space *space){

  Id aux;

  if(space==NULL){
    return NO_ID;
  }

  aux=space_get_id(space);

  aux=aux-1;

  if(aux==0){
    return NO_ID;
  }

  return aux;

}

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

Set* space_get_objects(Space* space) {
  if (space==NULL) {
    return NULL;
  }

  if(set_get_top(space->objects)==0){
    return NULL;
  }

  return space->objects;
}

BOOL space_object(Space* space, Id id){

  if(space==NULL || id==NO_ID){
    return FALSE;
  }

  if(set_id(space->objects,id)==FALSE){
    return FALSE;
  }

  return TRUE;

}

STATUS space_set_description(Space *space, char *cadena){
	if (!space || !cadena) return ERROR;

	if(strcpy(space->description, cadena) == ERROR) return ERROR;

	return OK;
}


STATUS space_get_description(Space *space, char *cadena){
	if (!space || !cadena) return ERROR;

	if(strcpy(cadena, space->description) == 0) return ERROR;

	return OK;
}

STATUS space_print(Space* space) {
  Id idaux = NO_ID;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  if (space_get_objects(space)) {
    fprintf(stdout, "---> Objects in the space.\n");
  } else {
    fprintf(stdout, "---> No objects in the space.\n");
  }

  if(space->description != NULL){
	fprintf(stdout, "Description: %s", space->description);
  }

  return OK;
}
