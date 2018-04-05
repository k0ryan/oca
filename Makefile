#   Proyecto de Programacion
# 	Escuela Politecnica Superior - UAM
# 	Fecha: Marzo de 2018
#	Autoras: Alba Ramos, Andrea Salcedo, Ana Roa y Laura Sánchez

#=============================================================
# Entorno de desarrollo y opciones
#=============================================================
# Compilador

CC = gcc

# Opciones de compilacion

CFLAGS= -Wall -pedantic -ansi -g

# Opciones de enlazado
# Indican el directorio donde localizar cada fichero

SRCPATH = ./src/
INCPATH = ./include/
OBJPATH = ./obj/
DOCPATH = ./doc/


#=============================================================
# Archivos que componen el proyecto
#=============================================================
# Ejecutables
EJECUTABLES = juego set_test die_test link_test object_test player_test inventory_test space_test screen_test graphicengine_test command_test gamereader_test game_test

# Objetos
OBJECTSJUEGO = command.o game.o game_loop.o graphic_engine.o screen.o space.o gamereader.o object.o player.o set.o die.o inventory.o link.o


#=============================================================
# Generación de ejecutables
#=============================================================

all: $(EJECUTABLES) 

juego: command.o object.o set.o die.o inventory.o link.o space.o player.o screen.o game.o gamereader.o graphic_engine.o game_loop.o 
	$(CC) $(CFLAGS) -o juego $(OBJPATH)command.o $(OBJPATH)object.o $(OBJPATH)set.o $(OBJPATH)die.o $(OBJPATH)inventory.o $(OBJPATH)link.o $(OBJPATH)player.o $(OBJPATH)space.o $(OBJPATH)screen.o $(OBJPATH)game.o $(OBJPATH)graphic_engine.o $(OBJPATH)gamereader.o $(OBJPATH)game_loop.o 

set_test: set.o set_test.o
	$(CC) $(CFLAGS) -o set_test $(OBJPATH)set_test.o $(OBJPATH)set.o

die_test: die.o die_test.o
	$(CC) $(CFLAGS) -o die_test $(OBJPATH)die_test.o $(OBJPATH)die.o

link_test: link.o link_test.o
	$(CC) $(CFLAGS) -o link_test $(OBJPATH)link_test.o $(OBJPATH)link.o

object_test: object_test.o object.o
	$(CC) $(CFLAGS) -o object_test $(OBJPATH)object_test.o $(OBJPATH)object.o

player_test: player_test.o player.o set.o inventory.o
	$(CC) $(CFLAGS) -o player_test $(OBJPATH)player_test.o $(OBJPATH)player.o $(OBJPATH)set.o $(OBJPATH)inventory.o

inventory_test: inventory_test.o inventory.o set.o
	$(CC) $(CFLAGS) -o inventory_test $(OBJPATH)inventory_test.o $(OBJPATH)inventory.o $(OBJPATH)set.o

space_test: space.o space_test.o set.o
	$(CC) $(CFLAGS) -o space_test $(OBJPATH)space.o $(OBJPATH)space_test.o $(OBJPATH)set.o

screen_test: screen.o screen_test.o
	$(CC) $(CFLAGS) -o screen_test $(OBJPATH)screen.o $(OBJPATH)screen_test.o

graphicengine_test: screen.o graphicengine_test.o graphic_engine.o game.o space.o link.o player.o command.o set.o gamereader.o object.o die.o inventory.o
	$(CC) $(CFLAGS) -o graphicengine_test $(OBJPATH)screen.o $(OBJPATH)graphicengine_test.o $(OBJPATH)graphic_engine.o $(OBJPATH)game.o $(OBJPATH)space.o $(OBJPATH)link.o $(OBJPATH)player.o $(OBJPATH)command.o $(OBJPATH)set.o $(OBJPATH)gamereader.o $(OBJPATH)object.o $(OBJPATH)die.o $(OBJPATH)inventory.o

command_test: command.o command_test.o
	$(CC) $(CFLAGS) -o command_test $(OBJPATH)command.o $(OBJPATH)command_test.o

