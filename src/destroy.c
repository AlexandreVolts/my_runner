/*
** EPITECH PROJECT, 2017
** destroy.c
** File description:
** Free game objects
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "defines.h"
#include "game.h"
#include "map_defines.h"
#include "prototypes.h"

void destroy_all(menu_t *menu, sfText **credits, game_t *game)
{
	destroy_menu(menu);
	destroy_credits(credits);
	destroy_layers(game->layers);
	destroy_player(game->player);
	destroy_game(game);
}

void destroy_game(game_t *game)
{
	destroy_menu(game->pause_menu);
	destroy_game_elements(game);
	destroy_text_manager(game->textes);
	sfRenderWindow_destroy(game->window);
	free(game->map->content);
	free(game->map);
	free(game);
}

void destroy_game_elements(game_t *game)
{
	destroy_mixer(game->mixer);
	for (int i = 0; i < PLATEFORM_NUMBER; i++)
		destroy_animated_sprite(game->game_sprites[i]);
	free(game->game_sprites);
}
