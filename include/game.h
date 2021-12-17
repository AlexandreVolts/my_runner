/*
** EPITECH PROJECT, 2017
** system.h
** File description:
** System structure
*/

#pragma once
#include <SFML/Graphics.h>
#include "animated_sprite.h"
#include "layer.h"
#include "map.h"
#include "menu.h"
#include "player.h"
#include "sound.h"
#include "text_manager.h"

typedef struct game
{
	sfRenderWindow *window;
	sfEvent event;
	map_t *map;
	int unity;
	int has_started;
	layer_t **layers;
	animated_sprite_t **game_sprites;
	player_t *player;
	mixer_t *mixer;
	menu_t *pause_menu;
	int has_ended;
	int game_over;
	int paused;
	int score;
	text_manager_t *textes;
} game_t;
