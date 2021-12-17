/*
** EPITECH PROJECT, 2017
** mixer.c
** File description:
** Mixer STructure
*/

#ifndef MIXER_H_
#define MIXER_H_

#include "sound.h"

typedef struct mixer
{
	sound_t **sounds;
        int size;
} mixer_t;

#endif /* MIXER_H_ */
