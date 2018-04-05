/**
 * @brief Comprueba las funciones de inventory.h
 *
 * @file inventory_test.c
 * @author Laura Sanchez Herrera
 * @version 1.0
 * @date 24-03-2018
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/inventory.h"


 int main(){

   Inventory *mochila;

   mochila=inventory_create();

   if(mochila==NULL){
     printf("Error al crear mochila\n");
     return -1;
   }

   if(inventory_is_empty(mochila)==TRUE){
     printf("Mochila vacia\n\n");
   }

   inventory_set_max(mochila,3);
   inventory_add_id(mochila,1);
   inventory_add_id(mochila,2);
   inventory_add_id(mochila,3);

   printf("Mochila al introducir tres elementos:\n\n");

   inventory_print(stdout,mochila);

   if(inventory_is_full(mochila)==TRUE){
     printf("\n\nLa mochila esta llena\n\n");
   }

   inventory_del_id(mochila,2);

   printf("Mochila al eliminar el objeto con el id 2:\n\n");

   inventory_print(stdout,mochila);

   if(inventory_contains(mochila,1)==TRUE){
     printf("\n\nLa mochila contiene el id 1\n\n");
   }

   inventory_destroy(mochila);

   return 0;

 }