gamereader_test: gamereader_test.o screen.o graphic_engine.o game.o space.o link.o player.o command.o set.o gamereader.o object.o die.o inventory.o
	$(CC) $(CFLAGS) -o gamereader_test $(OBJPATH)gamereader_test.o $(OBJPATH)screen.o $(OBJPATH)graphic_engine.o $(OBJPATH)game.o $(OBJPATH)space.o $(OBJPATH)link.o $(OBJPATH)player.o $(OBJPATH)command.o $(OBJPATH)set.o $(OBJPATH)gamereader.o $(OBJPATH)object.o $(OBJPATH)die.o $(OBJPATH)inventory.o

game_test: game_test.o screen.o graphic_engine.o game.o space.o link.o player.o command.o set.o gamereader.o object.o die.o inventory.o
	$(CC) $(CFLAGS) -o game_test $(OBJPATH)game_test.o $(OBJPATH)screen.o $(OBJPATH)graphic_engine.o $(OBJPATH)game.o $(OBJPATH)space.o $(OBJPATH)link.o $(OBJPATH)player.o $(OBJPATH)command.o $(OBJPATH)set.o $(OBJPATH)gamereader.o $(OBJPATH)object.o $(OBJPATH)die.o $(OBJPATH)inventory.o



#=============================================================
# Generación de archivos .o
#=============================================================
# Por cada archivo .c se genera un .o
# Cada .o depende del archivo .c indicado y de todos los .h que se incluyan

command.o: $(SRCPATH)command.c $(INCPATH)command.h
	$(CC) $(CFLAGS) -c $(SRCPATH)command.c -o $(OBJPATH)command.o
	
game.o: $(SRCPATH)game.c $(INCPATH)game.h $(INCPATH)gamereader.h
	$(CC) $(CFLAGS) -c $(SRCPATH)game.c -o $(OBJPATH)game.o
	
game_loop.o: $(SRCPATH)game_loop.c $(INCPATH)graphic_engine.h $(INCPATH)gamereader.h
	$(CC) $(CFLAGS) -c $(SRCPATH)game_loop.c -o $(OBJPATH)game_loop.o
	
graphic_engine.o: $(SRCPATH)graphic_engine.c $(INCPATH)screen.h $(INCPATH)graphic_engine.h
	$(CC) $(CFLAGS) -c $(SRCPATH)graphic_engine.c -o $(OBJPATH)graphic_engine.o
	
screen.o: $(SRCPATH)screen.c $(INCPATH)screen.h
	$(CC) $(CFLAGS) -c $(SRCPATH)screen.c -o $(OBJPATH)screen.o
	
inventory.o: $(SRCPATH)inventory.c $(INCPATH)inventory.h
	$(CC) $(CFLAGS) -c $(SRCPATH)inventory.c -o $(OBJPATH)inventory.o
	
set_test.o: $(SRCPATH)set_test.c $(INCPATH)set.h
	$(CC) $(CFLAGS) -c $(SRCPATH)set_test.c -o $(OBJPATH)set_test.o
	
space.o: $(SRCPATH)space.c $(INCPATH)space.h $(INCPATH)types.h
	$(CC) $(CFLAGS) -c $(SRCPATH)space.c -o $(OBJPATH)space.o
	
gamereader.o: $(SRCPATH)gamereader.c $(INCPATH)gamereader.h $(INCPATH)game.h
	$(CC) $(CFLAGS) -c $(SRCPATH)gamereader.c -o $(OBJPATH)gamereader.o
	
object.o: $(SRCPATH)object.c $(INCPATH)object.h $(INCPATH)types.h
	$(CC) $(CFLAGS) -c $(SRCPATH)object.c -o $(OBJPATH)object.o
	
player.o: $(SRCPATH)player.c $(INCPATH)player.h $(INCPATH)types.h $(INCPATH)inventory.h
	$(CC) $(CFLAGS) -c $(SRCPATH)player.c -o $(OBJPATH)player.o
	
set.o: $(SRCPATH)set.c $(INCPATH)set.h $(INCPATH)types.h
	$(CC) $(CFLAGS) -c $(SRCPATH)set.c -o $(OBJPATH)set.o
	
die.o: $(SRCPATH)die.c $(INCPATH)die.h
	$(CC) $(CFLAGS) -c $(SRCPATH)die.c -o $(OBJPATH)die.o
	
link.o: $(SRCPATH)link.c $(INCPATH)link.h
	$(CC) $(CFLAGS) -c $(SRCPATH)link.c -o $(OBJPATH)link.o
	
