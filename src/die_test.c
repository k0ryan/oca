/**
 * @brief Comprueba las funciones de die.h
 *
 * @file die_test.c
 * @author Ana Roa González
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../include/die.h"

int main(){

  Die* dado;

  dado=die_create();
  if(dado==NULL) return -1;

  die_set_id(dado, 1);


  srand((unsigned)time(NULL));
  die_roll(dado);
  die_print(stdout, dado);

  die_roll(dado);
  die_print(stdout, dado);

  die_roll(dado);
  die_print(stdout, dado);

  die_roll(dado);
  die_print(stdout, dado);

  die_roll(dado);
  die_print(stdout, dado);

  die_roll(dado);
  die_print(stdout, dado);

  die_roll(dado);
  die_print(stdout, dado);

  die_roll(dado);
  die_print(stdout, dado);


  die_destroy(dado);

  return 0;
}
