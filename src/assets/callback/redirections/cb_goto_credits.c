/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** cb_goto_credits functions
*/

# include "rpg.h"

void cb_goto_credits_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	rpg->last_st = rpg->state;
	rpg->state = gameOnCredits;
	reset_to_normal_rect(rpg);
}
