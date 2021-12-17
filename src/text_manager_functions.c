/*
** EPITECH PROJECT, 2018
** text_manager_functions.c
** File description:
** Text manager function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "defines.h"
#include "lib_prototypes.h"
#include "prototypes.h"
#include "text_manager.h"

text_manager_t *create_text_manager(void)
{
	text_manager_t *output = malloc(sizeof(text_manager_t));
	sfVector2f pos = {0, HEIGHT / 4};

	output->font = sfFont_createFromFile("./assets/font/AldotheApache.ttf");
	output->score = create_text("Score: 0", output->font, 0);
	output->rings = create_text("Rings: 0", output->font, 0);
	output->lifes = create_text("Lifes: 3", output->font, 0);
	output->game_over_text = create_text("Game over", output->font, 1);
	output->level_clear = create_text("Level cleared !", output->font, 1);
	pos.x = sfText_getPosition(output->game_over_text).x;
	sfText_setPosition(output->game_over_text, pos);
	pos.x = sfText_getPosition(output->level_clear).x;
	sfText_setPosition(output->level_clear, pos);
	set_text_manager_properties(output->score, 0);
	set_text_manager_properties(output->rings, 1);
	set_text_manager_properties(output->lifes, 2);

	return (output);
}

void set_text_manager_properties(sfText *text, int id)
{
	sfFloatRect bounds;
	sfVector2f pos = {TEXT_PADDING, 0};

	sfText_setCharacterSize(text, 35);
	bounds = sfText_getLocalBounds(text);
	pos.y = id * (bounds.height + TEXT_PADDING);
	sfText_setColor(text, sfColor_fromRGB(255, 128, 0));
	sfText_setPosition(text, pos);
}

void draw_textes(sfRenderWindow *window, text_manager_t *text_manager)
{
	sfRenderWindow_drawText(window, text_manager->score, NULL);
	sfRenderWindow_drawText(window, text_manager->rings, NULL);
	sfRenderWindow_drawText(window, text_manager->lifes, NULL);
}

void move_textes_when_level_cleared(text_manager_t *text_manager)
{
	char str[100];
	sfFloatRect rect = sfText_getLocalBounds(text_manager->level_clear);
	sfVector2f pos = {(WIDTH - rect.width) / 2, 0};

	str[0] = '\0';
	pos.y = HEIGHT / 2 - rect.height * 2;
	sfText_setPosition(text_manager->score, pos);
	pos.y = HEIGHT / 2;
	my_strcat(str, sfText_getString(text_manager->rings));
	my_strcat(str, "\t\tx");
	cat_text_with_int(text_manager->rings, str, RING_MULTIPLIER);
	sfText_setPosition(text_manager->rings, pos);
	pos.y = HEIGHT / 2 + rect.height * 2;
	str[0] = '\0';
	my_strcat(str, sfText_getString(text_manager->lifes));
	my_strcat(str, "\t\tx");
	cat_text_with_int(text_manager->lifes, str, LIFE_MULTIPLIER);
	sfText_setPosition(text_manager->lifes, pos);
}

void destroy_text_manager(text_manager_t *text_manager)
{
	sfFont_destroy(text_manager->font);
	sfText_destroy(text_manager->score);
	sfText_destroy(text_manager->rings);
	sfText_destroy(text_manager->lifes);
	sfText_destroy(text_manager->game_over_text);
	sfText_destroy(text_manager->level_clear);
}
