/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** inventory events
*/

# include "rpg.h"

static void mouse_coord(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtMouseMoved) {
		rpg->player->inventory->mouse.x = event->mouseMove.x;
		rpg->player->inventory->mouse.y = event->mouseMove.y;
	}
}

void ev_inventory(rpg_t *rpg, sfEvent *event)
{
	mouse_coord(rpg, event);
	if (event->type == sfEvtKeyReleased) {
		if (event->key.code == sfKeyEscape)
			cb_goto_pause_view(rpg, NULL);
		if (event->key.code == sfKeyI)
			cb_goto_play_view(rpg, NULL);
	}
}
