/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** settings_btn_callback functions
*/

# include "cook.h"

void btn_settings_released(cook_t *cook, button_t *btn)
{
	(void)btn;

	info("Openning settings menu...");
	reset_to_normal_rect(cook);
	cook->last_st = cook->state;
	cook->state = gameOnSettings;
}