die_test.o: $(SRCPATH)die_test.c $(INCPATH)die.h
	$(CC) $(CFLAGS) -c $(SRCPATH)die_test.c -o $(OBJPATH)die_test.o
	
link_test.o: $(SRCPATH)link_test.c $(INCPATH)link.h
	$(CC) $(CFLAGS) -c $(SRCPATH)link_test.c -o $(OBJPATH)link_test.o
	
player_test.o: $(SRCPATH)player_test.c $(INCPATH)player.h
	$(CC) $(CFLAGS) -c $(SRCPATH)player_test.c -o $(OBJPATH)player_test.o
	
object_test.o: $(SRCPATH)object_test.c $(INCPATH)object.h
	$(CC) $(CFLAGS) -c $(SRCPATH)object_test.c -o $(OBJPATH)object_test.o
	
space_test.o: $(SRCPATH)space_test.c $(INCPATH)space.h
	$(CC) $(CFLAGS) -c $(SRCPATH)space_test.c -o $(OBJPATH)space_test.o
	
inventory_test.o: $(SRCPATH)inventory_test.c $(INCPATH)inventory.h
	$(CC) $(CFLAGS) -c $(SRCPATH)inventory_test.c -o $(OBJPATH)inventory_test.o
	
graphicengine_test.o: $(SRCPATH)graphicengine_test.c $(INCPATH)graphic_engine.h
	$(CC) $(CFLAGS) -c $(SRCPATH)graphicengine_test.c -o $(OBJPATH)graphicengine_test.o
	
screen_test.o: $(SRCPATH)screen_test.c $(INCPATH)screen.h
	$(CC) $(CFLAGS) -c $(SRCPATH)screen_test.c -o $(OBJPATH)screen_test.o
	
command_test.o: $(SRCPATH)command_test.c $(INCPATH)command.h
	$(CC) $(CFLAGS) -c $(SRCPATH)command_test.c -o $(OBJPATH)command_test.o
	
gamereader_test.o: $(SRCPATH)gamereader_test.c $(INCPATH)gamereader.h $(INCPATH)game.h $(INCPATH)link.h $(INCPATH)object.h $(INCPATH)space.h
	$(CC) $(CFLAGS) -c $(SRCPATH)gamereader_test.c -o $(OBJPATH)gamereader_test.o
	
game_test.o: $(SRCPATH)game_test.c $(INCPATH)game.h
	$(CC) $(CFLAGS) -c $(SRCPATH)game_test.c -o $(OBJPATH)game_test.o




#=================================================================
# El objetivo clean limpia los archivos .o, la carpeta comprimida,
# los módulos de prueba y ejecutables del juego
#=================================================================

clean:
	rm -rf $(OBJPATH)*.o  $(EJECUTABLES) *.tgz $(DOCPATH)html $(DOCPATH)latex
	
#=================================================================
# El objetivo doc limpia los archivos .o, la carpeta comprimida,
# los módulos de prueba y ejecutables del juego, y crea la 
# documentación del proyecto en formatos html y latex
#=================================================================
doc: clean
	doxygen

#=============================================================
# Empaquetar el código en archivo tgz
#=============================================================
# El objetivo box comprime los archivos .c y .h en tar,
# una vez limpiados los .o y ejecutables del directorio.
box: clean
	tar -czvf PPROG_2163_I2_P07.tgz $(SRCPATH) $(INCPATH) $(OBJPATH) *.dat Makefile

#=============================================================
# Comprobación de fugas de memoria con Valgrind
#=============================================================
valgrind:
	valgrind -v --leak-check=full ./juego data.dat -l fichero.log

val_set:
	valgrind -v --leak-check=full ./set_test

val_die:
	valgrind -v --leak-check=full ./die_test

val_link:
	valgrind -v --leak-check=full ./link_test

val_player:
		valgrind -v --leak-check=full ./player_test

val_object:
	valgrind -v --leak-check=full ./object_test

val_space:
	valgrind -v --leak-check=full ./space_test

val_inventory:
	valgrind -v --leak-check=full ./inventory_test

val_graphicengine:
	valgrind -v --leak-check=full ./graphicengine_test

val_screen:
	valgrind -v --leak-check=full ./screen_test

val_command:
	valgrind -v --leak-check=full ./command_test

val_gamereader:
	valgrind -v --leak-check=full ./gamereader_test

val_game:
	valgrind -v --leak-check=full ./game_test
