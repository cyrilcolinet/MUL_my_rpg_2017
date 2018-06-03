/*
** EPITECH PROJECT, 2018
** start_fight_2
** File description:
** rpg
*/

#include "rpg.h"

void start_fight_2(rpg_t *rpg, int id)
{
	if (rpg->player->quest->id == 4) {
		rpg->battle->hero->rec.top = 0;
		rpg->battle->hero->rec.left = 0;
		rpg->battle->hero->pos.x = 6;
		rpg->battle->hero->pos.y = 9;
		rpg->map[rpg->map_id]->it[id]->active = false;
		rpg->map[rpg->map_id]->it[id]->in_zone = false;
		rpg->battle->run = true;
		rpg->battle->id = 1;
		sfSprite_setTextureRect(rpg->battle->hero->form,
					rpg->battle->hero->rec);
	}
}
