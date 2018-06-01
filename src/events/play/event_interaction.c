/*
** EPITECH PROJECT, 2018
** event_interaction
** File description:
** rpg
*/

#include "rpg.h"

static void check_activation(rpg_t *rpg, int id, int i, sfEvent *event)
{
	if (rpg->map_id == 0 && i == 5) {
		rpg->map[id]->it[i]->active = true;
		return;
	}
	else if (rpg->map_id == 1 && i >= 0 && i <= 2) {
		rpg->map[id]->it[i]->active = true;
		return;
	}
	if (event->type == sfEvtKeyReleased)
		if (event->key.code == sfKeyE) {
			rpg->map[id]->it[i]->active = true;
		}
}

void event_player_interaction(rpg_t *rpg, sfEvent *event)
{
	for (int i = 0; rpg->map[rpg->map_id]->it[i]; i++)
		if (rpg->map[rpg->map_id]->it[i]->in_zone == true) {
			check_activation(rpg, rpg->map_id, i, event);
		}
}
