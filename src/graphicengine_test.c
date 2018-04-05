/**
 * @brief Comprueba las funciones de graphic_engine.h
 *
 * @file graphicengine_test.c
 * @author Andrea Salcedo López
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/graphic_engine.h"
#include "../include/screen.h"

int main(){

  Graphic_engine * ge = NULL;
  Game * game = NULL;


  ge = graphic_engine_create();
  if (ge == NULL){
     printf("\nImposible de crear");
     return -1;
  }

  game = game_create();
  if (game == NULL){
     graphic_engine_destroy(ge);
     printf("\nImposible crear el juego");
     return -1;
  }


  graphic_engine_paint_game(ge, game);

  graphic_engine_destroy(ge);

  game_destroy(game);


  return 0;
}
