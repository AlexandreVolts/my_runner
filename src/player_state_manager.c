/*
** EPITECH PROJECT, 2018
** player_state_manager.c
** File description:
** Management of player state
*/

#include "player_defines.h"
#include "player.h"

void update_animation_state(player_t *player)
{
	player->animation_state++;
	if (player->state == PLAYER_RUNNING_STATE) {
		if (player->animation_state >= PLAYER_RUN_TEXTURES)
			player->animation_state = 0;
	}
	else if (player->state == PLAYER_JUMPING_STATE) {
		if (player->animation_state >= PLAYER_TEXTURES_PER_LINE)
			player->animation_state = 0;
	}
	else if (player->state == PLAYER_DYING_STATE) {
		if (player->animation_state >= PLAYER_DEATH_TEXTURES)
			player->animation_state = 0;
	}
	else if (player->state == PLAYER_CLEARING_STATE) {
		if (player->animation_state >= PLAYER_RUN_TEXTURES)
			player->animation_state = 0;
	}
}
