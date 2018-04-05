/**
 * @brief Comprueba las funciones de link.h
 *
 * @file link_test.c
 * @author Alba Ramos Pedroviejo
 * @version 1.0
 * @date 24-03-2018
 */

#include "../include/link.h"

int main(){

	Link *link;

	link = link_create();
	if (!link) return -1;

	if(link_set_name(link, "prueba") == ERROR){
		link_destroy(link);
		return -1;
	}

	if(link_set_id(link, 666) == ERROR){
		link_destroy(link);
		return -1;
	}

	if(link_set_space1(link, 1) == ERROR){
		link_destroy(link);
		return -1;
	}

	if(link_set_space2(link, 2) == ERROR){
		link_destroy(link);
		return -1;
	}

	if(link_set_status(link, 1) == ERROR){
		link_destroy(link);
		return -1;
	}

	link_print(stdout, link);

	if(link_set_status(link, 0) == ERROR){
		link_destroy(link);
		return -1;
	}

	link_print(stdout, link);

	link_destroy(link);


  return 0;
}
