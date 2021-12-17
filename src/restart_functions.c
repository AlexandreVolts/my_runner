/*
** EPITECH PROJECT, 2018
** restart_functions.c
** File description:
** Restart functions
*/

#include "game.h"
#include "prototypes.h"

void restart_player(game_t *game)
{
	reanimate_player(game);
	game->player->lifes = 3;
	sfText_setString(game->textes->lifes, "Lifes\t3");
}
