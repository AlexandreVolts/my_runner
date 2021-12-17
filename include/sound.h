/*
** EPITECH PROJECT, 2017
** sound.h
** File description:
** Sound structure
*/

#ifndef SOUND_H_
#define SOUND_H_

#include <SFML/Audio.h>

typedef struct sound
{
	sfSound *sound;
	sfSoundBuffer *buffer;
} sound_t;

#endif /* SOUND_H_ */
