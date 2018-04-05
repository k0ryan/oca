/**
 * @brief It defines common types interpreter
 *
 * @file types.h
 * @author Ana Roa González
 * @version 1.0
 * @date 13-01-2018
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1

/**
* @brief Definicicion de tipo Id
*/

typedef long Id;

/**
* @brief Lista del Tipo Booleano
*/

typedef enum {
  FALSE,    /*!< Falso */
  TRUE      /*!< Verdadero */
} BOOL;

/**
* @brief Lista del Tipo Status
*/

typedef enum {
  ERROR,    /*!< Error */
  OK        /*!< Correcto */
} STATUS;

/**
* @brief Lista de direcciones
*/

typedef enum {
  N,        /*!< Norte */
  S,        /*!< Sur */
  E,        /*!< Este */
  W         /*!< Oeste */
} DIRECTION;

#endif
