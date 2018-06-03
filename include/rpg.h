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

typedef struct dirent dir_t;

# define 	READ_SIZE		(128)

// rpg.c
void 		exit_game(rpg_t *);
int 		rpg_game(rpg_t *);
int		rpg_main(int, char **);

/*
** Events manager
** Management of events (mouse, keyboard, etc...)
*/

void 		mouse_events(rpg_t *, sfEvent *);
void 		keyboard_events(rpg_t *, sfEvent *);
void 		poll_event(rpg_t *, sfEvent *);
void 		mouse_button_pressed(rpg_t *, sfMouseButtonEvent);
void 		mouse_button_released(rpg_t *, sfMouseButtonEvent);
void 		mouse_moved(rpg_t *, sfMouseMoveEvent);
void 		views_events(rpg_t *, sfEvent *);
void		event_player_interaction(rpg_t *, sfEvent *);

// events/selection
bool 		ev_selection_text(rpg_t *, sfEvent *);
void 		ev_run(rpg_t *, sfEvent *);
void 		ev_selection(rpg_t *, sfEvent *);
void 		ev_inventory(rpg_t *, sfEvent *);
void 		ev_skills(rpg_t *, sfEvent *);
void 		ev_quests(rpg_t *, sfEvent *);

/*
** Sounds manager
** Manage sounds, button click, and other noises
*/

int 		new_sound(rpg_t *, char *, char *);
void 		set_volume(rpg_t *, float, bool);
int 		load_sounds(rpg_t *);

/*
** Assets manager
** Manage buttons, sliders, views and menus
*/

int 		new_asset(rpg_t *, texture_t);
int		create_texture(rpg_t *, char *, char *);
int 		configure_assets(rpg_t *);
int 		load_assets(rpg_t *);
void 		configure_views(rpg_t *);
void 		start_loader(rpg_t *);
sfSprite	*get_sprite(rpg_t *, char *);
sfTexture	*get_texture(rpg_t *, char *);
slider_t 	*get_slider(rpg_t *, char *);
assets_t 	*get_asset(rpg_t *, char *);
sound_t 	*get_sound(rpg_t *, char *);
void 		callback_btn(button_t *, button_t);
void 		add_button(rpg_t *, button_t);
button_t	*is_button(rpg_t *, int, int);
void 		draw_buttons(rpg_t *);
button_t 	*get_button(rpg_t *, char *, state_e);
void 		add_slider(rpg_t *, slider_t);

/*
** Callbacks
* *Redirections and more
*/
void 		cb_goto_main_view(rpg_t *, button_t *);
void 		cb_goto_credits_view(rpg_t *, button_t *);
void 		cb_goto_play_view(rpg_t *, button_t *);
void 		cb_goto_settings_view(rpg_t *, button_t *);
void 		cb_goto_history_view(rpg_t *, button_t *);
void 		cb_goto_pause_view(rpg_t *, button_t *);
void 		cb_goto_select_view(rpg_t *, button_t *);
void 		cb_goto_loader_view(rpg_t *, button_t *);
void 		cb_goto_custom_view(rpg_t *, state_e);
void 		cb_quit_action(rpg_t *, button_t *);
void 		cb_return_action(rpg_t *, button_t *);
void 		cb_void_action(rpg_t *, button_t *);
void 		cb_click_action(rpg_t *, button_t *);
void 		cb_hover_action(rpg_t *, button_t *);
void 		cb_play_sound1(rpg_t *, button_t *);
void 		cb_slider_volume_music(rpg_t *, slider_t *);
void 		cb_load_save(rpg_t *, button_t *);

/*
** Configurations
** All configurations for sprites, audio, etc...
*/

void 		configure_views_actions(rpg_t *);
void 		configure_main_play_button(rpg_t *);
void 		configure_main_settings_button(rpg_t *);
void 		configure_main_credits_button(rpg_t *);
void 		configure_main_quit_button(rpg_t *);
void 		configure_main_history_button(rpg_t *);
void 		configure_pause_resume_button(rpg_t *);
void 		configure_pause_save_button(rpg_t *);
void 		configure_pause_settings_button(rpg_t *);
void 		configure_pause_quit_button(rpg_t *);
void 		configure_settings_volume_button(rpg_t *);
void 		configure_settings_volume_mute_music_button(rpg_t *);
void 		configure_settings_return_button(rpg_t *);
void 		configure_settings_fullscreen_button(rpg_t *);
void 		configure_settings_volume_slider(rpg_t *);
void 		configure_credits_return_button(rpg_t *);
void 		configure_history_return_button(rpg_t *);
void 		configure_select_male_button(rpg_t *);
void 		configure_select_female_button(rpg_t *);
void 		configure_select_return_button(rpg_t *);
void 		configure_select_play_button(rpg_t *);
void 		configure_play_pause_button(rpg_t *);
void 		configure_load_return_button(rpg_t *);
void 		configure_load_new_game_button(rpg_t *);

/*
** Views gesture
** Menu displaying with their actions etc...
*/

