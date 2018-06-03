/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** skills events
*/

# include "rpg.h"

void ev_skills(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtKeyReleased) {
		if (event->key.code == sfKeyEscape)
			cb_goto_pause_view(rpg, NULL);
		if (event->key.code == sfKeyS)
			cb_goto_play_view(rpg, NULL);
	}
}
