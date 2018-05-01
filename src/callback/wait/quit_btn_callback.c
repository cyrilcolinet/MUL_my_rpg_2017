/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** quit_btn_callback functions
*/

# include "cook.h"

void btn_quit_released(cook_t *cook, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(cook);
	sfRenderWindow_close(cook->win);
}
