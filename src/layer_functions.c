/*
** EPITECH PROJECT, 2017
** layer_functions.c
** File description:
** Layer functions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "defines.h"
#include "layer.h"
#include "prototypes.h"

layer_t *create_layer(char *filepath, float speed)
{
	layer_t *output = malloc(sizeof(layer_t));
	sfVector2f scale = {(float)WIDTH / LAYER_WIDTH, 1};
	sfVector2f position = {0, HEIGHT - LAYER_HEIGHT};

	output->position = position;
	output->texture = sfTexture_createFromFile(filepath, NULL);
	output->sprite = sfSprite_create();
	sfSprite_setPosition(output->sprite, position);
	sfSprite_setTexture(output->sprite, output->texture, sfTrue);
	sfSprite_setScale(output->sprite, scale);
	output->speed = speed - 0.5;

	return (output);
}

layer_t **create_layer_array(void)
{
	layer_t **output = malloc(sizeof(layer_t *) * LAYER_NUMBER);
	char *assets[LAYER_NUMBER] = {
		"./assets/img/forest_background.png",
		"./assets/img/tree_background.png",
		"./assets/img/light_background.png",
		"./assets/img/trees.png",
		"./assets/img/tree_foreground.png",
		"./assets/img/forest_foreground.png",
		"./assets/img/light_foreground.png",
		"./assets/img/leaf.png",
		"./assets/img/ground.png",
		"./assets/img/foreground.png"
	};

	for (int i = 0; i < LAYER_NUMBER; i++)
		output[i] = create_layer(assets[i], - ((i + 1) * LAYER_SPEED));

	return (output);
}

void move_layer(layer_t *layer)
{
	layer->position.x += layer->speed;
	if (layer->position.x <= - WIDTH)
		layer->position.x = 0;
}

void draw_layer(sfRenderWindow *window, layer_t *layer)
{
	sfSprite_setPosition(layer->sprite, layer->position);
	sfRenderWindow_drawSprite(window, layer->sprite, NULL);
	layer->position.x += WIDTH;
	sfSprite_setPosition(layer->sprite, layer->position);
	sfRenderWindow_drawSprite(window, layer->sprite, NULL);
	layer->position.x -= WIDTH;
}

void destroy_layers(layer_t **layers)
{
	for (int i = 0; i < LAYER_NUMBER; i++) {
		sfTexture_destroy(layers[i]->texture);
		sfSprite_destroy(layers[i]->sprite);
		free(layers[i]);
	}
	free(layers);
}
