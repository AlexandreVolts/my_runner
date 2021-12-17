/*
** EPITECH PROJECT, 2018
** game_events_manager.c
** File description:
** Restart function
*/

#include "defines.h"
#include "game.h"
#include "player_defines.h"
#include "prototypes.h"

void on_player_death(game_t *game)
{
	game->map->has_ended = 0;
	if (game->player->is_dead == 0) {
		sfSound_play(game->player->mixer->sounds[1]->sound);
		game->player->lifes--;
		game->player->speed.y = -JUMP_HEIGHT * 1.5;
		game->player->is_dead = 1;
		cat_text_with_int(game->textes->lifes, "Lifes: ",
			game->player->lifes);
		game->score /= SCORE_DIVIDER;
	}
	if (game->player->position.y >= HEIGHT)
		game->player->state = PLAYER_ENDING_STATE;
}

void reanimate_player(game_t *game)
{
	game->player->is_dead = 0;
	game->player->state = PLAYER_RUNNING_STATE;
	game->map->position.x = 0;
	sfText_setString(game->textes->rings, "Rings: 0");
	init_player(game->player);
}

void listen_player_state(game_t *game)
{
	player_t *p = game->player;

	if (p->state == PLAYER_RUNNING_STATE ||
		p->state == PLAYER_JUMPING_STATE) {
		if (game->map->has_ended == 0)
			move_map(game);
	}
	if (p->state == PLAYER_DYING_STATE)
		on_player_death(game);
	else
		apply_collisions(game);
	if (p->state == PLAYER_ENDING_STATE)
		listen_game_over(game);
}

void listen_game_over(game_t *game)
{
	if (game->player->lifes <= 0 && game->game_over == 0) {
		game->game_over = 1;
		sfText_setString(game->textes->lifes, "Lifes\t0");
		sfSound_stop(game->mixer->sounds[0]->sound);
		sfSound_play(game->mixer->sounds[2]->sound);
	}
	if (game->game_over == 1)
		sfRenderWindow_drawText(game->window,
			game->textes->game_over_text, NULL);
	else
		reanimate_player(game);
}

void listen_map_ended(game_t *game)
{
	if (game->player->position.x >= WIDTH / 2 && game->has_ended == 0) {
		if (game->player->state == PLAYER_RUNNING_STATE) {
			game->has_ended = 1;
			game->player->state = PLAYER_CLEARING_STATE;
			game->player->speed.x = 0;
			sfSound_play(game->mixer->sounds[1]->sound);
			sfSound_stop(game->mixer->sounds[0]->sound);
			game->score += game->player->rings * RING_MULTIPLIER;
			game->score += game->player->lifes * LIFE_MULTIPLIER;
			cat_text_with_int(game->textes->score, "Score: ",
				game->score);
			move_textes_when_level_cleared(game->textes);
		}
	}
	if (game->has_ended == 1) {
		sfRenderWindow_drawText(game->window,
			game->textes->level_clear, NULL);
	}
}
