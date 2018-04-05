/**
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 *
 * @file game.c
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 16-02-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../include/game.h"
#include "../include/gamereader.h"

#define N_CALLBACK 11


/**
*
* @struct _Game
* @brief Representa un juego
*/

struct _Game{
  Player *player; /*!< jugador del juego */
  Object *object[MAXOBJECT]; /*!< array de los objetos del juego */
  Space* spaces[MAX_SPACES + 1]; /*!< array de los espacios del juego */
  Link* link[MAXLINK]; /*!< array de los links del juego */
  T_Command last_cmd; /*!< ultimo comando introducido por teclado */
  char option[WORD_SIZE+1]; /*!< nombre del objeto que cogera el jugador */
  Die* dado; /*!< dado del juego */
  STATUS control; /*!< control de errores de los comandos */
};

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);

/**
   List of callbacks for each command in the game
*/

/**
* @brief Comando desconocido
* @param game: Puntero a Game
* @return
*/

void game_callback_unknown(Game* game);

/**
* @brief Sale del juego
* @param game: Puntero a Game
* @return
*/

void game_callback_exit(Game* game);

/**
* @author Ana Roa González
* @brief Avanza a la siguiente casilla
* @param game: Puntero a Game
* @return
*/

void game_callback_following(Game* game);

/**
* @author Ana Roa González
* @brief Retroce a la casilla anterior
* @param game: Puntero a Game
* @return
*/

void game_callback_previous(Game* game);

/**
* @author Laura Sánchez Herrera
* @brief Coge un objeto de la casilla actual
* @param game: Puntero a Game
* @return
*/

void game_callback_Grasp_object(Game* game);

/**
* @author Laura Sánchez Herrera
* @brief Deja el objeto en la casilla actual
* @param game: Puntero a Game
* @return
*/

void game_callback_Drop_object(Game* game);

/**
* @author Ana Roa González
* @brief Tira el dado
* @param game: Puntero a Game
* @return
*/

void game_callback_roll_die(Game* game);

/**
* @author Laura Sánchez Herrera
* @brief Avanza a la casilla de la izquierda
* @param game: Puntero a Game
* @return
*/

void game_callback_left(Game *game);

/**
* @author Laura Sánchez Herrera
* @brief Avanza a la casilla de la derecha
* @param game: Puntero a Game
* @return
*/

void game_callback_right(Game *game);

/**
* @author Alba Ramos Pedroviejo
* @brief Avanza utilizando referencias a enlaces
* @param game: Puntero a Game
* @return
*/

void game_callback_move(Game *game);

/**
* @author Alba Ramos Pedroviejo
* @brief Permite inspeccionar la descripcion de un objeto
* @param game: Puntero a Game
* @return
*/

void game_callback_check(Game *game);


static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_following,
  game_callback_previous,
  game_callback_Grasp_object,
  game_callback_Drop_object,
  game_callback_roll_die,
  game_callback_left,
  game_callback_right,
  game_callback_move,
  game_callback_check
};

/**
   Private functions
*/

/**
   Game interface implementation
*/

Game * game_create() {
  int i;
  Game *game = NULL;

  game = (Game *)malloc(sizeof(Game));
  if(!game) return NULL;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->player= player_create(1);

  for (i = 0; i < MAXOBJECT; i++) {
    game->object[i] = NULL;
  }

  for (i = 0; i < MAXLINK; i++) {
    game->link[i] = NULL;
  }

  game->dado=die_create();

  game->last_cmd = NO_CMD;

  game->control=0;

  return game;
}


STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }

  player_destroy(game->player);

  for (i = 0; (i < MAXOBJECT) && (game->object[i] != NULL); i++) {
    object_destroy(game->object[i]);
  }

  for (i = 0; (i < MAXLINK) && (game->link[i] != NULL); i++) {
    link_destroy(game->link[i]);
  }

  die_destroy(game->dado);

  free(game);

  return OK;
}

STATUS game_set_player_location(Game* game, Id id) {

  if (id == NO_ID || game == NULL) {
    return ERROR;
  }

  if((player_set_location(game->player, id))==ERROR){
    return ERROR;
  }

  return OK;
}

STATUS game_set_object_location(Game* game, Id id, Id object) {

  if (id == NO_ID || game == NULL || object==NO_ID) {
    return ERROR;
  }

  if(space_add_object(game_get_space(game,id),object)==OK){
    return OK;
  }

  return ERROR;

}

