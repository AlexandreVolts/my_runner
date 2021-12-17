/*
** EPITECH PROJECT, 2017
** menu_functions.c
** File description:
** Menu functions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "button.h"
#include "defines.h"
#include "menu_defines.h"
#include "menu.h"
#include "prototypes.h"

menu_t *create_menu(char **names)
{
	menu_t *output = malloc(sizeof(menu_t));
	char *sounds[MENU_SOUNDS_NUMBER] = {
		"./assets/sound/selection.wav",
		"./assets/sound/validate.wav"
	};

	output->button_nbr = MENU_BUTTONS_NUMBER;
	create_menu_buttons(output, names,
		MENU_BUTTON_ROWS_NBR, MENU_BUTTONS_NUMBER);
	output->mixer = create_mixer(sounds, MENU_SOUNDS_NUMBER);
	init_menu(output);

	return (output);
}

void init_menu(menu_t *menu)
{
	sfVector2f position;
	sfColor bg_color = sfColor_fromRGBA(128, 128, 128, 128 / 2);
	sfVector2f bg_size = {WIDTH, HEIGHT};

	menu->is_off = 0;
	menu->current = 0;
	menu->selector = create_animated_sprite("./assets/img/ring.png", 4,
		0.1, NULL);
	position = sfRectangleShape_getPosition(menu->buttons[0]->shape);
	sfSprite_setPosition(menu->selector->sprite, position);
	menu->background = sfRectangleShape_create();
	sfRectangleShape_setFillColor(menu->background, bg_color);
	sfRectangleShape_setSize(menu->background, bg_size);
}

void create_menu_buttons(menu_t *menu, char **buttons_names, int rows, int cols)
{
	sfVector2f size;
	sfText *text;

	menu->font = sfFont_createFromFile("./assets/font/Long_Shot.ttf");
	menu->buttons = malloc(sizeof(button_t *) * menu->button_nbr);
	for (int i = 0; i < menu->button_nbr; i++) {
		size.x = WIDTH / rows;
		size.y = HEIGHT / (cols * 3);
		text = create_text(buttons_names[i], menu->font, 0);
		menu->buttons[i] = create_button(size, text, i);
	}
}

void destroy_menu(menu_t *menu)
{
	destroy_mixer(menu->mixer);
	for (int i = 0; i < menu->button_nbr; i++)
		destroy_button(menu->buttons[i]);
	destroy_animated_sprite(menu->selector);
	sfFont_destroy(menu->font);
	sfRectangleShape_destroy(menu->background);
	free(menu->buttons);
	free(menu);
}
