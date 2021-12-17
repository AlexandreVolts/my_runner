/*
** EPITECH PROJECT, 2017
** player_functions.c
** File description:
** Player functions
*/

#include <stdlib.h>
#include "defines.h"
#include "player_defines.h"
#include "player.h"
#include "prototypes.h"

player_t *create_player(int unity)
{
	player_t *output = malloc(sizeof(player_t));
	char *sounds[PLAYER_SOUND_NUMBER] = {
		"./assets/sound/jump.wav",
		"./assets/sound/death.wav",
		"./assets/sound/ring.wav"
	};

	init_player(output);
	create_visual_player_objects(output, unity);
	output->clock = sfClock_create();
	output->lifes = LIFES_NUMBER;
	output->state = PLAYER_RUNNING_STATE;
	output->mixer = create_mixer(sounds, PLAYER_SOUND_NUMBER);

	return (output);
}

void init_player(player_t *player)
{
	sfVector2f speed = {0, 0};
	int line_nbr = PLAYER_TEXTURES_NUMBER / PLAYER_TEXTURES_PER_LINE;

	player->position.x = WIDTH / PLAYER_SPAWN_X_RATIO;
	player->position.y = 0;
	player->size.x = PLAYER_TEXTURE_WIDTH / PLAYER_TEXTURES_PER_LINE;
	player->size.y = PLAYER_TEXTURE_HEIGHT / line_nbr;
	player->speed = speed;
	player->rings = 0;
	player->animation_state = PLAYER_RUNNING_STATE;
	player->jump_nbr = 0;
	player->is_dead = 0;
}

void create_visual_player_objects(player_t *player, int unity)
{
	char *path = "./assets/img/sonic.png";
	float resizer = (float)unity / player->size.x;
	sfVector2f scale = {resizer, resizer};
	sfIntRect rect = {0, 0, player->size.x, player->size.y};

	player->texture = sfTexture_createFromFile(path, NULL);
	player->sprite = sfSprite_create();
	sfSprite_setTexture(player->sprite, player->texture, sfTrue);
	sfSprite_setTextureRect(player->sprite, rect);
	sfSprite_setScale(player->sprite, scale);
}

int update_player(player_t *player)
{
	sfIntRect rect = {0, 0, player->size.x, player->size.y};
	float time = sfTime_asSeconds(sfClock_getElapsedTime(player->clock));
	int has_changed = 0;

	if (time >= TIME_BEFORE_NEXT_FRAME) {
		sfClock_restart(player->clock);
		rect.top = rect.height * player->state;
		update_animation_state(player);
		rect.left = rect.width * player->animation_state;
		sfSprite_setTextureRect(player->sprite, rect);
		has_changed = 1;
	}
	sfSprite_setPosition(player->sprite, player->position);

	return (has_changed);
}

void destroy_player(player_t *player)
{
	destroy_mixer(player->mixer);
	sfTexture_destroy(player->texture);
	sfSprite_destroy(player->sprite);
	sfClock_destroy(player->clock);
	free(player);
}
