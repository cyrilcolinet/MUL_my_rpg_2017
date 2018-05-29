/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** events for play menu
*/

# include "rpg.h"

void ev_run(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtKeyReleased && event->key.code == sfKeyEscape)
		cb_goto_pause_view(rpg, NULL);
	if (rpg->battle->run)
		battle_event_management(rpg, rpg->battle, event);
	else if (!rpg->battle->run) {
		if (event->type == sfEvtKeyReleased && event->key.code == sfKeyA)
			rpg->battle->run = true;
	}
}
