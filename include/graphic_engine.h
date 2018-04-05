/**
 * @brief It defines a textual graphic engine interpreter
 *
 * @file graphic_engine.h
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 18-01-2018
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "../include/game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
* @brief Reserva memoria para la estructura Graphic_engine y define
*        el area que va a ocupar la impresion
* @return Puntero a Graphic_engine
*/

Graphic_engine* graphic_engine_create();

/**
* @brief Destruye la impresion del juego
* @param ge: Puntero a Graphic_engine
* @return
*/

void graphic_engine_destroy(Graphic_engine *ge);

/**
* @author Laura Sánchez Herrera
* @brief Imprime el juego
* @param ge: Puntero a Graphic_engine
* @param game: Puntero a Game
* @return
*/

void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
* @author Laura Sánchez Herrera
* @brief Imprime los comandos
* @param ge: Puntero a Graphic_engine
* @param str Puntero a char
* @return
*/


void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
