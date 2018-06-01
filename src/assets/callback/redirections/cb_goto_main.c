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

	/*if (rpg->state == gamePause) {
		free_battle(rpg);
		sfSprite_destroy(rpg->player->sprite);
		configure_internal_struct(rpg);
		//configure_battle_characters(rpg);
		//init_icone_spell(rpg->battle);
		//parse_player(rpg);
	}*/
	// TODO: Reparser 

	rpg->state = gameWait;
	rpg->last_st = gameUnknown;
	reset_to_normal_rect(rpg);
}
