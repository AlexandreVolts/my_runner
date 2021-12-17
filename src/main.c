/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** ENtry point
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "game.h"
#include "defines.h"
#include "menu_defines.h"
#include "menu.h"
#include "prototypes.h"

sfRenderWindow *create_window(char *name)
{
	sfVideoMode mode = {WIDTH, HEIGHT, BITS_PER_PIXEL};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, name, sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, 65);

	return (window);
}

void render(game_t *game)
{
	char *names[MENU_BUTTONS_NUMBER] = {
		"Play", "Credits", "Quit"
	};
	menu_t *menu = create_menu(names);
	sfText **credits = create_credits(menu->font);
	sfColor blue = sfColor_fromRGB(0, 128, 255);

	while (sfRenderWindow_isOpen(game->window)) {
		manage_events(game, menu);
		sfRenderWindow_clear(game->window, blue);
		if (game->has_started == 0) {
			render_menu(game, menu);
			if (menu->is_off == 1
				&& menu->current == MENU_CREDIT_CODE)
				draw_credits(game->window, credits);
		}
		else
			render_game(game);
		sfRenderWindow_display(game->window);
	}
	destroy_all(menu, credits, game);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (84);

	if (av[1][0] == '-' && av[1][1] == 'h') {
		display_help();

		return (0);
	}

	game_t *game = init_game(av[1]);

	render(game);

	return (0);
}
