/*
** EPITECH PROJECT, 2017
** button_functions.c
** File description:
** Button functions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "button.h"
#include "defines.h"

button_t *create_button(sfVector2f dimentions, sfText *content, int id)
{
	button_t *output = malloc(sizeof(button_t));
	sfVector2f position;
	sfVector2f text_position;
	sfFloatRect text_size = sfText_getLocalBounds(content);

	position.x = (WIDTH - dimentions.x) / 2;
	position.y = (HEIGHT - dimentions.y) / 2 + dimentions.y * (id - 1);
	text_position.x = position.x + (dimentions.x - text_size.width) / 2;
	text_position.y = position.y + (dimentions.y - text_size.height) / 2;
	output->shape = sfRectangleShape_create();
	output->text = content;
	output->background_color = sfTransparent;
	output->on_over_color = sfColor_fromRGBA(50, 0, 0, 128);
	sfRectangleShape_setSize(output->shape, dimentions);
	sfRectangleShape_setPosition(output->shape, position);
	sfText_setPosition(output->text, text_position);

	return (output);
}

void draw_button(sfRenderWindow *window, button_t *button)
{
	sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
	sfRenderWindow_drawText(window, button->text, NULL);
}

void destroy_button(button_t *button)
{
	sfRectangleShape_destroy(button->shape);
	sfText_destroy(button->text);
	free(button);

}
