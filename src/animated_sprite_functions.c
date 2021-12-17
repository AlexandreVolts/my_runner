/*
** EPITECH PROJECT, 2017
** animated_sprite_functions.c
** File description:
** Functions for animated sprites
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "animated_sprite.h"

animated_sprite_t *create_animated_sprite(char *path, int limit, float next,
	sfIntRect *bounds)
{
	animated_sprite_t *output = malloc(sizeof(animated_sprite_t));

	output->texture = sfTexture_createFromFile(path, bounds);
	output->sprite = sfSprite_create();
	output->clock = sfClock_create();
	output->rect.left = 0;
	output->rect.top = 0;
	output->rect.width = sfTexture_getSize(output->texture).x / limit;
	output->rect.height = sfTexture_getSize(output->texture).y;
	output->current = 0;
	output->limit = limit;
	output->next = next;
	sfSprite_setTexture(output->sprite, output->texture, sfTrue);
	sfSprite_setTextureRect(output->sprite, output->rect);

	return (output);
}

void update_animated_sprite(animated_sprite_t *sprite)
{
	float time = sfTime_asSeconds(sfClock_getElapsedTime(sprite->clock));

	if (time >= sprite->next) {
		sfClock_restart(sprite->clock);
		sprite->current++;
		if (sprite->current >= sprite->limit)
			sprite->current = 0;
		sprite->rect.left = sprite->rect.width * sprite->current;
		sfSprite_setTextureRect(sprite->sprite, sprite->rect);
	}
}

void draw_animated_sprite(sfRenderWindow *window, animated_sprite_t *sprite)
{
	sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

void destroy_animated_sprite(animated_sprite_t *sprite)
{
	sfTexture_destroy(sprite->texture);
	sfSprite_destroy(sprite->sprite);
	sfClock_destroy(sprite->clock);
	free(sprite);
}
