/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** return_callback functions
*/

# include "cook.h"

void btn_return_released(cook_t *cook, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(cook);
	cook->state = cook->last_st;
	cook->last_st = gameUnknown;
}
