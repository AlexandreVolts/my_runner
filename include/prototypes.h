/*
** EPITECH PROJECT, 2017
** prototypes.h
** File description:
** Prototypes of all functions
*/

#include <SFML/Graphics.h>
#include <dirent.h>
#include "animated_sprite.h"
#include "game.h"
#include "layer.h"
#include "menu.h"
#include "mixer.h"
#include "sound.h"
#include "text_manager.h"

sfRenderWindow *create_window(char *name);
void manage_events(game_t *game, menu_t *menu);
void update_menu_display(game_t *game, menu_t *menu, sfKeyEvent event);
void on_key_pressed(game_t *game, sfKeyEvent event);
void on_game_play(game_t *game);
void on_game_pause(game_t *game, sfKeyEvent event);
void render(game_t *game);
game_t *init_game(char *filepath);
map_t *datas_to_map(char *filepath);
char get_char_at(map_t *map, int x, int y);
void set_char_at(map_t *map, int x, int y, char c);
void modify_map_content(map_t *map);
menu_t *create_file_explorer_menu(void);
char **get_valid_files(int file_nbr, DIR *dir);
int is_file(char const *filepath);
void set_default_game_informations(game_t *game);
animated_sprite_t *create_animated_sprite(char *path, int limit, float next, sfIntRect *bounds);
menu_t *create_menu(char **names);
void create_menu_buttons(menu_t *menu, char **buttons_name, int rows, int cols);
sfText *create_text(char *text, sfFont *font, int centered);
sfText **create_credits(sfFont *font);
button_t *create_button(sfVector2f dimentions, sfText *text, int id);
layer_t *create_layer(char *filepath, float speed);
layer_t **create_layer_array(void);
player_t *create_player(int unity);
void create_visual_player_objects(player_t *player, int unity);
mixer_t *create_mixer(char **paths, int size);
sound_t *create_sound(char *path);
text_manager_t *create_text_manager(void);
void set_text_manager_properties(sfText *text, int id);
animated_sprite_t **init_sprites(int unity);
void init_player(player_t *player);
void init_menu(menu_t *menu);
void update_menu_state(menu_t *menu, int move);
void init_game_informations(game_t *game);
void update_animated_sprite(animated_sprite_t *sprite);
void update_animation_state(player_t *player);
int update_player(player_t *player);
void render_menu(game_t *game, menu_t *menu);
void render_game(game_t *game);
void render_game_elements(game_t *game);
void manage_game_state(game_t *game);
void move_layer(layer_t *layer);
void move_map(game_t *game);
void draw_animated_sprite(sfRenderWindow *window, animated_sprite_t *sprite);
void draw_menu(sfRenderWindow *window, menu_t *menu);
void draw_button(sfRenderWindow *window, button_t *button);
void draw_credits(sfRenderWindow *window, sfText **credits);
void draw_layer(sfRenderWindow *window, layer_t *layer);
void draw_map(game_t *game);
void draw_map_sprite(game_t *game, int x, int y);
void draw_textes(sfRenderWindow *window, text_manager_t *textes);
sfVector2i get_player_position(game_t *game);
int check_collision_with_ground(game_t *game);
int check_collision_with_wall(game_t *game);
int check_collisions_with_top(game_t *game);
void apply_collision_with_wall(game_t *game, sfVector2i pos);
void apply_bottom_collision(game_t *game, sfVector2i pos);
void apply_top_collision(game_t *game, sfVector2i pos);
void apply_collisions(game_t *game);
void apply_physics(game_t *game);
void apply_jump_physics(player_t *player, int unity);
void apply_menu_action(game_t *game, int status);
void apply_pause_menu_action(game_t *game);
void on_spike_touched(player_t *player);
void on_ground_collision(player_t *player, int top);
void on_top_collision(player_t *player);
void on_ring_touched(game_t *game, sfVector2i pos);
void on_player_death(game_t *game);
void listen_player_state(game_t *game);
void listen_game_over(game_t *game);
void listen_map_ended(game_t *game);
void reanimate_player(game_t *game);
void restart_player(game_t *game);
void move_textes_when_level_cleared(text_manager_t *textes);
void cat_text_with_int(sfText *text, char *value, int nbr);
void destroy_all(menu_t *menu, sfText **text, game_t *game);
void destroy_animated_sprite(animated_sprite_t *sprite);
void destroy_game(game_t *game);
void destroy_menu(menu_t *menu);
void destroy_button(button_t *button);
void destroy_credits(sfText **credits);
void destroy_game_elements(game_t *game);
void destroy_layers(layer_t **layers);
void destroy_player(player_t *player);
void destroy_sound(sound_t *sound);
void destroy_text_manager(text_manager_t *textes);
void destroy_mixer(mixer_t *mixer);
void display_help(void);
