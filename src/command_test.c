/**
 * @brief Comprueba las funciones de command.h
 *
 * @file command_test.c
 * @author Andrea Salcedo López
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/command.h"
#define N_CMD 10


int main(){
  T_Command comand = NO_CMD;
  char * opcion = NULL;

  comand = command_get_user_input(opcion);
  if (comand == UNKNOWN){
     printf("Error al introducir el comando\n");
     return -1;
  }

  printf("Se ha introducido correctamente el comando\n");

  comand = command_get_user_input(opcion);
    if (comand == UNKNOWN){
       printf("Error al introducir el comando\n");
       return -1;
    }

  printf("Se ha introducido correctamente el comando\n");


  return 0;
}
