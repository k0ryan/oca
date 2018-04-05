/**
 * @brief It implements the inventory interface
 *
 * @file inventory.c
 * @author Alba Ramos Pedroviejo
 * @version 1.0
 * @date 24-02-2018
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/inventory.h"

/**
*
* @struct _Inventory
* @brief Representa una mochila
*/

struct _Inventory{
  Set *ids; /*!< conjunto de ids*/
  int max;  /*!< numero maximo de ids*/
};


Inventory * inventory_create(){
  Inventory *inv = NULL;

  inv = (Inventory *)malloc(sizeof(Inventory));
  if(!inv) return NULL;

  inv->ids =set_create();
  inv->max = 0;

  return inv;
}

STATUS inventory_destroy(Inventory *inv){
  if(!inv) return ERROR;

  set_destroy(inv->ids);

  free(inv);

  return OK;
}

BOOL inventory_is_full(Inventory *inv){

  if(inv==NULL){
    return FALSE;
  }

  if(inv->max==set_get_top(inv->ids)){
    return TRUE;
  }

  return FALSE;
}

BOOL inventory_is_empty(Inventory *inv){

  if(inv==NULL){
    return TRUE;
  }

  if(set_is_empty(inv->ids)==TRUE){
    return TRUE;
  }

  return FALSE;

}

STATUS inventory_set_ids(Inventory *inv, Set *ids){
  if(!inv || !ids) return ERROR;

  inv->ids = ids;

  return OK;

}

Set * inventory_get_ids(Inventory *inv){
  if(!inv) return NULL;

  return inv->ids;
}

STATUS inventory_set_max(Inventory *inv, int max){
  if(!inv || max <= 0) return ERROR;

  inv->max = max;

  return OK;
}

int inventory_get_max(Inventory *inv){
  if(!inv) return 0;

  return inv->max;
}

STATUS inventory_add_id(Inventory *inv, Id id){
  if(!inv || id == NO_ID) return ERROR;

  if(set_add(inv->ids, id) == ERROR){
    return ERROR;
  }

  return OK;

}

STATUS inventory_del_id(Inventory *inv, Id id){
  if(!inv || id == NO_ID) return ERROR;

  if(set_del(inv->ids, id) == ERROR) return ERROR;

  return OK;
}

BOOL inventory_contains(Inventory *inv, Id id){
  if(inv == NULL || id == NO_ID) return FALSE;

  return set_id(inv->ids, id);
}

int inventory_print(FILE *f, Inventory *inv){
  int cuenta = 0;

  if(!inv || !f) return 0;

  cuenta += set_print(f, inv->ids);
  cuenta += fprintf(f, "\nMaximo contenido: %d", inv->max);

  return cuenta;

}
