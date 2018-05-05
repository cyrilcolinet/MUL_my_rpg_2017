/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** quit_btn_callback functions
*/

# include "rpg.h"

void btn_quit_released(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	sfRenderWindow_close(rpg->win);
}
