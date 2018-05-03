/*
** EPITECH PROJECT, 2018
** check_deplacement
** File description:
** rpg
*/

#include "battle.h"

static void display_possible_case_hero(battle_t *battle, int i, int j)
{
	int x = battle->hero->pos.x;
	int y = battle->hero->pos.y;

	if ((i != y || j != x) && (abs(i - y) < 4
	&& abs(j - x) < 4) && (abs(i - y) + abs(j - x) < 4)
	&& battle->map[i][j] != 2) {
		sfRectangleShape_setFillColor(battle->fight
			[battle->id]->map[i * 12 + j], sfGreen);
		battle->map[i][j] = 3;
	}
}

static void check_select(battle_t *battle, int i, int j)
{
	if (battle->hero->select && !battle->fight[battle->id]->enemy_turn)
		display_possible_case_hero(battle, i, j);
}

void check_deplacement(battle_t *battle)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			check_select(battle, i , j);
		}
	}
}
