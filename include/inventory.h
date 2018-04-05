/**
 * @brief It defines the inventory interpreter
 *
 * @file inventory.h
 * @author Alba Ramos, Laura Sánchez, Andrea Salcedo y Ana Roa
 * @version 1.0
 * @date 15-03-2018
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "../include/types.h"
#include "../include/set.h"

typedef struct _Inventory Inventory;

/**
* @author Alba Ramos Pedroviejo
* @brief Crea un inventory
* @return Puntero a Inventory
*/

Inventory * inventory_create();

/**
* @author Laura Sánchez Herrera
* @brief Destruye un inventory
* @param inv: Puntero a Inventory
* @return ERROR o OK
*/

STATUS inventory_destroy(Inventory *inv);

/**
* @author Ana Roa González
* @brief Comprueba que el inventory esta lleno
* @param inv: Puntero a Inventory
* @return TRUE o FALSE
*/

BOOL inventory_is_full(Inventory *inv);

/**
* @author Andrea Salcedo López
* @brief Comprueba si el inventory esta vacio
* @param inv: Puntero a Inventory
* @return TRUE o FALSE
*/

BOOL inventory_is_empty(Inventory *inv);

/**
* @author Alba Ramos Pedroviejo
* @brief Modifica el conjunto de ids
* @param inv: Puntero a Inventory
* @param ids: Puntero a Set
* @return ERROR o OK
*/

STATUS inventory_set_ids(Inventory *inv, Set *ids);

/**
* @author Laura Sánchez Herrera
* @brief Devuelve el conjunto de ids
* @param inv: Puntero a Inventory
* @return Punterp a Set
*/

Set * inventory_get_ids(Inventory *inv);

/**
* @author Ana Roa González
* @brief Modifica el numero maximo de ids del inventory
* @param inv: Puntero a Inventory
* @param max: Tipo entero
* @return ERROR o OK
*/

STATUS inventory_set_max(Inventory *inv, int max);

/**
* @author Andrea Salcedo López
* @brief Devuelve el numero maximo de ids del inventory
* @param inv: Puntero a Inventory
* @return Tipo entero
*/

int inventory_get_max(Inventory *inv);

/**
* @author Alba Ramos Pedroviejo
* @brief Añade un id al conjunto de inventory
* @param inv: Puntero a Inventory
* @param id: Puntero Id
* @return ERROR o OK
*/

STATUS inventory_add_id(Inventory *inv, Id id);

/**
* @author Laura Sánchez Herrera
* @brief Elimina un id al conjunto de inventory
* @param inv: Puntero a Inventory
* @param id: Puntero Id
* @return ERROR o OK
*/

STATUS inventory_del_id(Inventory *inv, Id id);

/**
* @author Andrea Salcedo López
* @brief Comprueba si un id se encuentra en el inventory
* @param inv: Puntero a Inventory
* @param id: Puntero Id
* @return TRUE o FALSE
*/

BOOL inventory_contains(Inventory *inv, Id id);

/**
* @author Alba Ramos Pedroviejo
* @brief Imprime el inventory
* @param f: Puntero a FILE
* @param inv: Puntero a Inventory
* @return Tipo entero
*/

int inventory_print(FILE *f, Inventory *inv);

 #endif
