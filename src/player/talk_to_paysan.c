/*
** EPITECH PROJECT, 2018
** talk_to_paysan
** File description:
** rpg
*/

#include "rpg.h"

void talk_to_paysan(rpg_t *rpg, int id)
{
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;

	if (rpg->player->quest->id == 0) {
		rpg->player->quest->id++;
		rpg->player->level++;
	}
}
