/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** cb_goto_custom functions
*/

# include "rpg.h"

void cb_goto_custom_view(rpg_t *rpg, state_e state)
{
	reset_to_normal_rect(rpg);
	rpg->last_st = rpg->state;
	rpg->state = state;
}
