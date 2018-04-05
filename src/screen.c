/**
 * @brief It implements the screen interface
 *
 * @file screen.c
 * @author Ana Roa González
 * @version 1.0
 * @date 09-02-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/screen.h"

#pragma GCC diagnostic ignored "-Wpedantic"

#define ROWS 24
#define COLUMNS 80
#define TOTAL_DATA (ROWS * COLUMNS) + 1

#define BG_CHAR '~'
#define FG_CHAR ' '
#define PROMPT " prompt:> "

#define ACCESS(d, x, y) (d + ((y) * COLUMNS) + (x))

/**
*
* @struct _Area
* @brief Representa un area
*/

struct _Area{
  int x;  /*!< Coordenada x */
  int y;  /*!< Coordenada y */
  int width;  /*!< Anchura */
  int height;  /*!< Altura */
  char *cursor;   /*!< Cursor */
};

char *__data;

/****************************/
/*     Private functions    */
/****************************/

/**
* @brief Comprueba si el cursor del area esta fuera de los limites de
*        anchura y altura del area
* @param area Puntero a Area
* @return Tipo Entero
*/

int  screen_area_cursor_is_out_of_bounds(Area* area);

/**
* @brief Indica que el area de la pantalla se desplaza hacia arriba
* @param area Puntero a Area
* @return
*/

void screen_area_scroll_up(Area* area);

/**
* @brief Sustituye los caracteres extraños de la cadena recibida
* @param str Puntero a Char
* @return
*/

void screen_utils_replaces_special_chars(char* str);

/****************************/
/* Functions implementation */
/****************************/

void screen_init(){
  screen_destroy();
  __data = (char *) malloc(sizeof(char) * TOTAL_DATA);

  if (__data){
    memset(__data, (int) BG_CHAR, TOTAL_DATA);
    *(__data + TOTAL_DATA - 1) = '\0';
  }
}

void screen_destroy(){
  if (__data)
    free(__data);
}

void screen_paint(){
  char *src = NULL;
  char dest[COLUMNS + 1];
  int i=0;

  memset(dest, 0, COLUMNS + 1);

  if (__data){

    puts("\033[2J");
    for (src=__data; src < (__data + TOTAL_DATA - 1); src+=COLUMNS){
      memcpy(dest, src, COLUMNS);

      for (i=0; i<COLUMNS; i++){
	if (dest[i] == BG_CHAR){
	  printf("\033[0;34;44m%c\033[0m", dest[i]);
	}else{
	  printf("\033[0;30;47m%c\033[0m", dest[i]);
	}
      }
      printf("\n");
    }
  }
}

void screen_gets(char *str){
  fprintf(stdout, PROMPT);
  if (fgets(str, COLUMNS, stdin))
    *(str + strlen(str) - 1) = 0;
}

Area* screen_area_init(int x, int y, int width, int height){
  int i = 0;
  Area* area = NULL;

  if ( (area  = (Area*) malloc (sizeof(struct _Area))) ){
    *area = (struct _Area) {x, y, width, height, ACCESS(__data, x, y)};

    for (i=0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  }

  return area;
}

void screen_area_destroy(Area* area){
  if(area)
    free(area);
}

void screen_area_clear(Area* area){
  int i = 0;

  if (area){
    screen_area_reset_cursor(area);

    for (i=0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  }
}

void screen_area_reset_cursor(Area* area){
  if (area)
    area->cursor = ACCESS(__data, area->x, area->y);
}

void screen_area_puts(Area* area, char *str){
  int len = 0;
  char *ptr = NULL;

  if (screen_area_cursor_is_out_of_bounds(area))
    screen_area_scroll_up(area);

  screen_utils_replaces_special_chars(str);

  for (ptr = str; ptr < (str + strlen(str)); ptr+=area->width){
    memset(area->cursor, FG_CHAR, area->width);
    len = (strlen(ptr) < area->width)? strlen(ptr) : area->width;
    memcpy(area->cursor, ptr, len);
    area->cursor += COLUMNS;
  }
}

int screen_area_cursor_is_out_of_bounds(Area* area){
  return area->cursor > ACCESS(__data,
			       area->x + area->width,
			       area->y + area->height - 1);
}

void screen_area_scroll_up(Area* area){
  for(area->cursor = ACCESS(__data, area->x, area->y);
      area->cursor < ACCESS(__data, area->x + area->width, area->y + area->height - 2);
      area->cursor += COLUMNS){
    memcpy(area->cursor, area->cursor+COLUMNS, area->width);
  }
}

void screen_utils_replaces_special_chars(char* str){
  char *pch = NULL;

  while ((pch = strpbrk (str, "ÁÉÍÓÚÑáéíóúñ")))
    memcpy(pch, "??", 2);
}
