/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** return_callback functions
*/

# include "rpg.h"

void btn_return_released(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	rpg->state = rpg->last_st;
	rpg->last_st = gameUnknown;
}
