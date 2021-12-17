/*
** EPITECH PROJECT, 2017
** sound.c
** File description:
** Sound management
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include "sound.h"
#include "mixer.h"
#include "prototypes.h"

mixer_t *create_mixer(char **paths, int size)
{
	mixer_t *output = malloc(sizeof(mixer_t));

	output->size = size;
	output->sounds = malloc(sizeof(sound_t *) * size);
	for (int i = 0; i < size; i++)
		output->sounds[i] = create_sound(paths[i]);

	return (output);
}

sound_t *create_sound(char *path)
{
	sound_t *output = malloc(sizeof(sound_t));

	output->sound = sfSound_create();
	output->buffer = sfSoundBuffer_createFromFile(path);
	sfSound_setBuffer(output->sound, output->buffer);

	return (output);
}

void destroy_sound(sound_t *sound)
{
	sfSound_destroy(sound->sound);
	sfSoundBuffer_destroy(sound->buffer);
	free(sound);
}

void destroy_mixer(mixer_t *mixer)
{
	for (int i = 0; i < mixer->size; i++) {
		destroy_sound(mixer->sounds[i]);
	}
	free(mixer->sounds);
	free(mixer);
}
