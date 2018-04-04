/*
** EPITECH PROJECT, 2018
** fill_map_state
** File description:
** rpg
*/

#include "test.h"

void fill_map_state(data_t *data, int id)
{
	int x;
	int y;

	for (int i = 0; i < data->fight[id]->number_enemy; i++) {
		x = data->fight[id]->enemy[i]->pos.x;
		y = data->fight[id]->enemy[i]->pos.y;
		data->map[y][x] = 2;
	}
	x = data->hero->pos.x;
	y = data->hero->pos.y;
	data->map[y][x] = 1;
}
