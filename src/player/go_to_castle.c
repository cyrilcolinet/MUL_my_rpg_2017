/*
** EPITECH PROJECT, 2018
** go_to_castle
** File description:
** rpg
*/

#include "rpg.h"

void go_to_castle(rpg_t *rpg, int id)
{
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;

	if (rpg->player->quest->id == 8) {
		cb_goto_main_view(rpg, NULL);
	}
}
