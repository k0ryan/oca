/**
 * @brief It implements the player interface
 *
 * @file player.c
 * @author Ana Roa González
 * @version 1.0
 * @date 09-02-2018
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "../include/player.h"

/**
*
* @struct _Player
* @brief Representa un jugador
*/

struct _Player{
    Id id; /*!<identificador del jugador*/
    char name[WORD_SIZE + 1]; /*!<nombre del jugador*/
    Id location; /*!<localizacion del jugador*/
    Inventory *mochila; /*!<conjunto de objetos que tiene el jugador*/
};

Player* player_create(Id id){

 	Player *newPlayer = NULL;

  if(id==NO_ID){
    return NULL;
  }

  newPlayer=(Player*)malloc(sizeof(Player));

  if(newPlayer==NULL){
    return NULL;
  }

  newPlayer->id=id;

  newPlayer->name[0]= '\0';

  newPlayer->location=NO_ID;

  newPlayer->mochila=inventory_create();
  if(!newPlayer->mochila) return NULL;

  inventory_set_max(newPlayer->mochila,4);

  return newPlayer;

  }

STATUS player_destroy(Player *player){

  if(player==NULL){
    return ERROR;
  }

  inventory_destroy(player->mochila);

  free(player);
  player=NULL;

  return OK;

}

Id player_get_id(Player *player){

  if(player==NULL){
    return NO_ID;
  }

  return player->id;

}

STATUS player_set_id(Player *player, Id id){

  if(player==NULL || id==NO_ID){
    return ERROR;
  }

  player->id=id;

  return OK;

}

const char* player_get_name(Player *player){

  if(player==NULL){
    return NULL;
  }

  return player->name;

}


STATUS player_set_name(Player *player, char *name){

  if(player==NULL || name==NULL){
    return ERROR;
  }

  if((strcpy(player->name,name))==0){
    return ERROR;
  }

  return OK;

}

Id player_get_location(Player *player){

  if(player==NULL){
    return NO_ID;
  }

  return player->location;

}

STATUS player_set_location(Player *player, Id location){

  if(player==NULL || location==NO_ID){
    return ERROR;
  }

  player->location=location;

  return OK;

}

Inventory * player_get_mochila(Player *player){

  if(player==NULL){
    return NULL;
  }

  return player->mochila;

}

STATUS player_set_mochila(Player *player, Inventory *mochila){

  if(player==NULL){
    return ERROR;
  }

  player->mochila=mochila;

  return OK;

}

STATUS player_add_object(Player *player, Id object){
  if(!player || object == NO_ID) return ERROR;

  if(inventory_add_id(player->mochila, object) == ERROR) return ERROR;

  return OK;
}

STATUS player_del_object (Player *player, Id object){
  if(!player || object == NO_ID) return ERROR;

  if(inventory_del_id(player->mochila, object) == ERROR) return ERROR;

  return OK;
}

BOOL player_contains(Player *player, Id id){
  if(!player || id == NO_ID) return FALSE;

  return inventory_contains(player->mochila, id);
}

STATUS player_print(Player* player){

  if(player==NULL){
    return ERROR;
  }

  fprintf(stdout, "\nJugador de id %ld  y nombre %s. Ubicado en el espacio %ld\nContenido de la mochila:", player->id, player->name, player->location);
  inventory_print(stdout,player->mochila);
  fprintf(stdout, "\n");

  return OK;

}
