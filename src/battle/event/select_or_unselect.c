/*
** EPITECH PROJECT, 2018
** select_or_unselect
** File description:
** rpg
*/

#include "rpg.h"

static void unselect_all(battle_t *battle, int i)
{
	i = battle->hero->pos.x + battle->hero->pos.y * 12;
	sfRectangleShape_setFillColor
		(battle->fight[battle->id]->map[i], sfBlack);
	battle->hero->select = false;
	for (int a = 0; a < 4; a++)
		battle->hero->spell[a]->select = false;
	reset_map_state(battle);
}

void select_or_unselect(battle_t *battle, int i)
{
	unselect_all(battle, i);
	if (battle->map[i / 12][i % 12] == 1)
		battle->hero->select = true;
}
