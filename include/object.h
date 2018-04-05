/**
 * @brief It defines the object interpreter
 *
 * @file object.h
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 08-02-2018
 */

 #ifndef OBJECT_H
 #define OBJECT_H

 #include "../include/types.h"

 #define MAXOBJECT 100

 typedef struct _Object Object;

 /**
* @author Laura Sánchez Herrera
* @brief Crea un objeto
* @param id: Tipo Id
* @return Puntero a object
*/

 Object* object_create(Id id);

 /**
* @author Ana Roa González
* @brief Destruye un objeto
* @param object: Puntero a Object
* @return ERROR o OK
*/

 STATUS object_destroy(Object* object);

 /**
* @author Laura Sánchez Herrera
* @brief Devuelve la identificación del objeto
* @param object: Puntero a Object
* @return Tipo Id
*/

 Id object_get_id(Object* object);

 /**
* @author Ana Roa González
* @brief Modifica la identificacion del objeto
* @param object: Puntero a Object
* @param id: Tipo Id
* @return ERROR o OK
*/

 STATUS object_set_id(Object* object, Id id);

 /**
* @author Laura Sánchez Herrera
* @brief Devuelve el nombre del objeto
* @param object: Puntero a Object
* @return Puntero a const char
*/

 const char* object_get_name(Object* object);

 /**
* @author Ana Roa González
* @brief Modifica el nombre del objeto
* @param object: Puntero a Object
* @param name: Puntero a char
* @return ERROR o OK
*/

 STATUS object_set_name(Object* object, char* name);

 /**
* @author Laura Sánchez Herrera
* @brief Imprime el objeto
* @param object: Puntero a Object
* @return ERROR o OK
*/

 STATUS object_print(Object* object);

 /**
* @author Alba Ramos Pedroviejo
* @brief copia en una cadena el campo description del objeto
* @param object: Puntero a Object
* @return ERROR o OK
*/

STATUS object_get_description(Object *object, char *cadena);

 /**
* @author Alba Ramos Pedroviejo
* @brief copia una cadena en el campo description del objeto
* @param object: Puntero a Object
* @return ERROR o OK
*/

STATUS object_set_description(Object *object, char *cadena);


 #endif
