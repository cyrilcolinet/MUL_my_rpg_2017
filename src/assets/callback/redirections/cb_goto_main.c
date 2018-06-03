/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** cb_goto_main function
*/

# include "rpg.h"

void cb_goto_main_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	destroy_battle(rpg);
	fill_struct_values(rpg);
	destroy_player(rpg);

	rpg->player = NULL;
	rpg->battle->hero = NULL;
	rpg->state = gameWait;
	rpg->last_st = gameUnknown;
	reset_to_normal_rect(rpg);
}
