/**
 * @brief It implements the game reader interface
 *
 * @file gamereader.c
 * @author Ana Roa González
 * @version 1.0
 * @date 06-02-2018
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include "../include/gamereader.h"
 #include "../include/game.h"
 #include "../include/object.h"


 STATUS game_load_objects(Game* game, char* filename){

   FILE* file = NULL;
   char line[WORD_SIZE] = "";
   char name[WORD_SIZE] = "";
   char description[WORD_SIZE]="";
   char* toks = NULL;
   Id id = NO_ID;
   Id id_espacio;
   Object* object = NULL;
   STATUS status = OK;

   if (!filename) {
     return ERROR;
   }

   file = fopen(filename, "r");
   if (file == NULL) {
     return ERROR;
   }

   while (fgets(line, WORD_SIZE, file)) {
     line[strlen(line)-1]='\0';
     if (strncmp("#o:", line, 3) == 0) {
       toks = strtok(line + 3, "|");
       id = atol(toks);
       toks = strtok(NULL, "|");
       id_espacio = atol(toks);
       toks = strtok(NULL, "|");
       strcpy(name, toks);
       toks = strtok(NULL, "|");
       strcpy(description, toks);

 #ifdef DEBUG
       printf("Leido: %ld|%ld|%s|%s\n", id, id_espacio, name, description);
 #endif

       object = object_create(id);
       if(object==NULL){
         return ERROR;
       }
       object_set_name(object, name);
	     object_set_description(object, description);
       game_add_object(game, object);
       space_add_object(game_get_space(game,id_espacio), id);
     }
   }

   if (ferror(file)) {
     status = ERROR;
   }

   fclose(file);

   return status;
 }


 STATUS game_load_spaces(Game* game, char* filename) {


   FILE* file = NULL;
   char line[WORD_SIZE] = "";
   char name[WORD_SIZE] = "";
   char description[WORD_SIZE] = "";
   char* toks = NULL;
   Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
   Space* space = NULL;
   STATUS status = OK;
   char cadena0[WORD_SIZE] = "";
   char cadena1[WORD_SIZE] = "";
   char cadena2[WORD_SIZE] = "";

   if (!filename) {
     return ERROR;
   }

   file = fopen(filename, "r");
   if (file == NULL) {
     return ERROR;
   }

   while (fgets(line, WORD_SIZE, file)) {
     if (strncmp("#s:", line, 3) == 0) {
       toks = strtok(line + 3, "|");
       id = atol(toks);
       toks = strtok(NULL, "|");
       strcpy(name, toks);
       toks = strtok(NULL, "|");
       north = atol(toks);
       toks = strtok(NULL, "|");
       east = atol(toks);
       toks = strtok(NULL, "|");
       south = atol(toks);
       toks = strtok(NULL, "|");
       west = atol(toks);
       toks = strtok(NULL, "|");
       strcpy(cadena0, toks);
       toks = strtok(NULL, "|");
       strcpy(cadena1, toks);
       toks = strtok(NULL, "|");
       strcpy(cadena2, toks);
       toks = strtok(NULL, "|");
       strcpy(description, toks);

 #ifdef DEBUG
       printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s|%s|%s|%s\n", id, name, north, east, south, west, cadena0, cadena1, cadena2, description);
 #endif


       space = space_create(id);

       if (space != NULL) {
			space_set_name(space, name);
			space_set_north(space, north);
			space_set_east(space, east);
			space_set_south(space, south);
			space_set_west(space, west);
			space_set_cadena(space,cadena0);
			space_set_cadena(space,cadena1);
			space_set_cadena(space,cadena2);
			space_set_description(space, description);
			game_add_space(game, space);
       }
     }
   }

   if (ferror(file)) {
     status = ERROR;
   }

   fclose(file);

   return status;
 }

 STATUS game_load_links(Game* game, char* filename) {


   FILE* file = NULL;
   char line[WORD_SIZE] = "";
   char name[WORD_SIZE] = "";
   char* toks = NULL;
   Id id = NO_ID, space1 = NO_ID, space2 = NO_ID;
   Link* link = NULL;
   STATUS status = OK;
   int apertura;

   if (!filename) {
     return ERROR;
   }

   file = fopen(filename, "r");
   if (file == NULL) {
     return ERROR;
   }

   while (fgets(line, WORD_SIZE, file)) {
     if (strncmp("#l:", line, 3) == 0) {
       toks = strtok(line + 3, "|");
       id = atol(toks);
       toks = strtok(NULL, "|");
       strcpy(name, toks);
       toks = strtok(NULL, "|");
       space1 = atol(toks);
       toks = strtok(NULL, "|");
       space2 = atol(toks);
       toks = strtok(NULL, "|");
       apertura = atoi(toks);

 #ifdef DEBUG
       printf("Leido: %ld|%s|%ld|%ld|%d|\n", id, name, space1, space2, apertura);
 #endif

       link = link_create();
       if (link != NULL) {
          link_set_id(link,id);
          link_set_name(link, name);
          link_set_space1(link, space1);
 	        link_set_space2(link, space2);
 	        link_set_status(link, apertura);
 	        game_add_link(game, link);
       }
     }
   }

   if (ferror(file)) {
     status = ERROR;
   }

   fclose(file);

   return status;
 }

 STATUS game_create_from_file(Game* game, char* filename) {

   if (game == NULL || filename == NULL)
     return ERROR;


   if (game_load_spaces(game, filename) == ERROR)
     return ERROR;
   game_set_player_location(game, game_get_space_id_at(game, 0));
   game_load_objects(game,filename);
   game_load_links(game,filename);

   return OK;
 }
