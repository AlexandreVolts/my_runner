/*
** EPITECH PROJECT, 2017
** draw_map.c
** File description:
** Animation functions
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "defines.h"
#include "game.h"
#include "map_defines.h"
#include "prototypes.h"

void move_map(game_t *game)
{
	int x = fabs(game->map->position.x) / game->unity;
	map_t *map = game->map;

	if (x + map->visible_blocs.x + 1 >= map->size.x) {
		map->has_ended = 1;
		game->player->speed.x = map->speed.x;
	}
	if (map->has_ended == 0)
		map->position.x -= map->speed.x;
}

void draw_map(game_t *game)
{
	int x = fabs(game->map->position.x) / game->unity;

	for (int i = x; i <= x + game->map->visible_blocs.x; i++) {
		for (int j = 0; j < game->map->size.y; j++)
			draw_map_sprite(game, i, j);
	}
}

void draw_map_sprite(game_t *game, int x, int y)
{
	int cur = get_char_at(game->map, x, y) - '0';
	sfVector2f pos;

	if (cur >= 0 && cur < PLATEFORM_NUMBER) {
		pos.x = x * game->unity + game->map->position.x;
		pos.y = y * game->unity + game->map->position.y;
		sfSprite_setPosition(game->game_sprites[cur]->sprite, pos);
		update_animated_sprite(game->game_sprites[cur]);
		draw_animated_sprite(game->window, game->game_sprites[cur]);
	}
}
