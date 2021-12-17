/*
** EPITECH PROJECT, 2017
** physics_manager.c
** File description:
** Physic manager
*/

#include "defines.h" 
#include "game.h"
#include "player_defines.h"
#include "player.h"
#include "prototypes.h"

void apply_physics(game_t *game)
{
	game->player->position.y += GRAVITY;
	apply_jump_physics(game->player, game->unity);
}

void apply_jump_physics(player_t *player, int unity)
{
	player->speed.y *= JUMP_FRICTION;
	player->position.x += player->speed.x;
	player->position.y += player->speed.y;
	if (player->position.x + unity <= 0)
		player->state = PLAYER_DYING_STATE;
	if (player->position.y + unity > HEIGHT)
		player->state = PLAYER_DYING_STATE;
}
