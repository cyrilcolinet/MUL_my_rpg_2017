/*
** EPITECH PROJECT, 2018
** select_or_unselect
** File description:
** rpg
*/

#include "battle.h"

static void unselect_all(battle_t *battle, int i)
{
	i = battle->hero->pos.x + battle->hero->pos.y * 12;
	sfRectangleShape_setFillColor
		(battle->fight[battle->id]->map[i], sfBlack);
	battle->hero->select = false;
	for (int j = 0; j < battle->fight[battle->id]->number_enemy; j++) {
		i = battle->fight[battle->id]->enemy[j]->pos.x +
			battle->fight[battle->id]->enemy[j]->pos.y * 12;
		sfRectangleShape_setFillColor
			(battle->fight[battle->id]->map[i], sfBlack);
		battle->fight[battle->id]->enemy[j]->select = false;
	}
	reset_map_state(battle);
}

static void hero_selection(battle_t *battle, int i)
{
	sfRectangleShape_setFillColor
		(battle->fight[battle->id]->map[i], sfYellow);
	for (int j = 0; j < battle->fight[battle->id]->number_enemy; j++)
		battle->fight[battle->id]->enemy[j]->select = false;
	battle->hero->select = true;
}

void select_or_unselect(battle_t *battle, int i)
{
	unselect_all(battle, i);
	if (battle->map[i / 12][i % 12] == 1)
		hero_selection(battle, i);
}
