/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** play_btn_callback function
*/

# include "cook.h"

void btn_play_released(cook_t *cook, button_t *btn)
{
	(void)btn;

	cook->state = gameRun;
	cook->last_st = gameUnknown;
	sfRenderWindow_setTitle(cook->win, "My Cook");
	reset_to_normal_rect(cook);
}
