DIR	=	src/

INC_DIR =	include/

LIB_DIR =	lib/

SRC	=	$(DIR)main.c				\
		$(DIR)file_parse.c			\
		$(DIR)initialiser.c			\
		$(DIR)animated_sprite_functions.c	\
		$(DIR)layer_functions.c			\
		$(DIR)menu_functions.c			\
		$(DIR)menu_actions_functions.c		\
		$(DIR)button_functions.c		\
		$(DIR)text_functions.c			\
		$(DIR)map_functions.c			\
		$(DIR)player_functions.c		\
		$(DIR)player_state_manager.c		\
		$(DIR)player_events.c			\
		$(DIR)text_manager_functions.c		\
		$(DIR)events.c				\
		$(DIR)render_functions.c		\
		$(DIR)draw_map.c			\
		$(DIR)collisions_manager.c		\
		$(DIR)physics_manager.c			\
		$(DIR)sound_functions.c			\
		$(DIR)game_events_manager.c		\
		$(DIR)restart_functions.c		\
		$(DIR)credits.c				\
		$(DIR)destroy.c				\
		$(DIR)display_help.c

CFLAGS	=	-Wall -Wextra -Wpedantic -I ./$(INC_DIR) -I $(LIB_DIR)$(INC_DIR)

LFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -L $(LIB_DIR) -lmy -lm

CC	=	gcc -g

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib && make && make clean && cd ../..
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	cd lib && make fclean && cd ../..
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
