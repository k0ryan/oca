/**
 * @brief It defines the die interpreter
 *
 * @file die.h
 * @author Ana Roa González
 * @version 1.0
 * @date 06-03-2018
 */

#ifndef DIE_H
#define DIE_H

#include "../include/types.h"

typedef struct _Die Die;

/**
* @author Ana Roa González
* @brief Crea un dado
* @return Puntero a Die
*/

Die* die_create();

/**
* @author Ana Roa González
* @brief Destruye un dado
* @param dado: Puntero a Die
* @return ERROR o OK
*/

STATUS die_destroy(Die* dado);

/**
* @author Ana Roa González
* @brief Devuelve el id del dado
* @param dado: Puntero a Die
* @return Tipo Id
*/

Id die_get_id(Die* dado);

/**
* @author Ana Roa González
* @brief Modifica el id del dado
* @param dado: Puntero a Die
* @paaram id:Tipo Id
* @return ERROR o OK
*/

STATUS die_set_id(Die* dado, Id id);

/**
* @author Ana Roa González
* @brief Devuelve el ultimo numero sacado por el dado
* @param dado: Puntero a Die
* @return Tipo entero
*/

int die_get_numero(Die* dado);

/**
* @author Ana Roa González
* @brief Modifica el ultimo sacado por el dado
* @param dado: Puntero a Die
* @param numero: Tipo entero
* @return ERROR o OK
*/

STATUS die_set_numero(Die* dado, int numero);

/**
* @author Ana Roa González
* @brief Genera un numero aleatorio
* @param a: Tipo entero
* @param b: Tipo entero
* @return Tipo entero
*/

int aleatorio(int a, int b);

/**
* @author Ana Roa González
* @brief Tira el dado
* @param dado: Puntero a Die
* @return ERROR o OK
*/

STATUS die_roll(Die* dado);

/**
* @author Ana Roa González
* @brief Imprime el dado
* @param pf: Tipo FILE
* @param dado: Puntero a Die
* @return ERROR o OK
*/

STATUS die_print(FILE* pf ,Die* dado);

#endif
