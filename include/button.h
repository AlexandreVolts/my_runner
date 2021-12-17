/*
** EPITECH PROJECT, 2017
** button.h
** File description:
** Button structure
*/

#pragma once
#include <SFML/Graphics.h>

typedef struct button
{
	sfRectangleShape *shape;
	sfText *text;
	sfColor background_color;
	sfColor on_over_color;
} button_t;
