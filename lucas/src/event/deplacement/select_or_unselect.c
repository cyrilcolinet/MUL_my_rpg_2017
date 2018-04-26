/*
** EPITECH PROJECT, 2018
** select_or_unselect
** File description:
** rpg
*/

#include "test.h"

static void unselect_all(data_t *data, int i)
{
	i = data->hero->pos.x + data->hero->pos.y * 12;
	sfRectangleShape_setFillColor
		(data->fight[data->id]->map[i], sfBlack);
	data->hero->select = false;
	for (int j = 0; j < data->fight[data->id]->number_enemy; j++) {
		i = data->fight[data->id]->enemy[j]->pos.x +
			data->fight[data->id]->enemy[j]->pos.y * 12;
		sfRectangleShape_setFillColor
			(data->fight[data->id]->map[i], sfBlack);
		data->fight[data->id]->enemy[j]->select = false;
	}
	reset_map_state(data);
}

static void hero_selection(data_t *data, int i)
{
	sfRectangleShape_setFillColor
		(data->fight[data->id]->map[i], sfYellow);
	for (int j = 0; j < data->fight[data->id]->number_enemy; j++)
		data->fight[data->id]->enemy[j]->select = false;
	data->hero->select = true;
}

static void enemy_selection(data_t *data, int i)
{
	for (int j = 0; j < data->fight[data->id]->number_enemy; j++) {
		if (data->fight[data->id]->enemy[j]->pos.x == i % 12
		&& data->fight[data->id]->enemy[j]->pos.y == i / 12) {
			data->fight[data->id]->enemy[j]->select = true;
			sfRectangleShape_setFillColor
				(data->fight[data->id]->map[i], sfYellow);
		} else {
			data->fight[data->id]->enemy[j]->select = false;
		}
	}
	data->hero->select = false;
}

void select_or_unselect(data_t *data, int i)
{
	unselect_all(data, i);
	if (data->map[i / 12][i % 12] == 1)
		hero_selection(data, i);
	else if (data->map[i / 12][i % 12] == 2)
		enemy_selection(data, i);
	check_deplacement(data);
}
