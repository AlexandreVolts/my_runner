/*
** EPITECH PROJECT, 2017
** file_parse.c
** File description:
** File parsing
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "defines.h"
#include "map_defines.h"
#include "map.h"
#include "prototypes.h"

static char *get_file_content(char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char buffer[100000];

	if (fd < 0)
		exit(84);

	int size = read(fd, buffer, 100000);
	char *output = malloc(sizeof(char) * (size + 1));

	for (int i = 0; i < size; i++)
		output[i] = buffer[i];
	output[size] = '\0';
	return (output);
}

static void compute_dimentions(map_t *map)
{
	int i = 0;
	
	map->size.x = 0;
	map->size.y = 0;
	for (int j = 0; map->content[j] != '\0'; i++, j++) {
		if (map->content[j] != '\n' && map->content[j] != '\0')
			continue;
		map->size.x = map->size.x > i ? map->size.x : i;
		map->size.y++;
		i = 0;
	}
	map->size.x = map->size.x > i ? map->size.x : i;
	map->size.y++;
	map->visible_blocs.y = map->size.y;
}

static void fill_missing_parts(map_t *map)
{
	char *cpy = malloc(sizeof(char) * (map->size.x * map->size.y + 1));
	int i = 0;

	for (; i < map->size.x * map->size.y; i++) {
		cpy[i] = SKY_CHAR;
	}
	for (int j = 0, i = 1, k = 0; map->content[j] != '\0'; i++, j++, k++) {
		if (map->content[j] == '\n') {
			i += (map->size.x - k);
			k = 0;
			continue;
		}
		cpy[i] = map->content[j];
	}
	free(map->content);
	map->content = cpy;
}

map_t *datas_to_map(char *filepath)
{
	map_t *output = malloc(sizeof(map_t));

	output->position.x = 0;
	output->position.y = 0;
	output->content = get_file_content(filepath);
	compute_dimentions(output);
	fill_missing_parts(output);
	modify_map_content(output);
	output->speed.x = ((float)MAP_LAYER_POSITION + 1) * LAYER_SPEED + 0.5;
	output->speed.y = 0;
	output->has_ended = 0;
	return (output);
}
