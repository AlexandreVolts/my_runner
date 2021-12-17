/*
** EPITECH PROJECT, 2017
** menu.h
** File description:
** Menu structure
*/

#pragma once
#include <SFML/Graphics.h>
#include "animated_sprite.h"
#include "button.h"
#include "mixer.h"

typedef struct menu
{
	sfFont *font;
	button_t **buttons;
	animated_sprite_t *selector;
	mixer_t *mixer;
	sfRectangleShape *background;
	int current;
	int button_nbr;
	int is_off;
} menu_t;