void 		pause_view(rpg_t *);
void 		credits_view(rpg_t *);
void 		settings_view(rpg_t *);
void 		history_view(rpg_t *);
void 		select_view(rpg_t *);
void 		game_load_view(rpg_t *);
void 		skills_view(rpg_t *);
void 		quests_view(rpg_t *);
void 		inventory_view(rpg_t *);

//quests_view.c
void		quests_view(rpg_t *);

//skills_view.c
void		skills_view(rpg_t *);

//inventory_view.c
void		inventory_view(rpg_t *);
void		draw_stat_player(rpg_t *, battle_t *);
void		draw_obj_stat(rpg_t *, inventory_t *);
void		draw_unequip_message(rpg_t *, inventory_t *);
char		*check_stat_hp_value(inventory_t *, battle_t *,
			equipement_t *);
char		*check_stat_dmg_value(inventory_t *, battle_t *,
			equipement_t *);
char		*check_stat_armor_value(inventory_t *, battle_t *,
			equipement_t *);
char 		*check_stat_magic_value(inventory_t *, battle_t *,
			equipement_t *, int);
void		equip_obj_management(rpg_t *, inventory_t *);
void		swap_armor_stat(rpg_t *, battle_t *, equipement_t *,
			inventory_t *);
void		swap_weapon_stat(rpg_t *, battle_t *, equipement_t *,
			inventory_t *);
void		unequip_weapon_stat(rpg_t *, battle_t *, inventory_t *,
			int);
void		unequip_armor_stat(rpg_t *, battle_t *, inventory_t *, int);
sfVector2f	find_free_slot(inventory_t *);

// play_view.c
void		player_deplacement(rpg_t *);
void		player_interaction(rpg_t *);
bool		check_valid_deplacement(rpg_t *, sfVector2f, int, int);
void		call_interaction(rpg_t *);
void		go_to_spawn(rpg_t *, int);
void		start_fight_2(rpg_t *, int);
void		start_fight_3(rpg_t *, int);
void		start_fight_1(rpg_t *, int);
void		talk_to_paysan(rpg_t *, int);
void		go_to_city(rpg_t *, int);
void		talk_to_totem(rpg_t *, int);
void		go_to_campagne(rpg_t *, int);
void		go_in_city(rpg_t *, int);
void		go_out_city(rpg_t *, int);
void		go_to_castle(rpg_t *, int);
void		talk_to_trader(rpg_t *, int);
void		talk_to_soldier(rpg_t *, int);
void		display_message(rpg_t *, int, int, quest_t *);

// main_view.c
void 		play_view(rpg_t *);
void 		animate_book_sprite(rpg_t *, assets_t *);
void 		draw_history_button(rpg_t *);
void 		main_view(rpg_t *);

/*
** Utilities
** Struct utils, pointers utils and more...
*/

char 		*get_next_line(int);
int 		check_arguments(int, char **);
void 		display_view(rpg_t *);
void 		reset_to_normal_rect(rpg_t *);
char 		*my_itoa(int);
char 		*get_sound_in_str(int);
void 		configure_audio(rpg_t *);
void 		destroy_buttons(rpg_t *);
void 		destroy_assets(rpg_t *);
void 		destroy_slides(rpg_t *);
void 		destroy_sounds(rpg_t *);
void 		destroy_map(rpg_t *);
void 		destroy_player(rpg_t *);
bool 		fill_struct_values(rpg_t *);
rpg_t 		*configure_struct(void);
void 		set_favicon(rpg_t *);
void 		extra_text_config(sfText *, sfFont *, int);
float 		get_slot_position(int);
void 		display_icon(rpg_t *, char *, int, int);

/*
** Parse utilities
** Parse config file
*/

conf_sett_t	parse_file(rpg_t *, char *, char *);
conf_sett_t	parse_save_file(rpg_t *, char *, char *);
bool		configure_fight(fight_t **);
void 		configure_enemy_texture(rpg_t *, enemy_t **, int, int);
void 		parse_enemy_values(rpg_t *, config_setting_t *, int, int);
void 		parse_fight_values(rpg_t *, config_setting_t *, int);
int		configure_battle_fights(rpg_t *);
void		parse_player(rpg_t *);
int 		configure_all_default(rpg_t *, hero_t **, char *);
int 		configure_battle_characters(rpg_t *);
int		**parse_map_hitboxes(char *);
int 		parse_arena_rectangle_values(config_setting_t *,
			interact_t **);
int		parse_arenas_values(map_t **, config_setting_t *);
int 		parse_map_values(rpg_t *, config_setting_t *, int);
int		parse_map(rpg_t *);
bool		save_loader(rpg_t *, int);
bool		player_parser(rpg_t *, char *);
void 		load_player_datas(config_setting_t *, rpg_t *);
void		load_player_inventory(rpg_t *);
void		load_player_equipment(rpg_t *, inventory_t *);
void 		load_hero_datas(config_setting_t *, rpg_t *);
void 		load_hero_spells_icons(rpg_t *);
bool 		default_player(rpg_t *);
void 		default_hero_datas(rpg_t *);
void 		load_player_quest(rpg_t *);

# endif
