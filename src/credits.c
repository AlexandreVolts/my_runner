/*
** EPITECH PROJECT, 2017
** credits.c
** File description:
** Credits
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "defines.h"
#include "prototypes.h"

sfText **create_credits(sfFont *font)
{
	sfText **output = malloc(sizeof(sfText *) * CREDIT_LINES_NUMBER);
	char *lines[CREDIT_LINES_NUMBER] = {
		"Game developper:", "Alexandre Cochet",
		"Music:", "Karl Brueggemann",
		"Sound Design:", "Sega",
		"Game Design:", "Eder Muniz",
		"(Press Echap to leave)"
	};
	sfVector2f position = {0, 0};

	for (int i = 0; i < CREDIT_LINES_NUMBER; i++) {
		output[i] = create_text(lines[i], font, 1);
		position.x = sfText_getPosition(output[i]).x;
		position.y = ((float)HEIGHT * ((float)(i + 1) /
			(CREDIT_LINES_NUMBER + 1)));
		sfText_setPosition(output[i], position);
		if (i % 2 == 0) {
			sfText_setColor(output[i], sfYellow);
			sfText_setCharacterSize(output[i], 43);
		}
	}

	return (output);
}

void draw_credits(sfRenderWindow *window, sfText **credits)
{
	for (int i = 0; i < CREDIT_LINES_NUMBER; i++)
		sfRenderWindow_drawText(window, credits[i], NULL);
}

void destroy_credits(sfText **textes)
{
	for (int i = 0; i < CREDIT_LINES_NUMBER; i++)
		sfText_destroy(textes[i]);
	free(textes);
}
