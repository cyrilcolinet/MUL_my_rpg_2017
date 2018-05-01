/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** credits_btn_callback functions
*/

# include "cook.h"

void btn_credits_released(cook_t *cook, button_t *btn)
{
	(void)btn;

	info("Openning credits menu...");
	cook->last_st = cook->state;
	cook->state = gameOnCredits;
	reset_to_normal_rect(cook);
}
