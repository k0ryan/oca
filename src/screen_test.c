/**
 * @brief Comprueba las funciones de screen.h
 *
 * @file screen_test.c
 * @author Andrea Salcedo López
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/screen.h"
#define DATOS 30

int main(){

  Area *area = NULL;
  char datos[DATOS];
  int i = 0;

  for (i=0; i<DATOS ; i++){
      datos[i] = 0;
  }

  screen_init();

  screen_paint();

  screen_gets(datos);

  area = screen_area_init(1, 1, 1, 1);
  if (!area){
     screen_destroy(datos);
     printf("\nImposible crear el area");
     return -1;
  }

 screen_area_reset_cursor(area);

 screen_area_clear(area);

 screen_area_puts(area, datos);

 screen_area_destroy(area);

 screen_destroy(datos);

  return 0;
}
