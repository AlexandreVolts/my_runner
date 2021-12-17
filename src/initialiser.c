/*
** EPITECH PROJECT, 2017
** initialiser.c
** File description:
** Initialiser
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "animated_sprite.h"
#include "defines.h"
#include "game.h"
#include "map_defines.h"
#include "prototypes.h"

game_t *init_game(char *filepath)
{
	game_t *output = malloc(sizeof(game_t));
	unsigned int time = 0;

	srand((long long)&time);
	output->window = create_window("My runner");
	output->map = datas_to_map(filepath);
	output->unity = HEIGHT / output->map->size.y;
	output->map->visible_blocs.x = (WIDTH / output->unity) + 1;
	output->layers = create_layer_array();
	output->game_sprites = init_sprites(output->unity);
	output->player = create_player(output->unity);
	init_game_informations(output);

	return (output);
}

void init_game_informations(game_t *game)
{
	char *musics[GAME_THEME_NBR] = {
		"./assets/sound/forest_theme.wav",
		"./assets/sound/level_complete.wav",
		"./assets/sound/game_over.wav"
	};
	char *pause_menu_textes[3] = {
		"Resume",
		"Restart",
		"Quit"
	};

	set_default_game_informations(game);
	game->textes = create_text_manager();
	game->mixer = create_mixer(musics, GAME_THEME_NBR);
	game->pause_menu = create_menu(pause_menu_textes);
	sfSound_setLoop(game->mixer->sounds[0]->sound, sfTrue);
}

void set_default_game_informations(game_t *game)
{
	game->has_started = 0;
	game->has_ended = 0;
	game->game_over = 0;
	game->paused = 0;
	game->score = 0;
}

animated_sprite_t **init_sprites(int unity)
{
	animated_sprite_t **output =
		malloc(sizeof(animated_sprite_t *) * PLATEFORM_NUMBER);
	float resizer = (float)unity / TEXTURE_SIZE;
	sfVector2f scale = {resizer, resizer};
	sfIntRect tmp_rect = {0, 0,
		TEXTURE_SIZE * PLATEFORM_WIDTH, TEXTURE_SIZE};
	char *path = "./assets/img/textures.png";

	for (int i = 0; i < PLATEFORM_NUMBER; i++) {
		if (i != RING_CHAR - '0')
			output[i] = create_animated_sprite(path, 1, 1,
				&tmp_rect);
		else
			output[i] = create_animated_sprite(path, 4, 0.1,
				&tmp_rect);
		tmp_rect.top += TEXTURE_SIZE;
		sfSprite_setScale(output[i]->sprite, scale);
	}

	return (output);
}
