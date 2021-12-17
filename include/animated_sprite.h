/*
** EPITECH PROJECT, 2017
** animated_sprite.h
** File description:
** Animated sprite structure
*/

#pragma once
#include <SFML/Graphics.h>

typedef struct animated_sprite
{
	sfTexture *texture;
	sfSprite *sprite;
	sfClock *clock;
	sfIntRect rect;
	int current;
	int limit;
	float next;
} animated_sprite_t;
