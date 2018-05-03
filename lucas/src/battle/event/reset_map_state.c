/*
** EPITECH PROJECT, 2018
** reset_map_state
** File description:
** rpg
*/

#include "battle.h"

void reset_map_state(battle_t *battle)
{
	int x;
	int y;
	int id = battle->id;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 12; j++)
			battle->map[i][j] = 0;
	for (int i = 0; i < battle->fight[id]->number_enemy; i++) {
		x = battle->fight[id]->enemy[i]->pos.x;
		y = battle->fight[id]->enemy[i]->pos.y;
		battle->map[y][x] = 2;
	}
	x = battle->hero->pos.x;
	y = battle->hero->pos.y;
	battle->map[y][x] = 1;
	for (int i = 0; i < 120; i++)
		sfRectangleShape_setFillColor(battle->fight
			[battle->id]->map[i], sfTransparent);
}
