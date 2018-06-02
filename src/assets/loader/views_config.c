/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** views_configuration functions
*/

# include "rpg.h"

void configure_views_actions(rpg_t *rpg)
{
	void (*tab[])(rpg_t *) = {
		configure_main_play_button, configure_main_settings_button,
		configure_main_credits_button, configure_main_quit_button,
		configure_main_history_button, configure_settings_volume_button,
		configure_settings_volume_mute_music_button,
		configure_settings_volume_slider,
		configure_settings_return_button,
		configure_settings_fullscreen_button,
		configure_credits_return_button,
		configure_history_return_button, configure_select_return_button,
		configure_select_play_button, configure_load_return_button,
		configure_load_new_game_button, configure_pause_resume_button,
		configure_pause_save_button, configure_pause_settings_button,
		configure_pause_quit_button, configure_play_pause_button, NULL
	};

	for (int i = 0; tab[i] != NULL; i++)
		tab[i](rpg);
}
