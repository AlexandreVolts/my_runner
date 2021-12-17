/*
** EPITECH PROJECT, 2017
** map.h
** File description:
** Map structure
*/

#pragma once
#include <SFML/Graphics.h>

typedef struct map
{
	char *content;
	sfVector2f position;
	sfVector2f speed;
	sfVector2i size;
	sfVector2i visible_blocs;
	int has_ended;
} map_t;
