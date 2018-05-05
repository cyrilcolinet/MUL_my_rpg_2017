/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** buttons_loader functions
*/

# include "rpg.h"

void load_wait_buttons(rpg_t *rpg)
{
	setup_wait_play_btn(rpg);
	setup_wait_settings_btn(rpg);
	setup_wait_quit_btn(rpg);
	setup_wait_credits_btn(rpg);
}

void load_settings_buttons(rpg_t *rpg)
{
	setup_volume_settings_button(rpg);
	setup_return_settings_button(rpg);
	setup_fullscreen_settings_button(rpg);
}

void load_credits_buttons(rpg_t *rpg)
{
	setup_return_credits_button(rpg);
}
