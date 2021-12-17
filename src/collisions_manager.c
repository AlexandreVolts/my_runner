/*
** EPITECH PROJECT, 2017
** collision_manager.c
** File description:
** Collision manager
*/

#include <math.h>
#include "defines.h"
#include "game.h"
#include "map_defines.h"
#include "player_defines.h"
#include "prototypes.h"

sfVector2i get_player_position(game_t *game)
{
	sfVector2i pos;

	pos.x = (game->player->position.x - game->map->position.x);
	pos.y = (game->player->position.y - game->map->position.y);
	pos.x = round(pos.x / game->unity);
	pos.y = round(pos.y / game->unity);

	return (pos);
}

void apply_collision_with_wall(game_t *game, sfVector2i pos)
{
	int x_col;

	pos.x++;
	x_col = get_char_at(game->map, pos.x, pos.y);
	if (x_col >= GROUND_CHAR && x_col <= UNDERGROUND_CHAR) {
		if (game->map->has_ended == 0)
			game->player->speed.x = -game->map->speed.x;
		else
			game->player->speed.x = 0.25;
	}
	else {
		if (game->map->has_ended == 0)
			game->player->speed.x = 0.25;
		else
			game->player->speed.x = game->map->speed.x;
	}
	if (x_col == SPIKE_CHAR)
		on_spike_touched(game->player);
	else if (x_col == RING_CHAR)
		on_ring_touched(game, pos);
}

void apply_bottom_collision(game_t *game, sfVector2i pos)
{
	int top = floor(game->player->position.y / game->unity) * game->unity;
	int y_col_down;
	int is_on_ground;

	pos.y++;
	y_col_down = get_char_at(game->map, pos.x, pos.y);
	is_on_ground = (y_col_down >= GROUND_CHAR &&
		y_col_down <= UNDERGROUND_CHAR);
	if (y_col_down == RING_CHAR)
		on_ring_touched(game, pos);
	if (y_col_down == SPIKE_CHAR)
		on_spike_touched(game->player);
	else if (is_on_ground && game->player->speed.y > -GRAVITY)
		on_ground_collision(game->player, top);
}

void apply_top_collision(game_t *game, sfVector2i pos)
{
	int y_col_top = get_char_at(game->map, pos.x, pos.y);

	if (y_col_top >= GROUND_CHAR && y_col_top <= UNDERGROUND_CHAR)
		on_top_collision(game->player);
}

void apply_collisions(game_t *game)
{
	sfVector2i pos = get_player_position(game);

	if (pos.x <= game->map->size.x && pos.y <= game->map->size.y) {
		if (game->player->state != PLAYER_CLEARING_STATE)
			apply_collision_with_wall(game, pos);
		if (game->player->state == PLAYER_JUMPING_STATE) {
			pos.x++;
			apply_bottom_collision(game, pos);
			pos.x--;
		}
		apply_bottom_collision(game, pos);
		apply_top_collision(game, pos);
	}
}
