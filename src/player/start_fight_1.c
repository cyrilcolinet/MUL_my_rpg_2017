/*
** EPITECH PROJECT, 2018
** start_fight_1
** File description:
** rpg
*/

#include "rpg.h"

void start_fight_1(rpg_t *rpg, int id)
{
	rpg->battle->hero->rec.top = 192;
	rpg->battle->hero->rec.left = 0;
	rpg->battle->hero->pos.x = 0;
	rpg->battle->hero->pos.y = 5;
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;
	rpg->battle->run = true;
	rpg->battle->id = 0;
	sfSprite_setTextureRect(rpg->battle->hero->form,
				rpg->battle->hero->rec);
}
