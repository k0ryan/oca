/**
 * @brief Comprueba las funciones de gamereader.h
 *
 * @file gamereader_test.c
 * @author Ana Roa González
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/gamereader.h"
#include "../include/game.h"
#include "../include/object.h"
#include "../include/link.h"
#include "../include/space.h"

int main(int argc, char* argv[]){

  Game* game = NULL;

  game = game_create();
  if (game == NULL){
     return -1;
  }

 if(game_create_from_file(game, "data.dat")==OK){
    printf("\nCrea bien el juego\n");
  }

  if(game_load_spaces(game, "data.dat")==OK){
    printf("\nLee bien los espacios\n");
  }

  if(game_load_objects(game, "data.dat")==OK){
    printf("\nLee bien los objetos\n");
  }

  if(game_load_links(game, "data.dat")==OK){
    printf("\nLee bien los links\n");
  }

  game_destroy(game);

  return 0;
}
