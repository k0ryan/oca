/**
 * @brief It implements the command interpreter
 *
 * @file command.h
 * @author Ana Roa González
 * @version 1.0
 * @date 16-02-2018
 */

#ifndef COMMAND_H
#define COMMAND_H

/**
* @brief Lista de comandos
*/

typedef enum enum_Command {
  NO_CMD = -1,    /*!< No hay comando */
  UNKNOWN,        /*!< Comando desconocido */
  EXIT,           /*!< Salida */
  FOLLOWING,      /*!< Siguiente casilla */
  PREVIOUS,       /*!< Casilla anterior */
  GRASP_OBJECT,   /*!< Coger objeto */
  DROP_OBJECT,    /*!< Dejar objeto */
  ROLL_DIE,       /*!< Tirar el dado */
  LEFT,           /*!< Casilla a la izquierda */
  RIGHT,          /*!< Casilla a la derecha */
  MOVE,           /*!< Movimiento hacia los puntos cardinales */
  CHECK           /*!< Examinar objetos */
} T_Command;

/**
* @brief Devuelve el comando introducido por teclado
* @param option: Puntero a char
* @return Tipo T_Command
*/

T_Command command_get_user_input(char *option);

#endif
