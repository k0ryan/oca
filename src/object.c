/**
 * @brief It implements the object interface
 *
 * @file object.c
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 08-02-2018
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "../include/types.h"
 #include "../include/object.h"

 /**
 *
 * @struct _Object
 * @brief Representa un objeto
 */

 struct _Object{
   Id id; /*!< identificador del objeto*/
   char name[WORD_SIZE + 1]; /*!<nombre del objeto*/
   char description[WORD_SIZE + 1]; /*!<descripción del objeto*/
 };

 Object* object_create(Id id){

   Object *newObject=NULL;

   if(id==NO_ID){
     return NULL;
   }

   newObject=(Object*)malloc(sizeof(Object));

   if(newObject==NULL){
     return NULL;
   }

   newObject->id=id;

   newObject->name[0] = '\0';

   return newObject;

 }

 STATUS object_destroy(Object* object){

   if(object==NULL){
     return ERROR;
   }

   free(object);
   object=NULL;

   return OK;

 }

Id object_get_id(Object* object){

  if(object==NULL){
    return NO_ID;
  }

  return object->id;
}

STATUS object_set_id(Object* object, Id id){

  if(object==NULL || id==NO_ID){
    return ERROR;
  }

  object->id=id;

  return OK;

}

const char* object_get_name(Object* object){

  if(object==NULL){
    return NULL;
  }

  return object->name;

}

STATUS object_set_name(Object* object, char* name){

  if(object==NULL || name==NULL){
    return ERROR;
  }

  if((strcpy(object->name,name))==0){
    return ERROR;
  }

  return OK;

}

STATUS object_get_description(Object *object, char *cadena){
	if(object==NULL || cadena==NULL){
    return ERROR;
  }

  if((strcpy(cadena, object->description))==0){
    return ERROR;
  }

  return OK;
}

STATUS object_set_description(Object *object, char *cadena){
	if(object==NULL || cadena==NULL){
    return ERROR;
  }

  if((strcpy(object->description,cadena))==0){
    return ERROR;
  }

  return OK;
}

STATUS object_print(Object* object){

  if(object==NULL){
    return ERROR;
  }

  fprintf(stdout, "\nObjeto con id %ld y con nombre %s\n", object->id, object->name);
  if(object->description != NULL){
	  fprintf(stdout, "\nSu descripcion es: %s\n", object->description);
  }


  return OK;

}
