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
	/* free_battle(rpg); */
	/* sfSprite_destroy(rpg->player->sprite); */
	/* configure_internal_struct(rpg); */
	/* rpg->state = gameWait; */
	/* rpg->last_st = gameUnknown; */
	/* reset_to_normal_rect(rpg); */
	cb_goto_main_view(rpg, NULL);
}
