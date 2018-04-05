/**
 * @brief Comprueba las funciones de set.h
 *
 * @file set_test.c
 * @author Andrea Salcedo López
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdlib.h>
#include <stdio.h>
#include "../include/set.h"

int main(){

	Set *conj;
	Id id = 5;
	Id d = 2;
	Id c = 9;

	conj = set_create();
	if(conj == NULL) return -1;

	set_add(conj, id);

	set_add(conj, d);

	set_add(conj, c);

	printf("PILA\n");

	set_print(stdout, conj);

	set_del(conj, d);

	printf("PILA\n");

	set_print(stdout, conj);

	set_del(conj, id);

	printf("PILA\n");

	set_print(stdout, conj);

	set_destroy(conj);

	return 0;
}
