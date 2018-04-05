/**
 * @brief It implements the graphic engine interface
 *
 * @file graphic_engine.c
 * @author Laura Sánchez Herrera
 * @version 1.0
 * @date 06-02-2018
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/screen.h"
#include "../include/graphic_engine.h"

/**
*
* @struct _Graphic_engine
* @brief Representa un graphic engine
*/

struct _Graphic_engine {
    Area *map;        /*!< Mapa */
    Area *descript;   /*!< Descripcion */
    Area *banner;     /*!< Bandera */
    Area *help;       /*!< Ayuda */
    Area *feedback;   /*!<  Realimentacion*/
};

Graphic_engine *graphic_engine_create() {
    static Graphic_engine *ge = NULL;

    if (ge)
        return ge;

    screen_init();
    ge = (Graphic_engine *) malloc(sizeof (Graphic_engine));

    ge->map = screen_area_init(1, 1, 37, 13);
    ge->descript = screen_area_init(39, 1, 40, 13);
    ge->banner = screen_area_init(28, 15, 23, 1);
    ge->help = screen_area_init(1, 16, 78, 3);
    ge->feedback = screen_area_init(1, 20, 78, 3);

    return ge;
}

void graphic_engine_destroy(Graphic_engine *ge) {
    if (!ge)
        return;

    screen_area_destroy(ge->map);
    screen_area_destroy(ge->descript);
    screen_area_destroy(ge->banner);
    screen_area_destroy(ge->help);
    screen_area_destroy(ge->feedback);

    screen_destroy();
    free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
    Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_link_west = NO_ID, id_link_east = NO_ID,
	id_link_north = NO_ID, id_link_south = NO_ID, id_dest_west = NO_ID, id_dest_east = NO_ID;
    int die_num=NO_ID;
    Space* space_act = NULL;
    char obj[255];
    char paint1[255]=" ";
    char paint2[255]=" ";
    char paint3[255]=" ";
    char str[255];
	char cadena[WORD_SIZE + 1] = "";
	char name[255];
    T_Command last_cmd = UNKNOWN;
    extern char *cmd_to_str[];
    BOOL control_east, control_west;

    screen_area_clear(ge->map);

    if ((id_act = game_get_player_location(game)) != NO_ID) {

        space_act = game_get_space(game, id_act);
        id_back = space_get_id_back(space_act);
        id_next = space_get_id_next(space_act);

        game_screen_space_objects(game,game_get_space(game,id_back),obj);

        if (id_back != NO_ID) {
            id_link_north=space_get_north(space_act);
            sprintf(str, "  |         %2d|", (int) id_back);
            screen_area_puts(ge->map, str);
            sprintf(str, "  | %s |", obj);
            screen_area_puts(ge->map, str);
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
            sprintf(str, "        ^ %ld",id_link_north);
            screen_area_puts(ge->map, str);
        }

        game_screen_space_objects(game,game_get_space(game,id_act),obj);
        id_link_east=space_get_east(game_get_space(game,id_act));
        control_east=game_link_open(game,game_get_link(game,id_link_east));
        id_dest_east=link_get_space2(game_get_link(game,id_link_east));
        id_link_west=space_get_west(game_get_space(game,id_act));
        control_west=game_link_open(game,game_get_link(game,id_link_west));
        id_dest_west=link_get_space2(game_get_link(game,id_link_west));
        if(id_dest_west==16){
          id_dest_west=8;
        }
        game_screen_paints(game,game_get_space(game,id_act),paint1,1);
        game_screen_paints(game,game_get_space(game,id_act),paint2,2);
        game_screen_paints(game,game_get_space(game,id_act),paint3,3);

        if (id_act != NO_ID && control_east != TRUE && control_west != TRUE) {
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
            sprintf(str, "  |>8D      %2d|", (int) id_act);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |",paint1);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |",paint2);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |",paint3);
            screen_area_puts(ge->map, str);
            sprintf(str, "  | %s |", obj);
            screen_area_puts(ge->map, str);
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
        }

        if (id_act != NO_ID && control_east == TRUE && control_west != TRUE) {
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
            sprintf(str, "  |>8D      %2d|%ld", (int) id_act,id_link_east);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |-->%ld",paint1,id_dest_east);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |",paint2);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |",paint3);
            screen_area_puts(ge->map, str);
            sprintf(str, "  | %s |", obj);
            screen_area_puts(ge->map, str);
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
        }

        if (id_act != NO_ID && control_east != TRUE && control_west == TRUE) {
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
            sprintf(str, "  |>8D      %2d|", (int) id_act);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |",paint1);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |",paint2);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |%ld",paint3,id_link_west);
            screen_area_puts(ge->map, str);
            sprintf(str, "  | %s |<--%ld", obj,id_dest_west);
            screen_area_puts(ge->map, str);
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
        }

        if (id_act != NO_ID && control_east == TRUE && control_west == TRUE) {
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
            sprintf(str, "  |>8D      %2d|%ld", (int) id_act,id_link_east);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |-->%ld",paint1,id_dest_east);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |",paint2);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |  %s  |%ld",paint3,id_link_west);
            screen_area_puts(ge->map, str);
            sprintf(str, "  | %s |<--%ld", obj,id_dest_west);
            screen_area_puts(ge->map, str);
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
        }


        game_screen_space_objects(game,game_get_space(game,id_next),obj);

        if (id_next != NO_ID) {
            id_link_south=space_get_south(space_act);
            sprintf(str, "        v %ld",id_link_south);
            screen_area_puts(ge->map, str);
            sprintf(str, "  +-----------+");
            screen_area_puts(ge->map, str);
            sprintf(str, "  |         %2d|", (int) id_next);
            screen_area_puts(ge->map, str);
            sprintf(str, "  | %s |", obj);
            screen_area_puts(ge->map, str);
        }
    }

    screen_area_clear(ge->descript);
    if (game_screen_object(game,obj) != ERROR) {
        sprintf(str, "  Object location:");
        screen_area_puts(ge->descript, str);
        sprintf(str, "  %s",obj);
        screen_area_puts(ge->descript, str);
        sprintf(str, " ");
        screen_area_puts(ge->descript, str);
    }

    if (game_screen_player_objects(game,obj) != ERROR) {
        sprintf(str, "  Player objects: %s",obj);
        screen_area_puts(ge->descript, str);
        sprintf(str, " ");
        screen_area_puts(ge->descript, str);
    }else{
      sprintf(str, "  Player objects: ");
      screen_area_puts(ge->descript, str);
      sprintf(str, " ");
      screen_area_puts(ge->descript, str);
    }



    if ((die_num = game_get_die_roll(game)) != -1) {
      sprintf(str, "  Last Roll die:%d",die_num);
      screen_area_puts(ge->descript, str);
      sprintf(str, " ");
      screen_area_puts(ge->descript, str);
    }else{
      sprintf(str, "  Last Roll die:");
      screen_area_puts(ge->descript, str);
      sprintf(str, " ");
      screen_area_puts(ge->descript, str);
    }

	if (game_get_last_command(game) == CHECK){
		game_get_option(game, name);

		if (strcmp(name, space_get_name(space_act)) != 0){
			if(strcmp("OK", game_get_control(game)) == 0){
				object_get_description(game_get_object(game, game_object_name_to_id(game, name)), cadena);
        sprintf(str, "  Object description:");
        screen_area_puts(ge->descript, str);
        sprintf(str, "  %s",cadena);
        screen_area_puts(ge->descript, str);
        sprintf(str, " ");
        screen_area_puts(ge->descript, str);
			}
			else{
				sprintf(str, "  Object description:");
				screen_area_puts(ge->descript, str);
				sprintf(str, " ");
				screen_area_puts(ge->descript, str);
			}
		}

		else {
			if(strcmp("OK", game_get_control(game)) == 0){
				space_get_description(game_get_space(game, id_act), cadena);
        sprintf(str, "  Space description:");
        screen_area_puts(ge->descript, str);
        sprintf(str, "  %s",cadena);
        screen_area_puts(ge->descript, str);
        sprintf(str, " ");
        screen_area_puts(ge->descript, str);
			}
			else{
				sprintf(str, "  Space description:");
				screen_area_puts(ge->descript, str);
				sprintf(str, " ");
				screen_area_puts(ge->descript, str);
			}

		}

	}

    screen_area_puts(ge->banner, " The game of the Goose ");
    screen_area_clear(ge->help);

    sprintf(str, " The commands you can use are:");
    screen_area_puts(ge->help, str);
    sprintf(str, " following(f), previous(p), grasp(g)+<name>, drop(d)+<name>, roll(i), exit(e),");
    screen_area_puts(ge->help, str);
    sprintf(str, " left(l), right(r), check(c)+<name or space(s)>, move(m)+<direction>");
    screen_area_puts(ge->help, str);

    last_cmd = game_get_last_command(game);
    if(strcmp(cmd_to_str[last_cmd - NO_CMD],"No command")==0){
      sprintf(str, " %s", cmd_to_str[last_cmd - NO_CMD]);
      screen_area_puts(ge->feedback, str);
    }else{
      sprintf(str, " %s: %s", cmd_to_str[last_cmd - NO_CMD], game_get_control(game));
      screen_area_puts(ge->feedback, str);
    }

    screen_paint();
    printf("prompt:> ");
}
