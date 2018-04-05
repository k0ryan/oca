/**
 * @brief It implements the die interface
 *
 * @file die.c
 * @author Ana Roa González
 * @version 1.0
 * @date 24-02-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/die.h"

/**
*
* @struct _Die
* @brief Representa un dado
*/

struct _Die{
  Id id; /*!< identificador del dado */
  int numero; /*!< ultimo numero sacado por el dado */
};

Die* die_create(){

  Die* dado;

  dado=(Die*)malloc(sizeof(Die));
  if(dado==NULL){
    return NULL;
  }

  dado->id=NO_ID;
  dado->numero=-1;

  return dado;

}

STATUS die_destroy(Die* dado){

  if(dado==NULL) {
    return ERROR;
  }

  free(dado);
  dado=NULL;

  return OK;

}

Id die_get_id(Die* dado){

  if(dado==NULL){
    return NO_ID;
  }

  return dado->id;

}

STATUS die_set_id(Die* dado, Id id){

  if(dado==NULL || id==NO_ID){
    return ERROR;
  }

  dado->id=id;

  return OK;

}

int die_get_numero(Die* dado){

  if(dado==NULL){
    return -1;
  }

  return dado->numero;

}

STATUS die_set_numero(Die* dado, int numero){

  if(dado==NULL || numero==-1){
    return ERROR;
  }

  dado->numero=numero;

  return OK;

}

int aleatorio(int a, int b){

  if(a==0 || b==0){
    return 0;
  }
  return (int) (a + (double) rand() / (RAND_MAX-1) * (b - a + 1));
}

STATUS die_roll(Die* dado){

  if(dado==NULL){
    return ERROR;
  }

  dado->numero=aleatorio(1, 6);

  return OK;

}

STATUS die_print(FILE* pf ,Die* dado){

  if(dado==NULL){
    return ERROR;
  }

  fprintf(pf, "ID: %ld\n Dado:%d\n", dado->id, dado->numero);

  return OK;

}