Id game_get_player_location(Game* game) {

  if(game==NULL){
    return NO_ID;
  }


  return player_get_location(game->player);

}

Id game_get_object_location(Game* game, Id object) {

  int i;

  if(game==NULL || object==NO_ID){
    return NO_ID;
  }

  for(i=0;i<(MAX_SPACES + 1) && (game->spaces[i]!=NULL);i++){
    if(space_object(game->spaces[i],object)==TRUE){
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;

}

STATUS game_update(Game* game, T_Command cmd, char *option) {

  Id id_player;
  Space *space;

  game->last_cmd = cmd;


  if(cmd==9){
    if(strcmp(option,"n")==0){
      strcpy(option,"north");
    }
    if(strcmp(option,"s")==0){
      strcpy(option,"south");
    }
    if(strcmp(option,"w")==0){
      strcpy(option,"west");
    }
    if(strcmp(option,"e")==0){
      strcpy(option,"east");
    }
  }

  if(cmd==10){
    if(strcmp(option,"s")==0 || strcmp(option,"space")==0 ){
      id_player=game_get_player_location(game);
      space=game_get_space(game,id_player);
      strcpy(option,space_get_name(space));
    }
  }

  strcpy(game->option,option);
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}

STATUS game_screen_object(Game *game, char *cadena){

  int i;
  Id space,obj;
  const char *object_name;

  if(game==NULL || cadena==NULL){
    return ERROR;
  }

  strcpy(cadena,"");

  for(i=0;i < MAXOBJECT && game->object[i] != NULL; i++){

    obj=object_get_id(game->object[i]);
    object_name=object_get_name(game->object[i]);
    space=game_get_object_location(game,obj);
    if(space!=NO_ID){
      sprintf(cadena,"%s%s:%ld, ",cadena,object_name,space);
    }
  }
  cadena[strlen(cadena)-2]='\0';
  return OK;
}

STATUS game_screen_paints(Game *game, Space *space, char *cadena, int option){

  char *cadena_aux;
  int i,j;

  if( game==NULL || space==NULL || cadena==NULL || option<1 || option>3 ){
    return ERROR;
  }

  cadena_aux=space_get_cadena(space);

  if(option==1){
    for(i=0;i<7;i++){
      cadena[i]=cadena_aux[i];
    }
  }
  if(option==2){
    for(i=7,j=0;i<14;i++,j++){
      cadena[j]=cadena_aux[i];
    }
  }

  if(option==3){
    for(i=14,j=0;i<21;i++,j++){
      cadena[j]=cadena_aux[i];
    }
  }

  return OK;

}

STATUS game_screen_player_objects(Game *game, char *cadena){

  int i;
  Id id_object;
  BOOL control;
  const char *object_name;
  Set *mochila;
  Object *object;

  if(game==NULL || cadena==NULL){
    return ERROR;
  }

  strcpy(cadena,"");

  mochila=inventory_get_ids(player_get_mochila(game->player));

  control=inventory_is_empty(player_get_mochila(game->player));

  if(control==TRUE){
    return ERROR;
  }

  for(i=0; i<set_get_top(mochila);i++){
    id_object=set_get_id(mochila,i);
    object=game_get_object(game, id_object);
    object_name=object_get_name(object);
    sprintf(cadena,"%s%s ",cadena,object_name);
  }

  return OK;
}

STATUS game_screen_space_objects(Game *game, Space *space, char *cadena){

  int i;
  int l;
  Id id_object;
  Object *object;
  Set *conjunto;

  if(game==NULL || cadena==NULL || space==NULL){
    return ERROR;
  }

  strcpy(cadena,"");

  conjunto=space_get_objects(space);

  for(i=0;i<set_get_top(conjunto);i++){
       id_object=set_get_id(conjunto,i);
       object=game_get_object(game,id_object);
       sprintf(cadena,"%s%s,",cadena,object_get_name(object));
    }
    cadena[strlen(cadena)-1]='\0';
    l=strlen(cadena);
    for(i=l;i<9;i++){
      sprintf(cadena,"%s%s",cadena," ");
    }

    return OK;

}

void game_print_data(Game* game) {
  int i = 0;
  Id object,space;
  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: \n");

  for(i=0;i < MAXOBJECT && game->object[i] != NULL; i++){
    object=object_get_id(game->object[i]);
    space=game_get_object_location(game,object);
    if(space!=NO_ID){
      printf("%ld:%ld ",object,space);
    }
  }

  printf("=> Player location: %d\n", (int) game_get_player_location(game));
  printf("prompt:> ");
}

BOOL game_is_over(Game* game) {
  return FALSE;
}

char* game_get_control(Game *game){

  if(game==NULL){
    return NULL;
  }

  if(game->control==ERROR){
    return "ERROR";
  }

  if(game->control==OK){
    return "OK";
  }

  return NULL;

}

/**
   Callbacks implementation for each action
*/

void game_callback_unknown(Game* game) {
  game->control=ERROR;
}

void game_callback_exit(Game* game) {
  game->control=OK;
}

void game_callback_following(Game* game) {

  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id destination = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game->control=ERROR;
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {

      current_id = space_get_south(game->spaces[i]);
      if(link_get_status(game_get_link(game, current_id)) == 1){
        destination = link_get_space2(game_get_link(game, current_id));
      }

    if(destination != NO_ID){
      game_set_player_location(game, destination);
      game->control=OK;
    }
    else{
          game->control=ERROR;
    }

      return;
    }
  }
}


void game_callback_previous(Game* game) {

  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id destination = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game->control=ERROR;
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id) {

        current_id = space_get_north(game->spaces[i]);
        if(link_get_status(game_get_link(game, current_id)) == 1){
          destination = link_get_space1(game_get_link(game, current_id));
        }

      if(destination != NO_ID){
        game_set_player_location(game, destination);
        game->control=OK;
      }
      else{
          game->control=ERROR;
      }

      return;
    }
  }
}

