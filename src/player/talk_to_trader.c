/*
** EPITECH PROJECT, 2018
** talk_to_trader
** File description:
** rpg
*/

#include "rpg.h"

void talk_to_trader(rpg_t *rpg, int id)
{
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;

	if (rpg->player->quest->id == 2)
		rpg->player->quest->id++;
}
