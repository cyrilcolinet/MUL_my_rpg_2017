/*
** EPITECH PROJECT, 2018
** start_fight_3
** File description:
** rpg
*/

#include "rpg.h"

void start_fight_3(rpg_t *rpg, int id)
{
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;

	if (rpg->player->quest->id == 6) {
		rpg->battle->hero->rec.top = 128;
		rpg->battle->hero->rec.left = 0;
		rpg->battle->hero->pos.x = 7;
		rpg->battle->hero->pos.y = 0;
		rpg->battle->run = true;
		rpg->battle->id = 2;
		sfSprite_setTextureRect(rpg->battle->hero->form,
					rpg->battle->hero->rec);
	}
}
