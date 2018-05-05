/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** settings_btn_callback functions
*/

# include "rpg.h"

void btn_settings_released(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	info("Openning settings menu...");
	reset_to_normal_rect(rpg);
	rpg->last_st = rpg->state;
	rpg->state = gameOnSettings;
}
