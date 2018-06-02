/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** inventory events
*/

# include "rpg.h"

void ev_inventory(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtKeyReleased) {
		if (event->key.code == sfKeyEscape)
			cb_goto_pause_view(rpg, NULL);
	}
}
