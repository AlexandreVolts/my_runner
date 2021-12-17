/*
** EPITECH PROJECT, 2017
** render.c
** File description:
** Render functions
*/

#include "defines.h"
#include "game.h"
#include "map_defines.h"
#include "menu.h"
#include "player_defines.h"
#include "prototypes.h"

void render_menu(game_t *game, menu_t *menu)
{
	for (int i = 0; i < LAYER_NUMBER; i++) {
		if (i == LIGHT_BACKGROUND_ID || i == LIGHT_FOREGROUND_ID)
			move_layer(game->layers[i]);
		draw_layer(game->window, game->layers[i]);
	}
	if (menu->is_off == 0)
		draw_menu(game->window, menu);
}

void render_game(game_t *game)
{
	int m_c = game->map->has_ended == 0;

	m_c = m_c && game->player->state < PLAYER_DYING_STATE;
	m_c  = m_c && game->paused == 0;
	for (int i = 0; i < LAYER_NUMBER; i++) {
		if (i == MAP_LAYER_POSITION)
			render_game_elements(game);
		if (m_c || i == LIGHT_BACKGROUND_ID)
			move_layer(game->layers[i]);
		draw_layer(game->window, game->layers[i]);
	}
}

void render_game_elements(game_t *game)
{
	draw_map(game);
	sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
	draw_textes(game->window, game->textes);
	if (game->paused == 0) {
		if (game->player->state < PLAYER_DYING_STATE) {
			game->score += update_player(game->player);
			cat_text_with_int(game->textes->score, " Score: ",
				game->score);
		}
		else
			update_player(game->player);
		manage_game_state(game);
		sfSound_setVolume(game->mixer->sounds[0]->sound, 100);
	}
	else {
		draw_menu(game->window, game->pause_menu);
		sfSound_setVolume(game->mixer->sounds[0]->sound, 50);
	}
}

void manage_game_state(game_t *game)
{
	if (game->game_over == 0) {
		apply_physics(game);
		listen_player_state(game);
		if (game->map->has_ended == 1)
			listen_map_ended(game);
	}
	else if (game->game_over == 1)
		listen_game_over(game);
}
