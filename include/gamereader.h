/**
 * @brief It defines the game reader interpreter
 *
 * @file gamereader.h
 * @author Ana Roa González
 * @version 1.0
 * @date 06-02-2018
 */

 #ifndef GAMEREADER_H
 #define GAMEREADER_H

 #include "../include/game.h"

 /**
 * @author Ana Roa González
 * @brief Carga los espacios del juego
 * @param game: Puntero a Game
 * @param filename: Puntero a char
 * @return ERROR o Ok
 */

 STATUS game_load_spaces(Game* game, char* filename);

 /**
 * @brief Carga los objetos del juego
 * @param game: Puntero a Game
 * @param filename: Puntero a char
 * @return ERROR o OK
 */

 STATUS game_load_objects(Game* game, char* filename);

 /**
 * @author Alba Ramos Pedroviejo
 * @brief Carga los links del juego
 * @param game: Puntero a Game
 * @param filename: Puntero a char
 * @return ERROR o OK
 */

 STATUS game_load_links(Game* game, char* filename);

 /**
* @brief Crea un juego desde un fichero
* @param game: Puntero a Game
* @param filename: Puntero a char
* @return ERROR o OK
*/

 STATUS game_create_from_file(Game* game, char* filename);

#endif
