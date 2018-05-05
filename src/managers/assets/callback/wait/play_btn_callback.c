/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** play_btn_callback function
*/

# include "rpg.h"

void btn_play_released(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	rpg->state = gameRun;
	rpg->last_st = gameUnknown;
	sfRenderWindow_setTitle(rpg->win, "My rpg");
	reset_to_normal_rect(rpg);
}
