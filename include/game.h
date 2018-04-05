/**
 * @brief It defines the game interpreter
 * for each command
 *
 * @file game.h
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 30-03-2018
 */

#ifndef GAME_H
#define GAME_H

#include "../include/command.h"
#include "../include/space.h"
#include "../include/object.h"
#include "../include/player.h"
#include "../include/die.h"
#include "../include/set.h"
#include "../include/inventory.h"
#include "../include/link.h"

typedef struct _Game Game;

/**
* @brief Crea un juego
* @return puntero a Game
*/

Game * game_create();

/**
* @brief Introduce el ultimo comando en la estructura game y llama a la funcion
*        callback correspondiiente
* @param game: Puntero a Game
* @param cmd: Tipo T_Command
* @param option: Puntero a char
* @return ERROR o OK
*/

STATUS game_update(Game* game, T_Command cmd, char *option);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve el identificador del espacio que se encuentra en la posicion "position"
*        de la array de espacios
* @param game: Puntero a Game
* @param position: Tipo int
* @return Tipo Id
*/

Id     game_get_space_id_at(Game* game, int position);

/**
* @author Ana Roa González
* @brief Modifica la localización del jugador
* @param game: Puntero a Game
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS game_set_player_location(Game* game, Id id);

/**
* @author Laura Sánchez Herrera
* @brief Modifica la localización del objeto
* @param game: Puntero a Game
* @param id: Tipo Id
* @param object: Tipo Id
* @return ERROR o OK
*/

STATUS game_set_object_location(Game* game, Id id, Id object);

/**
* @brief Destruye el juego
* @param game: Puntero a Game
* @return ERROR o OK
*/

STATUS game_destroy(Game* game);

/**
* @brief El juego acaba
* @param game: Puntero a Game
* @return TRUE o FALSE
*/

BOOL   game_is_over(Game* game);

/**
* @brief Pinta la pantalla del juego
* @param game: Puntero a Game
* @return
*/

void   game_print_screen(Game* game);

/**
* @brief Imprime la informacion del espacio el objeto y el jugador
* @param game: Puntero a Game
* @return
*/

void   game_print_data(Game* game);

/**
* @author Laura Sánchez Herrera
* @brief Imprime los objetos junto con su localizacion en el espacio
* @param game: Puntero a Game
* @param cadena: Puntero a char
* @return ERROR o OK
*/

STATUS game_screen_object(Game *game, char *cadena);

/**
* @author Ana Roa González
* @brief Imprime los dibujos en las casillas
* @param game: Puntero a Game
* @param cadena: Puntero a char
* @param space: Puntero a Space
* @param position: Tipo int
* @return ERROR o OK
*/

STATUS game_screen_paints(Game *game, Space *space, char *cadena, int option);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve el espacio identificado con el id que se pasa como argumento
* @param game: Puntero a Game
* @param id: Tipo Id
* @return Puntero a Space
*/

Space* game_get_space(Game* game, Id id);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve el objeto identificado con el id que se pasa como argumento
* @param game: Puntero a Game
* @param id: Tipo Id
* @return Puntero a Object
*/

Object* game_get_object(Game* game, Id id);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve la localizacion del jugador
* @param game: Puntero a Game
* @return Tipo Id
*/

Id     game_get_player_location(Game* game);

/**
* @author Ana Roa González
* @brief Devulve la localizacion del objeto
* @param game: Puntero a Game
* @param object: Tipo Id
* @return Tipo Id
*/

Id game_get_object_location(Game* game, Id object);

/**
* @author Laura Sánchez Herrera
* @brief Imprime los objetos que hay en el espacio
* @param game: Puntero a Game
* @param space: Puntero a Space
* @param cadena: Puntero a char
* @return ERROR o OK
*/

STATUS game_screen_space_objects(Game *game, Space *space, char *cadena);

/**
* @author Laura Sánchez Herrera
* @brief Imprime el objeto que tiene el jugador
* @param game: Puntero a Game
* @param cadena: Puntero a char
* @return ERROR o OK
*/

STATUS game_screen_player_objects(Game *game, char *cadena);

/**
* @brief Devuelve el ultimo comando introducido
* @param game: Puntero a Game
* @return Tipo T_command
*/

T_Command game_get_last_command(Game* game);

/**
* @author Ana Roa González
* @brief Añade un espacio en el juego
* @param game: Puntero a Game
* @param space: Puntero a Space
* @return ERROR o OK
*/

STATUS game_add_space(Game* game, Space* space);

/**
* @author Laura Sánchez Herrera
* @brief Añade un objeto en el juego
* @param game: Puntero a Game
* @param object: Puntero a Object
* @return ERROR o OK
*/

STATUS game_add_object(Game* game, Object* object);

/**
* @author Ana Roa González
* @brief Devuelve el ultimo numero que saca el dado
* @param game: Puntero a Game
* @return Tipo int
*/

int game_get_die_roll(Game* game);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve si un comando se ha ejecutado bien o no
* @param game: Puntero a Game
* @return Tipo STATUS
*/

char* game_get_control(Game *game);

/**
* @author Laura Sánchez Herrera
* @brief Añade un link en el juego
* @param game: Puntero a Game
* @param object: Puntero a Link
* @return ERROR o OK
*/

STATUS game_add_link(Game *game, Link *link);

/**
* @author Alba Ramos Pedroviejo
* @brief Devuelve la opcion que recibe game de un comando
* @param game: Puntero a Game
* @return Tipo STATUS
*/

STATUS game_get_option(Game *game, char *cadena);

/**
* @author Alba Ramos Pedroviejo
* @brief Permite obtener el id de un objeto del juego a partir de su nombre
* @param game: Puntero a Game
* @param cadena: Puntero a char
* @return Tipo Id
*/

Id game_object_name_to_id(Game *game, char *cadena);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve el Link correspondiente al id que se proporciona
* @param game: Puntero a Game
* @param id: Tipo Id
* @return Puntero a Link
*/

Link* game_get_link(Game* game, Id id);

/**
* @author Laura Sánchez Herrera
* @brief Conoce el estado de un Link, abierto o cerrado
* @param game: Puntero a Game
* @param link: Puntero a Link
* @return TRUE o FALSE
*/

BOOL game_link_open(Game *game, Link *link);

#endif