void game_callback_Grasp_object(Game* game){

  Id space_player;
  Space *space;
  const char *name_object;
  int i;
  Set *conjunto;

  if(game==NULL){
    game->control=ERROR;
    return;
  }

  space_player=player_get_location(game->player);
  space=game_get_space(game,space_player);
  conjunto=space_get_objects(space);

  for(i=0;i<(MAXOBJECT) && game->object[i]!=NULL;i++){
    name_object=object_get_name(game->object[i]);
    if(strcmp(game->option,name_object)==0){
      if(set_id(conjunto,object_get_id(game->object[i]))==TRUE){
        if(inventory_is_full(player_get_mochila(game->player))!=TRUE){
          player_add_object(game->player, object_get_id(game->object[i]));
          inventory_print(stdout,player_get_mochila(game->player));
          space_del_object(space,object_get_id(game->object[i]));
          game->control=OK;
          return;
        }
      }
    }
  }
  game->control=ERROR;
}

void game_callback_Drop_object(Game* game){

    Id id_space_player;
    Id id_object;
    const char *name_object;
    Space *space;
    Object *object;
    Set *mochila;
    int i;

    if(game==NULL){
      game->control=ERROR;
      return;
    }

    if(inventory_is_empty(player_get_mochila(game->player))==TRUE){
      game->control=ERROR;
      return;
    }

    id_space_player=player_get_location(game->player);
    space=game_get_space(game,id_space_player);
    mochila=inventory_get_ids(player_get_mochila(game->player));

    for(i=0; i<set_get_top(mochila);i++){
      id_object=set_get_id(mochila,i);
      object=game_get_object(game, id_object);
      name_object=object_get_name(object);
      if(strcmp(game->option,name_object)==0){
        space_add_object(space,id_object);
        player_del_object(game->player,id_object);
        game->control=OK;
        return;
      }
    }

    game->control=ERROR;

  }



void game_callback_roll_die(Game* game){

  if(game==NULL){
    game->control=ERROR;
    return;
  }

  if(die_roll(game->dado)==OK){
    game->control=OK;
    return;
  }
  game->control=ERROR;
}

int game_get_die_roll(Game* game){

  if(game==NULL){
    return -1;
  }

  return die_get_numero(game->dado);
}

void game_callback_left(Game *game){

  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id destination = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game->control=ERROR;
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {

        current_id = space_get_west(game->spaces[i]);
        if(link_get_status(game_get_link(game, current_id)) == 1){
          destination = link_get_space1(game_get_link(game, current_id));
        }


        if(destination != NO_ID){
          game_set_player_location(game, destination);
          game->control=OK;
        }
        else{
            game->control=ERROR;
        }

        return;
      }
    }
  }

void game_callback_right(Game *game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id destination = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game->control=ERROR;
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {

      current_id = space_get_east(game->spaces[i]);
      if(link_get_status(game_get_link(game, current_id)) == 1){
        destination = link_get_space2(game_get_link(game, current_id));
      }

    if(destination != NO_ID){
      game_set_player_location(game, destination);
      game->control=OK;
    }
    else{
          game->control=ERROR;
    }

      return;
    }
  }
}


