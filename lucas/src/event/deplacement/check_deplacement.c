/*
** EPITECH PROJECT, 2018
** check_deplacement
** File description:
** rpg
*/

#include "test.h"

static void display_possible_case_hero(data_t *data, int i, int j)
{
	int x = data->hero->pos.x;
	int y = data->hero->pos.y;

	if ((i != y || j != x) && (abs(i - y) < 4
	&& abs(j - x) < 4) && (abs(i - y) + abs(j - x) < 4)
	&& data->map[i][j] != 2) {
		sfRectangleShape_setFillColor(data->fight
			[data->id]->map[i * 12 + j], sfGreen);
		data->map[i][j] = 3;
	}
}

static void display_possible_case_enemy(data_t *data, int i, int j, int a)
{
	int x = data->fight[data->id]->enemy[a]->pos.x;
	int y = data->fight[data->id]->enemy[a]->pos.y;

	if ((i != y || j != x) && (abs(i - y) < 4
	&& abs(j - x) < 4) && (abs(i - y) + abs(j - x) < 4)
	&& data->map[i][j] != 1 && data->map[i][j] != 2) {
		sfRectangleShape_setFillColor(data->fight
			[data->id]->map[i * 12 + j], sfGreen);
		data->map[i][j] = 3;
		data->hero->select = false;
	}
}

static void check_select(data_t *data, int i, int j)
{
	if (data->hero->select && !data->fight[data->id]->enemy_turn)
		display_possible_case_hero(data, i, j);
	for (int a = 0; a < data->fight[data->id]->number_enemy; a++) {
		if (data->fight[data->id]->enemy[a]->select
		&& !data->fight[data->id]->enemy[a]->played
		&& data->fight[data->id]->enemy_turn)
			display_possible_case_enemy(data, i, j, a);
	}
}

void check_deplacement(data_t *data)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			check_select(data, i , j);
		}
	}
}
