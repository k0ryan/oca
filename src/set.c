/**
 * @brief It implements the set interface
 *
 * @file set.c
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 22-02-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/set.h"

/**
*
* @struct _Set
* @brief Representa un conjunto
*/

struct _Set{

  Id id[MAXID]; /*!<Array de identificadores*/
  int top; /*!<Numero de identificadores que hay en el conjunto*/

};

 Set* set_create(){

   int i;

   Set *conjunto;

   conjunto=(Set*)malloc(sizeof(Set));

   if(conjunto==NULL){
     return NULL;
   }

   for(i=0;i<MAXID;i++){
     conjunto->id[i]=NO_ID;
   }

   conjunto->top=0;

   return conjunto;

 }

 STATUS set_destroy(Set *conjunto){

   if(conjunto==NULL){
     return ERROR;
   }

   free(conjunto);
   conjunto=NULL;

   return OK;

 }

 int set_get_top(Set *conjunto){

   if(conjunto==NULL){
     return -1;
   }

   return conjunto->top;
 }

 Id set_get_id(Set *conjunto, int position){

   if(conjunto==NULL || position<0 || position>=conjunto->top){
     return NO_ID;
   }

   return conjunto->id[position];
 }

 STATUS set_add(Set *conjunto, const Id id){

   int i;

   if(conjunto==NULL || id==NO_ID){
     return ERROR;
   }

  if(conjunto->top==(MAXID-1)){
    return ERROR;
  }

  for(i=0;i<conjunto->top;i++){
    if(id==conjunto->id[i]){
      return ERROR;
    }
  }

  conjunto->id[conjunto->top]=id;

  conjunto->top++;

  return OK;

 }

 BOOL set_is_full(Set *conjunto){

   if(conjunto==NULL){
     return FALSE;
   }

   if(conjunto->top==MAXID){
     return TRUE;
   }

   return FALSE;

 }

 BOOL set_is_empty(Set *conjunto){

   if(conjunto==NULL){
     return TRUE;
   }

   if(conjunto->top==0){
     return TRUE;
   }

   return FALSE;

 }

 STATUS set_del(Set *conjunto, const Id id){

   int i;
   int j;
   int z;

   if(conjunto==NULL || id==NO_ID){
     return ERROR;
   }

   for(i=0;i<conjunto->top;i++){
     if(id==conjunto->id[i]){
       conjunto->id[i]=NO_ID;
       for(j=0,z=i;j<((conjunto->top-1)-i);j++,z++){
         conjunto->id[z]=conjunto->id[z+1];
       }
       conjunto->id[conjunto->top-1]=NO_ID;
       conjunto->top--;
       return OK;
     }
   }

   return ERROR;

 }

 BOOL set_id(Set *conjunto, Id id){

   int i;

   if (conjunto==NULL || id==NO_ID){
     return FALSE;
   }

   for(i=0;i<conjunto->top;i++){
     if(id==conjunto->id[i]){
       return TRUE;
     }
   }

   return FALSE;

 }

 STATUS set_print(FILE *f, const Set *conjunto){

   int i;

   if(conjunto==NULL || f == NULL){
     return ERROR;
   }

   for(i=0;i<conjunto->top;i++){

      fprintf(f,"Objeto numero %d: su id es %ld\n",i+1, conjunto->id[i]);
   }

   return OK;

 }