void game_callback_move(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id destination = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game->control=ERROR;
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {

		if(!strcasecmp(game->option, "north")){
		  current_id = space_get_north(game->spaces[i]);
			if(link_get_status(game_get_link(game, current_id)) == 1){
				destination = link_get_space1(game_get_link(game, current_id));
			}

		}

		else if (!strcasecmp(game->option, "south")){
		  current_id = space_get_south(game->spaces[i]);
			if(link_get_status(game_get_link(game, current_id)) == 1){
				destination = link_get_space2(game_get_link(game, current_id));
			}
		}

		else if(!strcasecmp(game->option, "east")){
		  current_id = space_get_east(game->spaces[i]);
			if(link_get_status(game_get_link(game, current_id)) == 1){
				destination = link_get_space2(game_get_link(game, current_id));
			}
		}

		else {
		  current_id = space_get_west(game->spaces[i]);
			if(link_get_status(game_get_link(game, current_id)) == 1){
				destination = link_get_space1(game_get_link(game, current_id));
        if(destination==22){
          destination=1;
        }
			}
		}

		if(destination != NO_ID){
			game_set_player_location(game, destination);
			game->control=OK;
		}
		else{
      		game->control=ERROR;
		}

      return;
    }
  }
}

void game_callback_check(Game *game){
  Id space_player;
  Space *space;
  const char *name_object;
  int i;
  Set *conjunto;

  if(game==NULL){
    game->control=ERROR;
    return;
  }

  space_player=player_get_location(game->player);
  space=game_get_space(game,space_player);

  if(strcmp(game->option,space_get_name(space)) == 0){
	  game->control = OK;
	  return;
  }

  conjunto=space_get_objects(space);

  for(i=0;i<(MAXOBJECT) && game->object[i]!=NULL;i++){
    name_object=object_get_name(game->object[i]);
    if(strcmp(game->option,name_object)==0){
		if(set_id(conjunto,object_get_id(game->object[i]))==TRUE){
			game->control = OK;
			return;
		}
    }
  }

  conjunto = inventory_get_ids(player_get_mochila(game->player));
  for(i=0;i<(MAXOBJECT) && game->object[i]!=NULL;i++){
    name_object=object_get_name(game->object[i]);
    if(strcmp(game->option,name_object)==0){
		if(set_id(conjunto,object_get_id(game->object[i]))==TRUE){
			game->control = OK;
			return;
		}
    }
  }
  game->control = ERROR;
  return;
}


STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

STATUS game_add_object(Game* game, Object* object){
  int i = 0;

  if (object == NULL) {
    return ERROR;
  }

  while ( (i < MAXOBJECT) && (game->object[i] != NULL)){
    i++;
  }

  if (i >= MAXOBJECT) {
    return ERROR;
  }

  game->object[i] = object;

  return OK;
}

Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}

Object* game_get_object(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAXOBJECT && game->object[i] != NULL; i++) {
    if (id == object_get_id(game->object[i])){
      return game->object[i];
    }
  }

  return NULL;
}

STATUS game_add_link(Game *game, Link *link){

  int i=0;

  if(game==NULL || link==NULL){
    return ERROR;
  }

  while ( (i < MAXLINK) && (game->link[i] != NULL)){
    i++;
  }

  if (i >= MAXLINK) {
    return ERROR;
  }

  game->link[i] = link;

  return OK;
}

Link* game_get_link(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAXLINK && game->link[i] != NULL; i++) {
    if (id == link_get_id(game->link[i])){
      return game->link[i];
    }
  }

  return NULL;
}

BOOL game_link_open(Game *game, Link *link){

  if(link==NULL || game==NULL){
    return FALSE;
  }

  if(link_get_status(link)==1){
    return TRUE;
  }

  return FALSE;

}

STATUS game_get_option(Game *game, char *cadena){
	if(!game || !cadena) return ERROR;

	if(strcpy(cadena, game->option) == 0) return ERROR;

	return OK;
}

Id game_object_name_to_id(Game *game, char *cadena){
	int i;
	Id id;

	if(!game || !cadena) return NO_ID;

	for(i=0;i<(MAXOBJECT) && game->object[i]!=NULL;i++){
		if (strcmp(cadena, object_get_name(game->object[i])) == 0){
			id = object_get_id(game->object[i]);
			return id;
		}
	}

	return NO_ID;
}
