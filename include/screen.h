/**
 * @brief It defines a screen interpreter
 *
 * @file screen.h
 * @author Ana Roa González
 * @version 1.0
 * @date 11-01-2018
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80

typedef struct _Area Area;

/**
* @brief Crea el fondo de la pantalla de juego
* @param
* @return
*/

void  screen_init();

/**
* @brief Libera la memoria reservada para el fondo de pantalla
* @param
* @return
*/

void  screen_destroy();

/**
* @brief Colorea el background y el foreground
* @param
* @return
*/

void  screen_paint();

/**
* @brief Muestra el mensaje 'promt' por pantalla y lee el comando
*       introducido por el usuario
* @param str: Puntero a Char
* @return
*/

void  screen_gets(char *str);

/**
* @brief Reserva memoria para la estrucutura Area e inicializa sus parametros
* @param x: Tipo Entero
* @param y: Tipo Entero
* @param width: Tipo Entero
* @param height: Tipo Entero
* @return Puntero a Area
*/

Area* screen_area_init(int x, int y, int width, int height);

/**
* @brief Libera la memoria reservada para el Area
* @param area: Puntero a Area
* @return
*/

void  screen_area_destroy(Area* area);

/**
* @brief Devuelve el puntero a Area que recibe a su estado inicial
* @param area: Puntero a Area
* @return
*/

void  screen_area_clear(Area* area);

/**
* @brief Resetea el cursor del puntero a Area que recibe, poniendole en su estado inicial
* @param area: Puntero a Area
* @return
*/

void  screen_area_reset_cursor(Area* area);

/**
* @brief Imprime el area del juego por pantalla
* @param area: Puntero a Area
* @param str: Puntero a Char
* @return
*/

void  screen_area_puts(Area* area, char *str);

#endif
