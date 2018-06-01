/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** cb_goto_select function
*/

# include "rpg.h"

void cb_goto_select_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	rpg->last_st = rpg->state;
	rpg->state = gameSelect;
}
