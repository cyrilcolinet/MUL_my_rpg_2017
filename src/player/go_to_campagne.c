/*
** EPITECH PROJECT, 2018
** go_to_campagne
** File description:
** rpg
*/

#include "rpg.h"

void go_to_campagne(rpg_t *rpg, int id)
{
	sfVector2f pos = {1824, 360};

	sfSprite_setPosition(rpg->player, pos);
	rpg->player_rect.top = 64;
	rpg->player_rect.left = 0;
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;
	rpg->map_id = 0;
}
