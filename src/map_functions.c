/*
** EPITECH PROJECT, 2017
** map_functions.c
** File description:
** Functions for game's map
*/

#include <stdlib.h>
#include "defines.h"
#include "map_defines.h"
#include "map.h"
#include "prototypes.h"

static void add_details_to_map(map_t *map, int x, int y)
{
	char cur = get_char_at(map, x, y);
	char ground_char;
	char vegetation_char;
	char up_char;

	if (cur != GROUND_CHAR)
		return;
	up_char = get_char_at(map, x, y - 1);
	if (up_char == SKY_CHAR || up_char == RING_CHAR) {
		ground_char = GROUND_CHAR + rand() % GROUND_CHAR_TYPES;
		set_char_at(map, x, y, ground_char);
		if (rand() % 2 == 0 || up_char != SKY_CHAR) {
			return;
		}
		vegetation_char = UNDERGROUND_CHAR + 1 + rand() % 5;
		set_char_at(map, x, y - 1, vegetation_char);
	}
	else if (cur >= GROUND_CHAR && cur < GROUND_CHAR + GROUND_CHAR_TYPES) {
		set_char_at(map, x, y, UNDERGROUND_CHAR);
	}
}

char get_char_at(map_t *map, int x, int y)
{
	return (map->content[y * map->size.x + x]);
}

void set_char_at(map_t *map, int x, int y, char c)
{
	map->content[y * map->size.x + x] = c;
}

void modify_map_content(map_t *map)
{
	for (int i = 0; i < map->size.x; i++) {
		for (int j = 0; j < map->size.y; j++) {
			add_details_to_map(map, i, j);
		}
	}
}
