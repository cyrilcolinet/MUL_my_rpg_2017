/*
** EPITECH PROJECT, 2018
** fill_map_state
** File description:
** rpg
*/

#include "battle.h"

void fill_map_state(battle_t *battle, int id)
{
	int x;
	int y;

	for (int i = 0; i < battle->fight[id]->number_enemy; i++) {
		if (battle->fight[id]->enemy[i]->alive) {
			x = battle->fight[id]->enemy[i]->pos.x;
			y = battle->fight[id]->enemy[i]->pos.y;
			battle->map[y][x] = 2;
		}
	}
	x = battle->hero->pos.x;
	y = battle->hero->pos.y;
	battle->map[y][x] = 1;
}
