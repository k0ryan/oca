/**
 * @brief It implements the set interpreter
 *
 * @file set.h
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 22-02-2018
 */

#ifndef SET_H
#define SET_H

#define MAXID 1000

#include "../include/types.h"

typedef struct _Set Set;

/**
* @author Laura Sánchez Herrera
* @brief Crea el conjunto
* @return Puntero a Set
*/

Set* set_create();

/**
* @author Laura Sánchez Herrera
* @brief Destruye el conjunto
* @param conjunto: Puntero a Set
* @return ERROR o OK
*/

STATUS set_destroy(Set *conjunto);

/**
* @author Laura Sánchez Herrera
* @brief Añade un identificador en el conjunto
* @param conjunto: Puntero a Set
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS set_add(Set *conjunto, const Id id);

/**
* @author Laura Sánchez Herrera
* @brief Elimina un identificador del conjunto
* @param conjunto: Puntero a Set
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS set_del(Set *conjunto, const Id id);

/**
* @author Laura Sánchez Herrera
* @brief Verifica si un identificador pertenece al conjunto
* @param conjunto: Puntero a Set
* @param id: Tipo Id
* @return FALSE o TRUE
*/

BOOL set_id(Set *conjunto, Id id);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve el identificador que se encuentra en la posicion "position"
*        de la array de identificadores
* @param conjunto: Puntero a Set
* @param position: Tipo int
* @return Tipo Id
*/

Id set_get_id(Set *conjunto, int position);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve el numero de identificadores que tiene el conjunto
* @param conjunto: Puntero a Set
* @return Tipo int
*/

int set_get_top(Set *conjunto);

/**
* @author Ana Roa González
* @brief Indica si el conjunto esta lleno
* @param conjunto: Puntero a Set
* @return TRUE o FALSE
*/

BOOL set_is_full(Set *conjunto);

/**
* @author Laura Sánchez Herrera
* @brief Indica si el conjunto esta vacia
* @param conjunto: Puntero a Set
* @return TRUE o FALSE
*/

BOOL set_is_empty(Set *conjunto);

/**
* @author Laura Sánchez Herrera
* @brief Imprime el conjunto
* @param conjunto: Puntero a Set
* @param f: Puntero a FILE
* @return ERROR o OK
*/

STATUS set_print(FILE *f, const Set *conjunto);

#endif
