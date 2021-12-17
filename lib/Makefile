##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile
##

SRC	=	my_putstr.c	\
		my_putcstr.c	\
		my_strlen.c	\
		my_strcpy.c	\
		my_strcat.c	\
		nbr_to_str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $NAME

$NAME:		$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
