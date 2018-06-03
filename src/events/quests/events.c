/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** events quests
*/

# include "rpg.h"

void ev_quests(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtKeyReleased) {
		if (event->key.code == sfKeyEscape)
			cb_goto_pause_view(rpg, NULL);
		if (event->key.code == sfKeyQ)
			cb_goto_play_view(rpg, NULL);
		if (event->key.code == sfKeyM)
			rpg->player->quest->id++;
		if (event->key.code == sfKeyL)
			rpg->player->quest->id--;
	}
}
