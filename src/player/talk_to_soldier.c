/*
** EPITECH PROJECT, 2018
** talk_to_soldier
** File description:
** rpg
*/

#include "rpg.h"

void talk_to_soldier(rpg_t *rpg, int id)
{
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;

	if (rpg->player->quest->id == 3
	|| rpg->player->quest->id == 5 || rpg->player->quest->id == 7)
		rpg->player->quest->id++;
}
