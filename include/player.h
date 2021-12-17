/*
** EPITECH PROJECT, 2017
** player.h
** File description:
** Player structure
*/

#pragma once
#include <SFML/Graphics.h>
#include "mixer.h"

typedef struct player
{
	sfVector2f position;
	sfVector2f size;
	sfVector2f speed;
	sfTexture *texture;
	sfSprite *sprite;
	sfClock *clock;
	mixer_t *mixer;
	int state;
	int lifes;
	int rings;
	int animation_state;
	int jump_nbr;
	int is_dead;
} player_t;
