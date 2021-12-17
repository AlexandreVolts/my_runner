/*
** EPITECH PROJECT, 2018
** text_manager.h
** File description:
** Text manager structure
*/

#pragma once
#include <SFML/Graphics.h>

typedef struct text_manager
{
	sfFont *font;
	sfText *score;
	sfText *rings;
	sfText *lifes;
	sfText *game_over_text;
	sfText *level_clear;
} text_manager_t;
