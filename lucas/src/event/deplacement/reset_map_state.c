/*
** EPITECH PROJECT, 2018
** reset_map_state
** File description:
** rpg
*/

#include "test.h"

void reset_map_state(data_t *data)
{
	int x;
	int y;
	int id = data->id;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 12; j++)
			data->map[i][j] = 0;
	for (int i = 0; i < data->fight[id]->number_enemy; i++) {
		x = data->fight[id]->enemy[i]->pos.x;
		y = data->fight[id]->enemy[i]->pos.y;
		data->map[y][x] = 2;
	}
	x = data->hero->pos.x;
	y = data->hero->pos.y;
	data->map[y][x] = 1;
	for (int i = 0; i < 120; i++)
		sfRectangleShape_setFillColor(data->fight
			[data->id]->map[i], sfBlack);
}
