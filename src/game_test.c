/**
 * @brief Comprueba las funciones de game.h
 *
 * @file game_test.c
 * @author Andrea Salcedo López
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/game.h"
#define MAX 25

int main(){

  Game * juego = NULL;
  Object* objeto = NULL;
  char cadena[MAX];
  Space* espacio = NULL;
  Link* enlace = NULL;
  char opcion[MAX];
  T_Command comando = NO_CMD;
  T_Command cmd = NO_CMD;
  T_Command dado = NO_CMD;
  char* control = NULL;
  int i = 0;

  for (i= 0; i< MAX; i++){
     opcion[i] = 0;
  }

  for (i= 0; i< MAX; i++){
     cadena[i] = 0;
  }

  juego = game_create();
  if(juego == NULL){
    printf("Imposible crear el juego");
    return 0;
  }

  objeto = object_create(3);
  if(!objeto){
    printf("\nImposible crear objeto");
    game_destroy(juego);
    return 0;
  }

  espacio = space_create(9);
  if(espacio == NULL){
     printf("Error al crear el espacio");
     game_destroy(juego);
     return 0;
  }

  enlace = link_create();
  if(enlace == NULL){
     printf("Error al crear el enlace");
     game_destroy(juego);
     return 0;
  }

  if(game_set_player_location(juego, 2) == ERROR){
     printf("Error al modificar la localizacion del jugador\n");
     game_destroy(juego);
     object_destroy(objeto);
     return 0;
  }

  printf("El jugador se encuentra en la casilla %ld\n", game_get_player_location(juego));

  printf("\nTiramos el dado para comprobar su funcionamiento\n");

  dado = command_get_user_input(opcion);
  if (dado == NO_CMD){
     printf("Error en el comando\n");
     game_destroy(juego);
     return 0;
  }

  if(game_update(juego, dado, opcion) == ERROR){
     printf("Error en el comando a introducir\n");
     game_destroy(juego);
     return 0;
  }

  printf("\nEl ultimo numero del dado es %d\n", game_get_die_roll(juego));

  if(game_add_object(juego, objeto) == ERROR){
     printf("Error al añadir el objeto\n");
     game_destroy(juego);
     return 0;
  }

  objeto = game_get_object(juego, 3);
  if(objeto == NULL){
     printf("Error al devolver el objeto\n");
     game_destroy(juego);
     return 0;
  }

  if(game_add_space(juego, espacio) == ERROR){
     printf("Error al añadir el espacio\n");
     game_destroy(juego);
     return 0;
  }

  espacio = game_get_space(juego, 9);
  if(espacio == NULL){
     printf("Error al devolver el espacio\n");
     game_destroy(juego);
     return 0;
  }

  if(game_add_link(juego, enlace) == ERROR){
     printf("Error al añadir el enlace\n");
     game_destroy(juego);
     return 0;
  }

  if(link_set_id(enlace, 6) == ERROR){
    printf("Error\n");
    game_destroy(juego);
    return 0;
  }

  enlace = game_get_link(juego, 6);
  if(enlace == NULL){
     printf("Error al devolver el enlace\n");
     game_destroy(juego);
     return 0;
  }

  if(game_set_object_location(juego, 9, 2) == ERROR){
     printf("Error al modificar la localizacion del objeto\n");
     game_destroy(juego);
     return 0;
  }

  printf("\nEl objeto se encuentra en la localizacion %ld\n", game_get_object_location(juego, 2));

  printf("\nLa id del objeto es %ld\n", game_object_name_to_id(juego, cadena));

  if(game_screen_object(juego, cadena) == ERROR){
     printf("Error al imprimir los objetos\n");
     game_destroy(juego);
     return 0;
  }

  if(game_screen_space_objects(juego, espacio, cadena) == ERROR){
     printf("Error al imprimir el objeto del espacio\n");
     game_destroy(juego);
     return 0;
  }


  if(game_screen_player_objects(juego, cadena) == ERROR){
    printf("\nEl jugador no ha cogido ningun objeto\n");
  }

  else{
    printf("\nEl jugador ha cogido el objeto correctamente\n");
  }

  if (space_set_north(espacio, 9) == ERROR){
      printf("Error al introducir el norte\n");
      game_destroy(juego);
      return 0;
  }

  if (space_set_south(espacio, 9) == ERROR){
      printf("Error al introducir el sur\n");
      game_destroy(juego);
      return 0;
  }

  if (space_set_east(espacio, 9) == ERROR){
      printf("Error al introducir el este\n");
      game_destroy(juego);
      return 0;
  }

  if (space_set_west(espacio, 9) == ERROR){
      printf("Error al introducir el oeste\n");
      game_destroy(juego);
      return 0;
  }


  printf("\nLa id del espacio en esa posicion es %ld\n", game_get_space_id_at(juego, 9));

  if(game_link_open(juego, enlace) == TRUE){
     printf("\nEl enlace esta cerrado\n");
  }
  else{
     printf("\nEl enlace esta abierto\n");
  }

  cmd = command_get_user_input(opcion);
  if (cmd == NO_CMD){
     printf("Error en el comando\n");
     game_destroy(juego);
     return 0;
  }

  if(game_update(juego, cmd, opcion) == ERROR){
     printf("Error en el comando a introducir\n");
     game_destroy(juego);
     return 0;
  }

  comando = game_get_last_command(juego);
  if (comando == NO_CMD){
     printf("Error al introducir el comando\n");
     game_destroy(juego);
     return 0;
  }

  control = game_get_control(juego);
  if (control == NULL){
      printf("Error en la cadena de comandos\n");
      game_destroy(juego);
      return 0;
  }

  printf("\nEl comando se ha ejecutado %s\n", control);

  if (game_get_option(juego, opcion) == ERROR){
     printf("Error al devolver la opcion de un comando");
     game_destroy(juego);
     return 0;
  }

  game_print_data(juego);

  if (game_screen_paints(juego, espacio, cadena, 2) == ERROR){
    printf("Error al imprimir los dibujos en las casillas\n");
    game_destroy(juego);
    return 0;
  }

  if(game_is_over(juego) == FALSE){
     printf("\nEl juego se ha terminado\n");
  }
  else{
    printf("\nEl juego continua\n");
  }

  game_destroy(juego);

  return 0;
}
