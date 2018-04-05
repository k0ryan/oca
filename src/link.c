/**
 * @brief It implements the link interface
 *
 * @file link.c
 * @author Alba Ramos Pedroviejo
 * @version 1.0
 * @date 22-02-2018
 */

#include <stdlib.h>
#include <string.h>
#include "../include/link.h"

#define MAX_NAME 25

/**
*
* @struct _Link
* @brief Representa un enlace
*/

struct _Link{
	Id id; /*!< identificador único del enlace*/
	char name [MAX_NAME + 1];/*!< nombre del enlace*/
	Id space1; /*!< indica el espacio de origen*/
	Id space2; /*!< indica el espacio enlazado con el espacio origen*/
	int status; /*!< indica si el enlace está abierto ('1') o cerrado ('0')*/
};

Link * link_create(){
	Link *link;

	link = (Link *)malloc(sizeof (Link));
	if(!link) return NULL;

	link->id = NO_ID;
	strcpy(link->name, "");
	link->space1 = NO_ID;
	link->space2 = NO_ID;
	link->status = 0;

	return link;
}

void link_destroy(Link *link){
	if (!link) return;

	free(link);
}

STATUS link_set_id(Link *link, Id id){
	if(!link || id == NO_ID) return ERROR;

	link->id = id;

	return OK;
}

STATUS link_set_name(Link *link, char *name){
	if(!link || !name || strlen(name) > MAX_NAME) return ERROR;

	strcpy(link->name, name);

	return OK;
}

STATUS link_set_space1(Link *link, Id s1){
	if(!link || s1 == NO_ID) return ERROR;

	link->space1 = s1;

	return OK;
}

STATUS link_set_space2(Link *link, Id s2){
	if(!link || s2 == NO_ID) return ERROR;

	link->space2 = s2;

	return OK;
}

STATUS link_set_status(Link *link, int status){
	if(!link || status < 0 || status > 1) return ERROR;

	link->status = status;

	return OK;
}

Id link_get_id(Link *link){
	if(!link) return NO_ID;

	return link->id;
}

char * link_get_name(Link *link){
	if(!link) return NULL;

	return link->name;
}

Id link_get_space1(Link *link){
	if(!link) return NO_ID;

	return link->space1;
}

Id link_get_space2(Link *link){
	if(!link) return NO_ID;

	return link->space2;
}

int link_get_status(Link *link){
	if(!link) return NO_ID;

	return link->status;
}

void link_print(FILE *f, Link *link){
	if(!f || !link) return;

	fprintf(f, "\nEnlace de id %ld y nombre %s."
			"Espacio uno: %ld. Espacio dos: %ld.",
			link->id, link->name, link->space1, link->space2);

	if(link->status == 1){
		fprintf(f, "Estado: abierto");
	}

	else{
		fprintf(f, "Estado: cerrado");
	}
}
