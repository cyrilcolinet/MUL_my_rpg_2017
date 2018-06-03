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
	char *texture = NULL;

	reset_to_normal_rect(rpg);
	if (my_strlen(rpg->player->name) <= 1 || rpg->player->sexe == 0) {
		cb_void_action(rpg, btn);
		return;
	}

	if (rpg->state == gameSelect) {
		texture = ((rpg->player->sexe == 1) ? "man_nu_no" :
		"women_nu_no");
		rpg->player->texture = get_texture(rpg, texture);
		sfSprite_setTexture(rpg->player->sprite, rpg->player->texture,
			true);
	}
	rpg->state = gameRun;
	rpg->last_st = gameUnknown;
}
