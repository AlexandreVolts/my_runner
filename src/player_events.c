/*
** EPITECH PROJECT, 2018
** player_events.c
** File description:
** PLayer events
*/

#include "defines.h"
#include "game.h"
#include "map_defines.h"
#include "player_defines.h"
#include "player.h"
#include "prototypes.h"

void on_spike_touched(player_t *player)
{
	player->state = PLAYER_DYING_STATE;
	sfSound_play(player->mixer->sounds[1]->sound);
}

void on_ground_collision(player_t *player, int top)
{
	player->position.y = top;
	player->jump_nbr = 0;
	if (player->state < PLAYER_DYING_STATE)
		player->state = PLAYER_RUNNING_STATE;
}

void on_top_collision(player_t *player)
{
	if (player->state < PLAYER_DYING_STATE)
		player->state = PLAYER_RUNNING_STATE;
	player->speed.y = -GRAVITY / 2;
}

void on_ring_touched(game_t *game, sfVector2i pos)
{
	game->player->rings++;
	sfSound_play(game->player->mixer->sounds[2]->sound);
	cat_text_with_int(game->textes->rings, "Rings: ", game->player->rings);
	set_char_at(game->map, pos.x, pos.y, SKY_CHAR);
}
