/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** cb_goto_play functions
*/

# include "rpg.h"

void cb_goto_play_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	if (my_strlen(rpg->player->name) <= 1 || rpg->player->sexe == 0) {
		cb_void_action(rpg, btn);
		return;
	}
	rpg->state = gameRun;
	rpg->last_st = gameUnknown;
}
