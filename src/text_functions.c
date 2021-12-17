/*
** EPITECH PROJECT, 2017
** text.c
** File description:
** Manage text creation
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "defines.h"
#include "game.h"
#include "lib_prototypes.h"

sfText *create_text(char *text, sfFont *font, int centered)
{
	sfText *output = sfText_create();
	sfVector2f pos = {0, 0};

	sfText_setFont(output, font);
	sfText_setString(output, text);
	sfText_setCharacterSize(output, 40);
	sfText_setColor(output, sfWhite);
	if (centered == 1) {
		pos.x = (WIDTH - sfText_getLocalBounds(output).width) / 2;
		pos.y = (HEIGHT - sfText_getLocalBounds(output).height) / 2;
	}
	sfText_setPosition(output, pos);

	return (output);
}

void cat_text_with_int(sfText *text, char *value, int nb)
{
	char *output;
	char *str = malloc(sizeof(char) * (int_len(nb) + my_strlen(value) + 1));

	my_strcpy(str, value);
	output = my_strcat(str, nbr_to_str(nb));
	sfText_setString(text, output);
	free(str);
}
