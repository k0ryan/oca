/**
 * @brief It defines the player interpreter
 *
 * @file player.h
 * @author Ana Roa González
 * @version 1.0
 * @date 09-02-2018
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "../include/types.h"
#include "../include/inventory.h"

typedef struct _Player Player;

/**
* @author Ana Roa González
* @brief Crea un jugador
* @param id: Tipo Id
* @return Puntero a Player
*/

Player* player_create(Id id);

/**
* @author Laura Sánchez Herrera
* @brief Destruye un jugador
* @param player: Puntero a Player
* @return ERROR o OK
*/

STATUS player_destroy(Player *player);

/**
* @author Ana Roa González
* @brief Devuelve la identificacion del jugador
* @param player: Puntero a Player
* @return Tipo de Id
*/

Id player_get_id(Player *player);

/**
* @author Laura Sánchez Herrera
* @brief Modifica la identificacion del jugador
* @param player: Puntero a Player
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS player_set_id(Player *player, Id id);

/**
* @author Ana Roa González
* @brief Devuelve el nombre del jugador
* @param player: Puntero a Player
* @return Puntero a const char
*/

const char* player_get_name(Player *player);

/**
* @author Laura Sánchez Herrera
* @brief Modifica el nombre del jugador
* @param player: Puntero a Player
* @param name: Puntero a char
* @return ERROR o OK
*/

STATUS player_set_name(Player *player, char *name);

/**
* @author Ana Roa González
* @brief Devuelve la localizacion del jugador
* @param player: Puntero a Player
* @return Tipo Id
*/

Id player_get_location(Player *player);

/**
* @author Laura Sánchez Herrera
* @brief Modifica la localizacion del jugador
* @param player: Puntero a Player
* @param location: Tipo Id
* @return ERROR o OK
*/

STATUS player_set_location(Player *player, Id location);

/**
* @author Ana Roa González
* @brief Devuelve el conjunto de objetos que lleva el jugador
* @param player: Puntero a Player
* @return Puntero a Inventory
*/

Inventory * player_get_mochila(Player *player);

/**
* @author Laura Sánchez Herrera
* @brief Modifica el conjunto de objetos que lleva el jugador
* @param player: Puntero a Player
* @param mochila: Puntero a Inventory
* @return ERROR o OK
*/

STATUS player_set_mochila(Player *player, Inventory *mochila);

/**
* @author Laura Sánchez Herrera
* @brief Agrega a la mochila el objeto correspondiente al Id recibido
* @param player: Puntero a Player
* @param object: Id del objeto a agregar
* @return ERROR o OK
*/

STATUS player_add_object(Player *player, Id object);

/**
* @author Laura Sánchez Herrera
* @brief Elimina de la mochila el objeto correspondiente al Id recibido
* @param player: Puntero a Player
* @param object: Id del objeto a eliminar
* @return ERROR o OK
*/

STATUS player_del_object (Player *player, Id object);

/**
* @author Laura Sánchez Herrera
* @brief Comprueba si el jugador lleva encima el objeto correspondiente al Id recibido
* @param player: Puntero a Player
* @param id: Id del objeto a buscar en la mochila
* @return TRUE o FALSE
*/

BOOL player_contains(Player *player, Id id);

/**
* @author Ana Roa González
* @brief Imprime el jugador
* @param player: Puntero a Player
* @return ERROR o OK
*/

STATUS player_print(Player* player);

 #endif
