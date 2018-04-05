/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Ana Roa González
 * @version 1.0
 * @date 16-02-2018
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "../include/command.h"

#define CMD_LENGHT 30
#define N_CMD 12


char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Following", "Previous","Grasp","Drop", "Roll", "Left","Right", "Move", "Check"};

char *short_cmd_to_str[N_CMD] = {"", "", "e", "f", "p","g","d", "i", "l", "r", "m", "c"};


T_Command command_get_user_input(char *option) {

    T_Command cmd = NO_CMD;
    char input[CMD_LENGHT] = "";
    int i = UNKNOWN - NO_CMD + 1;

    if (scanf("%s", input) > 0) {
        cmd = UNKNOWN;
        while (cmd == UNKNOWN && i < N_CMD) {
            if (!strcasecmp(input, short_cmd_to_str[i]) || !strcasecmp(input, cmd_to_str[i])) {
                cmd = i + NO_CMD;
            } else {
                i++;
            }
        }

        if(!strcasecmp(input,"g") || !strcasecmp(input,"grasp") || !strcasecmp(input,"d") || !strcasecmp(input,"drop")
		   || !strcasecmp(input,"m") || !strcasecmp(input,"move") || !strcasecmp(input,"c") || !strcasecmp(input,"check")){
          scanf("%s", option);
        }
    }
    return cmd;
}
