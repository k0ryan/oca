/**
 * @brief It defines the link interpreter
 *
 * @file link.h
 * @author Alba Ramos Pedroviejo
 * @version 1.0
 * @date 21-03-2018
 */

#ifndef LINK_H
#define LINK_H

#define MAXLINK 100
#include <stdio.h>
#include "../include/types.h"


typedef struct _Link Link;

/**
* @author Alba Ramos Pedroviejo
* @brief Reserva memoria para un nuevo enlace
* @return Puntero a Link
*/

Link * link_create();

/**
* @author Alba Ramos Pedroviejo
* @brief Libera un Puntero a Link
* @param link: Puntero a Link
* @return
*/

void link_destroy(Link *link);

/**
* @author Alba Ramos Pedroviejo
* @brief Establece el id de un enlace
* @param link: Puntero a Link
* @param id: Tipo Id
* @return ERROR o OK
*/

STATUS link_set_id(Link *link, Id id);

/**
* @author Alba Ramos Pedroviejo
* @brief Establece el nombre de un enlace
* @param link: Puntero a Link
* @param name: Puntero a char
* @return ERROR o OK
*/

STATUS link_set_name(Link *link, char *name);

/**
* @author Alba Ramos Pedroviejo
* @brief Establece el id del espacio uno de un enlace
* @param link: Puntero a Link
* @param s1: Tipo a Id
* @return ERROR o OK
*/

STATUS link_set_space1(Link *link, Id s1);

/**
* @author Alba Ramos Pedroviejo
* @brief Establece el id del espacio dos de un enlace
* @param link: Puntero a Link
* @param s2: Tipo Id
* @return ERROR o OK
*/

STATUS link_set_space2(Link *link, Id s2);

/**
* @author Alba Ramos Pedroviejo
* @brief Establece el estado (abierto o cerrado) de un enlace
* @param link: Puntero a Link
* @param status: Tipo entero
* @return ERROR o OK
*/

STATUS link_set_status(Link *link, int status);

/**
* @author Alba Ramos Pedroviejo
* @brief Devuelve el id de un enlace
* @param link: Puntero a Link
* @return Tipo Id
*/

Id link_get_id(Link *link);

/**
* @author Alba Ramos Pedroviejo
* @brief Devuelve el nombre de un enlace
* @param link: Puntero a Link
* @return Tipo Puntero a char
*/

char * link_get_name(Link *link);

/**
* @author Alba Ramos Pedroviejo
* @brief Devuelve el id del espacio uno de un enlace
* @param link: Puntero a Link
* @return Tipo Id
*/

Id link_get_space1(Link *link);

/**
* @author Alba Ramos Pedroviejo
* @brief Devuelve el id del espacio dos de un enlace
* @param link: Puntero a Link
* @return Tipo Id
*/

Id link_get_space2(Link *link);

/**
* @author Alba Ramos Pedroviejo
* @brief Devuelve el estado (abierto o cerrado) de un enlace
* @param link: Puntero a Link
* @return Tipo entero
*/

int link_get_status(Link *link);

/**
* @author Alba Ramos Pedroviejo
* @brief Imprime los atributos de un enlace con fines de depuración
* @param f: Puntero a FILE
* @param link: Puntero a Link
* @return
*/

void link_print(FILE *f, Link *link);

#endif
