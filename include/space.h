/**
 * @brief It defines a space interpreter
 *
 * @file space.h
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 13-01-2018
 */

#ifndef SPACE_H
#define SPACE_H

#include "../include/types.h"
#include "../include/object.h"
#include "../include/set.h"
#include "../include/link.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define MAX_CADENA 21

/**
* @brief Crea el espacio
* @param id: Tipo Id
* @return Puntero a Space
*/

Space* space_create(Id id);

/**
* @brief Destruye el espacio
* @param space: Puntero a Space
* @return ERROR o OK
*/

STATUS space_destroy(Space* space);

/**
* @brief Devuelve la identificacion del espacio
* @param space: Puntero a Space
* @return Tipo Id
*/

Id space_get_id(Space* space);

/**
* @brief Devuelve la identificacion del espacio siguiente
* @param space Puntero a Space
* @return Tipo Id
*/

Id space_get_id_next(Space *space);

/**
* @brief Devuelve la identificacion del espacio anterior
* @param space Puntero a Space
* @return Tipo Id
*/

Id space_get_id_back(Space *space);

/**
* @brief Modifica el nombre del espacio
* @param space: Puntero a Space
* @param name: Puntero a char
* @return ERROR o OK
*/

STATUS space_set_name(Space* space, char* name);

/**
* @brief Devuelve el nombre del espacio
* @param space: Puntero a Space
* @return Puntero a const char
*/

const char* space_get_name(Space* space);

/**
* @author Ana Roa González
* @brief Devuelve el dibujo del espacio
* @param space: Puntero a Space
* @return Puntero a char
*/

char* space_get_cadena(Space *space);

/**
* @brief Modifica el identificador del link del norte
* @param space: Puntero a space
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS space_set_north(Space* space, Id id);

/**
* @brief Devuelve el identificador del link del norte
* @param space: Puntero a space
* @return Tipo Id
*/

Id space_get_north(Space* space);

/**
* @brief Modifica el identificador del link del sur
* @param space: Puntero a space
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS space_set_south(Space* space, Id id);

/**
* @brief Devuelve el identificador del link del sur
* @param space: Puntero a space
* @return Tipo Id
*/

Id space_get_south(Space* space);

/**
* @brief Modifica el identificador del link del este
* @param space: Puntero a space
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS space_set_east(Space* space, Id id);

/**
* @brief Devuelve el identificador del link del este
* @param space: Puntero a space
* @return Tipo Id
*/

Id space_get_east(Space* space);

/**
* @brief Modifica el identificador del link del oeste
* @param space: Puntero a space
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS space_set_west(Space* space, Id id);

/**
* @brief Devuelve el identificador del link del oeste
* @param space: Puntero a space
* @return Tipo Id
*/

Id space_get_west(Space* space);

/**
* @author Laura Sánchez Herrera
* @brief Añade un conjunto de objetos en el espacio
* @param space: Puntero a Space
* @param objects: Puntero a Set
* @return ERROR o OK
*/

STATUS space_set_object(Space* space, Set *objects);

/**
* @author Laura Sánchez Herrera
* @brief Añade un objeto en el espacio
* @param space: Puntero a Space
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS space_add_object(Space* space, Id id);

/**
* @author Laura Sánchez Herrera
* @brief Elimina un objeto en el espacio
* @param space: Puntero a Space
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS space_del_object(Space* space, Id id);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve el conjunto de objetos que hay en el espacio
* @param space: Puntero a Space
* @return Puntero a Set
*/

Set* space_get_objects(Space* space);

/**
* @author Laura Sánchez Herrera
* @brief Verifica si un objeto pertenece al conjunto de objetos del espacio
* @param space: Puntero a Space
* @param id: Tipo Id
* @return FALSE O TRUE
*/

BOOL space_object(Space* space, Id id);

/**
* @brief Imprime el espacio
* @param space: Puntero a Space
* @return ERROR o OK
*/

STATUS space_print(Space* space);

/**
* @author Ana Roa González
* @brief Introduce una cadena en Space
* @param space: Puntero a Space
* @param cadena: Puntero a char
* @param position: Tipo int
* @return ERROR o OK
*/

STATUS space_set_cadena(Space *space, char *cadena);

/**
* @author Alba Ramos Pedroviejo
* @brief Introduce una descripcion en un espacio
* @param space: Puntero a Space
* @param cadena: Puntero a char
* @return ERROR o OK
*/

STATUS space_set_description(Space *space, char *cadena);

/**
* @author Alba Ramos Pedroviejo
* @brief Copia en una cadena la descripcion en un espacio
* @param space: Puntero a Space
* @param cadena: Puntero a char
* @return ERROR o OK
*/

STATUS space_get_description(Space *space, char *cadena);

#endif
