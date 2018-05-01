/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** buttons_loader functions
*/

# include "cook.h"

void load_wait_buttons(cook_t *cook)
{
	setup_wait_play_btn(cook);
	setup_wait_settings_btn(cook);
	setup_wait_quit_btn(cook);
	setup_wait_credits_btn(cook);
}

void load_settings_buttons(cook_t *cook)
{
	setup_volume_settings_button(cook);
	setup_return_settings_button(cook);
}

void load_credits_buttons(cook_t *cook)
{
	setup_return_credits_button(cook);
}
