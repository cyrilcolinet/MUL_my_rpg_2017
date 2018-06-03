/*
** EPITECH PROJECT, 2018
** go_to_spawn
** File description:
** rpg
*/

#include "rpg.h"

void go_to_spawn(rpg_t *rpg, int id)
{
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;
	cb_goto_main_view(rpg, NULL);
}
