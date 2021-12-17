/*
** EPITECH PROJECT, 2017
** layer.h
** File description:
** Layer structure
*/

#ifndef LAYER_H_
#define LAYER_H_

#include <SFML/Graphics.h>

typedef struct layer
{
	sfVector2f position;
	sfTexture *texture;
	sfSprite *sprite;
	float speed;
} layer_t;

#endif /* LAYER_H_ */
