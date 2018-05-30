/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg functions (header file)
*/

# ifndef RPG_H
# define RPG_H

# include "my.h"
# include "structs.h"
# include "battle.h"

# define 	READ_SIZE		(128)

// Debug global variable
bool 		debug;

// rpg.c
void 		exit_game(rpg_t *);
int 		rpg_game(rpg_t *);
int		rpg_main(int, char **);

/*
** Events manager
** Management of events (mouse, keyboard, etc...)
*/

// events_manager.c
void 		mouse_events(rpg_t *, sfEvent *);
void 		keyboard_events(rpg_t *, sfEvent *);
void 		poll_event(rpg_t *, sfEvent *);

// events/mouse_events.c
void 		mouse_button_pressed(rpg_t *, sfMouseButtonEvent);
void 		mouse_button_released(rpg_t *, sfMouseButtonEvent);
void 		mouse_moved(rpg_t *, sfMouseMoveEvent);

// events/views_events.c
void 		views_events(rpg_t *, sfEvent *);

// events/play/events.c
void 		ev_run(rpg_t *, sfEvent *);
void 		player_deplacement(rpg_t *);
bool 		check_valid_deplacement(rpg_t *, sfVector2f, int, int);

// events/selection
bool 		ev_selection_text(rpg_t *, sfEvent *);
void 		ev_selection(rpg_t *, sfEvent *);

/*
** Sounds manager
** Manage sounds, button click, and other noises
*/

// sounds_manager.c
int 		new_sound(rpg_t *, char *, char *);
void 		set_volume(rpg_t *, float, bool);
int 		load_sounds(rpg_t *);

/*
** Assets manager
** Manage buttons, sliders, views and menus
*/

// assets_manager.c
int 		new_asset(rpg_t *, texture_t);
int		create_texture(rpg_t *, char *, char *);
int 		configure_assets(rpg_t *);
int 		load_assets(rpg_t *);

// assets_loader_manager.c
void 		configure_views(rpg_t *);
void 		start_loader(rpg_t *);

// assets/getter.c
sfSprite	*get_sprite(rpg_t *, char *);
sfTexture	*get_texture(rpg_t *, char *);
slider_t 	*get_slider(rpg_t *, char *);
assets_t 	*get_asset(rpg_t *, char *);
sound_t 	*get_sound(rpg_t *, char *);

// assets/button_manager.c
void 		callback_btn(button_t *, button_t);
void 		add_button(rpg_t *, button_t);
button_t	*is_button(rpg_t *, int, int);
void 		draw_buttons(rpg_t *);
button_t 	*get_button(rpg_t *, char *, state_e);

// assets/slider_manager.c
void 		add_slider(rpg_t *, slider_t);

// callback/goto_view_callback.c
void 		cb_goto_main_view(rpg_t *, button_t *);
void 		cb_goto_credits_view(rpg_t *, button_t *);
void 		cb_goto_play_view(rpg_t *, button_t *);
void 		cb_goto_settings_view(rpg_t *, button_t *);
void 		cb_goto_history_view(rpg_t *, button_t *);

// callback/goto_view_callback2.c
void 		cb_goto_pause_view(rpg_t *, button_t *);
void 		cb_goto_select_view(rpg_t *, button_t *);

// callback/actions_callback.c
void 		cb_quit_action(rpg_t *, button_t *);
void 		cb_return_action(rpg_t *, button_t *);
void 		cb_void_action(rpg_t *, button_t *);
void 		cb_click_action(rpg_t *, button_t *);
void 		cb_hover_action(rpg_t *, button_t *);

// callbacks/play_callback.c
void 		cb_play_sound1(rpg_t *, button_t *);

// callbacks/sliders/volume_callback.c
void 		cb_slider_volume_music(rpg_t *, slider_t *);

/*
** Configurations
** All configurations for sprites, audio, etc...
*/

// views_config.c
void 		configure_main_view(rpg_t *);
void 		configure_settings_view(rpg_t *);
void 		configure_credits_view(rpg_t *);
void 		configure_pause_view(rpg_t *);

