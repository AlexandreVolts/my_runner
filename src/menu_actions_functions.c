/*
** EPITECH PROJECT, 2018
** menu_actions_functions.c
** File description:
** Menu action management
*/

#include <SFML/Graphics.h>
#include "button.h"
#include "menu_defines.h"
#include "game.h"
#include "menu.h"
#include "prototypes.h"

void draw_menu(sfRenderWindow *window, menu_t *menu)
{
	button_t *current;
	sfVector2f selector_pos;

	selector_pos = sfSprite_getPosition(menu->selector->sprite);
	selector_pos.y = sfRectangleShape_getPosition(
		menu->buttons[menu->current]->shape).y;
	sfRenderWindow_drawRectangleShape(window, menu->background, NULL);
	for (int i = 0; i < menu->button_nbr; i++) {
		current = menu->buttons[i];
		if (i == menu->current)
			sfRectangleShape_setFillColor(current->shape,
				current->on_over_color);
		else
			sfRectangleShape_setFillColor(current->shape,
				current->background_color);
		draw_button(window, current);
	}
	update_animated_sprite(menu->selector);
	sfSprite_setPosition(menu->selector->sprite, selector_pos);
	draw_animated_sprite(window, menu->selector);
}

void update_menu_state(menu_t *menu, int move)
{
	menu->current += move;
	if (menu->current < 0)
		menu->current = menu->button_nbr - 1;
	if (menu->current >= menu->button_nbr)
		menu->current = 0;
	sfSound_play(menu->mixer->sounds[0]->sound);
}

void apply_pause_menu_action(game_t *game)
{
	switch (game->pause_menu->current) {
		case (PAUSE_MENU_RESUME_CODE):
		game->paused = 0;
		break;
		case (PAUSE_MENU_RESTART_CODE):
		restart_player(game);
		sfSound_play(game->mixer->sounds[0]->sound);
		break;
		case (MENU_QUIT_CODE):
		restart_player(game);
		set_default_game_informations(game);		 
		sfSound_stop(game->mixer->sounds[0]->sound);
		break;
	}
}

void apply_menu_action(game_t *game, int status)
{
	if (status == MENU_PLAY_CODE) {
		game->has_started = 1;
		sfSound_play(game->mixer->sounds[0]->sound);
	}
	if (status == MENU_QUIT_CODE)
		sfRenderWindow_close(game->window);
}
