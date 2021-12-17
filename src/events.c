/*
** EPITECH PROJECT, 2017
** events.c
** File description:
** Events management
*/

#include <SFML/Graphics.h>
#include "defines.h"
#include "game.h"
#include "menu.h"
#include "player_defines.h"
#include "prototypes.h"

void manage_events(game_t *game, menu_t *menu)
{
	while (sfRenderWindow_pollEvent(game->window, &game->event)) {
		if (game->event.type == sfEvtClosed)
			sfRenderWindow_close(game->window);
		if (game->event.type == sfEvtKeyPressed) {
			if (game->has_started == 0)
				update_menu_display(game, menu,
					game->event.key);
			else {
				on_key_pressed(game, game->event.key);
				if (game->has_started == 0)
					menu->is_off = 0;
			}
		}
	}
}

void update_menu_display(game_t *game, menu_t *menu, sfKeyEvent event)
{
	if (event.code == sfKeyUp) {
		menu->is_off = 0;
		update_menu_state(menu, -1);
	}
	else if (event.code == sfKeyDown) {
		menu->is_off = 0;
		update_menu_state(menu, 1);
	}
	else if (event.code == sfKeyReturn || event.code == sfKeySpace) {
		menu->is_off = 1;
		apply_menu_action(game, menu->current);
		sfSound_play(menu->mixer->sounds[1]->sound);
	}
	else if (event.code == sfKeyEscape)
		menu->is_off = 0;
}

void on_key_pressed(game_t *game, sfKeyEvent event)
{
	int is_valid_state = game->player->state < PLAYER_CLEARING_STATE;

	if (game->paused == 0 && is_valid_state) {
		if (event.code == sfKeySpace || event.code == sfKeyUp)
			on_game_play(game);
	}
	else if (game->paused == 1)
		on_game_pause(game, event);

	if (event.code == sfKeyReturn)
		game->paused = 0;
	else if (event.code == sfKeyEscape) {
		if (game->paused == 0 && is_valid_state)
			game->paused = 1;
		else
			game->paused = 0;
	}
}

void on_game_play(game_t *game)
{
	if (game->player->jump_nbr < PLAYER_JUMP_NBR) {
		if (game->player->state < PLAYER_DYING_STATE) {
			game->player->speed.y = -JUMP_HEIGHT;
			game->player->jump_nbr++;
			game->player->state = PLAYER_JUMPING_STATE;
			sfSound_play(game->player->mixer->sounds[0]->sound);
		}
	}
}

void on_game_pause(game_t *game, sfKeyEvent event)
{
	if (event.code == sfKeyUp)
		update_menu_state(game->pause_menu, -1);
	else if (event.code == sfKeyDown)
		update_menu_state(game->pause_menu, 1);
	else if (event.code == sfKeySpace || event.code == sfKeyReturn)
		apply_pause_menu_action(game);
}
