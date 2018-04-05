/**
 * @brief It defines the game loop interface
 *
 * @file game_loop.c
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 13-01-2018
 * 
 * fichero principal
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/graphic_engine.h"
#include "../include/gamereader.h"
#include "../include/game.h"

int main(int argc, char *argv[]) {
    Game *game = NULL;
    T_Command command = NO_CMD;
    T_Command last_cmd = UNKNOWN;
    extern char *cmd_to_str[];
    Graphic_engine *gengine;
    char option[WORD_SIZE + 1];
    char control[WORD_SIZE + 1];
    FILE *f= NULL;
    FILE *pf= NULL;

    option[0]='\0';

    game = game_create();
    if(!game) return 1;
	
	srand(time(NULL));

    if (argc < 4) {
        fprintf(stderr, "Use: %s <game_data_file> -l <game_log_file>\n", argv[0]);
        return 1;
    }
    if (game_create_from_file(game, argv[1]) == ERROR) {
        fprintf(stderr, "Error while initializing game.\n");
        return 1;
    }
    if(strcmp(argv[2],"-l")!=0){
      fprintf(stderr, "Use: %s <game_data_file> -l <game_log_file>\n", argv[0]);
      return 1;
    }
    if ((gengine = graphic_engine_create()) == NULL) {
        fprintf(stderr, "Error while initializing graphic engine.\n");
        game_destroy(game);
        return 1;
    }

    f = fopen(argv[3],"w");
    pf = fopen("../fichero_cmd.log","w");

    while ((command != EXIT) && !game_is_over(game)) {
        graphic_engine_paint_game(gengine, game);
        command = command_get_user_input(option);
        game_update(game, command,option);
        last_cmd = game_get_last_command(game);
        strcpy(control,game_get_control(game));
        if((strcmp(cmd_to_str[last_cmd - NO_CMD],"No command")!=0)){
          fprintf(f, "%s: %s\n", cmd_to_str[last_cmd - NO_CMD], control);
          if(strcmp(cmd_to_str[last_cmd - NO_CMD],"Move")==0 || strcmp(cmd_to_str[last_cmd - NO_CMD],"Grasp")==0
            ||strcmp(cmd_to_str[last_cmd - NO_CMD],"Drop")==0 || strcmp(cmd_to_str[last_cmd - NO_CMD],"Check")==0){
              fprintf(pf, "%s %s\n", cmd_to_str[last_cmd - NO_CMD], option);
          }else{
            fprintf(pf, "%s\n", cmd_to_str[last_cmd - NO_CMD]);
          }
        }
    }

    game_destroy(game);
    graphic_engine_destroy(gengine);
    fclose(f);
    fclose(pf);
    return 0;
}
