/*
** EPITECH PROJECT, 2018
** go_in_city
** File description:
** rpg
*/

#include "rpg.h"

void go_in_city(rpg_t *rpg, int id)
{
	sfVector2f pos = {1208, 360};

	sfSprite_setPosition(rpg->player, pos);
	rpg->player_rect.top = 192;
	rpg->player_rect.left = 0;
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;
}
