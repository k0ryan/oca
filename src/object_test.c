/**
 * @brief Comprueba las funciones de object.h
 *
 * @file object_test.c
 * @author Alba Ramos Pedroviejo
 * @version 1.0
 * @date 24-03-2018
 */


#include <stdio.h>
#include "../include/object.h"


int main(){
	Object *object = NULL;
	char cadena[255];


	object = object_create(666);
	if(!object){
		printf("\nImposible crear objeto");
		return -1;
	}

	object_set_id(object, 20);
	printf("\nObjeto con id: %ld", object_get_id(object));

	if(object_set_name(object, "linterna") == ERROR){
		printf("\nImposible crear objeto");
		return -1;
	}

	printf("\nObjeto de nombre %s", object_get_name(object));

	if(object_set_description(object, "La descripcion mas simple del mundo") == ERROR){
		printf("\nImposible setear descripcion del objeto");
		return -1;
	}

	object_get_description(object, cadena);

	printf("\nObjeto de descripcion %s", cadena);

	object_print(object);


	object_destroy(object);

	return 0;
}
