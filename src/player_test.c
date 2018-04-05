/**
 * @brief Comprueba las funciones de player.h
 *
 * @file player_test.c
 * @author Alba Ramos Pedroviejo
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdio.h>
#include "../include/player.h"

int main(){
	Player *player = NULL;

	player = player_create(1);

	if(!player){
		printf("\nImposible crear jugador");
		return -1;
	}

	if (player_set_name(player, "Alba") == ERROR){
		printf("\nImposible setear el nombre");
		player_destroy(player);
		return -1;
	}

	printf("\nEl jugador se llama %s\n", player_get_name(player));


	if (player_set_id(player, 2) == ERROR){
		printf("\nImposible setear el id");
		player_destroy(player);
		return -1;
	}

	printf("\nEl jugador tiene el id %ld\n", player_get_id(player));

	if (player_set_location(player, 2) == ERROR){
		printf("\nImposible setear la ubicacion");
		player_destroy(player);
		return -1;
	}

	printf("\nEl jugador se encuentra en el espacio %ld\n", player_get_location(player));
	printf("\nEl jugador se encuentra en el espacio %ld\n", player_get_location(player));


	if(player_get_mochila(player) == NULL){
		printf("\nImposible obtener la mochila");
		player_destroy(player);
		return -1;
	}


	if (player_add_object(player, 2) == ERROR){
		printf("\nImposible agregar objeto a la mochila");
		player_destroy(player);
		return -1;
	}
	player_print(player);

	if (player_add_object(player, 4) == ERROR){
		printf("\nImposible agregar objeto a la mochila");
		player_destroy(player);
		return -1;
	}

	player_print(player);

	if (player_del_object(player, 2) == ERROR){
		printf("\nImposible eliiminar objeto de la mochila");
		player_destroy(player);
		return -1;
	}


	player_print(player);

	player_destroy(player);

	return 0;
}