// views/main/buttons.c
void 		configure_main_play_button(rpg_t *);
void 		configure_main_settings_button(rpg_t *);
void 		configure_main_credits_button(rpg_t *);
void 		configure_main_quit_button(rpg_t *);

// views/main/history_button.c
void 		configure_main_history_button(rpg_t *);

// views/pause/buttons.c
void 		configure_pause_resume_button(rpg_t *);
void 		configure_pause_save_button(rpg_t *);
void 		configure_pause_settings_button(rpg_t *);
void 		configure_pause_quit_button(rpg_t *);

// views/settings/buttons.c
void 		configure_settings_volume_button(rpg_t *);
void 		configure_settings_volume_mute_music_button(rpg_t *);
void 		configure_settings_return_button(rpg_t *);
void 		configure_settings_fullscreen_button(rpg_t *);

// views/settings/sliders.c
void 		configure_settings_volume_slider(rpg_t *);

// views/settings/buttons.c
void 		configure_credits_return_button(rpg_t *);

// views/history/buttons.c
void 		configure_history_return_button(rpg_t *);

// views/select/buttons.c
void 		configure_select_male_button(rpg_t *);
void 		configure_select_female_button(rpg_t *);
void 		configure_select_return_button(rpg_t *);
void 		configure_select_play_button(rpg_t *);

// views/play/buttons.c
void 		configure_play_pause_button(rpg_t *);

/*
** Views gesture
** Menu displaying with their actions etc...
*/

// menu_views.c
void 		pause_view(rpg_t *);
void 		credits_view(rpg_t *);
void 		settings_view(rpg_t *);
void 		history_view(rpg_t *);
void 		select_view(rpg_t *);

// play_view.c
void 		play_view(rpg_t *);

// main_view.c
void 		animate_book_sprite(rpg_t *, assets_t *);
void 		draw_history_button(rpg_t *);
void 		main_view(rpg_t *);

/*
** Utilities
** Struct utils, pointers utils and more...
*/

char 		*get_next_line(int);

// args_utils.c
int 		check_arguments(int, char **);

// debug_utils.c
void 		info(char *);
void 		warning(char *);
void 		print_key_value_str(char *, char *);
void 		print_key_value_int(char *, int);

// views_utils.c
void 		display_view(rpg_t *);

// rect_utils.c
void 		reset_to_normal_rect(rpg_t *);

// settings_utils.c
char 		*my_itoa(int);
char 		*get_sound_in_str(int);

// sound_utils.c
void 		configure_audio(rpg_t *);

// destroy_utils.c
void 		destroy_buttons(rpg_t *);
void 		destroy_assets(rpg_t *);
void 		destroy_slides(rpg_t *);
void 		destroy_sounds(rpg_t *);
void 		destroy_map(rpg_t *);

// struct_utils.c
void 		configure_textures(rpg_t *, battle_t *);
bool 		configure_internal_battle(rpg_t *);
bool 		configure_internal_struct(rpg_t *);
rpg_t 		*configure_struct(void);

// windows_tils.c
void 		set_favicon(rpg_t *);

/*
** Parse utilities
** Parse config file
*/

// parser.c
conf_sett_t	parse_file(rpg_t *, char *, char *);

// battle_fights_parser.c
bool		configure_fight(fight_t **);
void 		configure_enemy_texture(rpg_t *, enemy_t **, int, int);
void 		parse_enemy_values(rpg_t *, config_setting_t *, int, int);
void 		parse_fight_values(rpg_t *, config_setting_t *, int);
int		configure_battle_fights(rpg_t *);

// battle_character_parser.c
void		parse_player(rpg_t *);
int 		configure_all_default(rpg_t *, hero_t **, char *);
int 		configure_battle_characters(rpg_t *);

// map_parser.c
int		**parse_map_hitboxes(char *);
int 		parse_arena_rectangle_values(config_setting_t *, interact_t **);
int		parse_arenas_values(map_t **, config_setting_t *);
int 		parse_map_values(rpg_t *, config_setting_t *, int);
int		parse_map(rpg_t *);

# endif
