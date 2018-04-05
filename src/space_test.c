/**
 * @brief Comprueba las funciones de space.h
 *
 * @file space_test.c
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/space.h"
#include "../include/set.h"

int main(){

  Space *space;
  char cadena[10]="Espacio 1";
  char desc[WORD_SIZE + 1];

  space=space_create(10);

  if(space==NULL){
    printf("Error al crear el espacio");
    return -1;
  }

  space_set_name(space,cadena);

  space_set_north(space,1);

  space_set_south(space,2);

  space_set_east(space,3);

  space_set_west(space,4);

  space_set_description(space, "Esto es un espacio");
  space_get_description(space, desc);

  printf("\nEspacio tras modificar la descripcion: descripcion es -->%s\n", desc);

  space_add_object(space,11);
  space_add_object(space,12);

  printf("Espacio tras haber introducido dos objetos\n\n");

  space_print(space);

  if(space_object(space,11)==TRUE){
    printf("\n\nEl espacio contiene el objeto con el id 11\n\n");
  }

  space_del_object(space,11);
  space_del_object(space,12);

  printf("Espacio tras haber sacado ambos objetos:\n\n");

  space_print(space);

  space_destroy(space);

  return 0;
}
