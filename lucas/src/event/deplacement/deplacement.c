/*
** EPITECH PROJECT, 2018
** deplacement
** File description:
** rpg
*/

#include "test.h"

static void check_enemy_deplacement(data_t *data, int x, sfVector2f pos)
{
	for (int i = 0; i < 120; i++) {
		pos = sfRectangleShape_getPosition
			(data->fight[data->id]->map[i]);
		enemy_deplacement(data, i, x, pos);
	}
}

static void hero_turn(data_t *data)
{
	sfVector2f pos;

	if (data->hero->select) {
		for (int i = 0; i < 120; i++) {
			pos = sfRectangleShape_getPosition
				(data->fight[data->id]->map[i]);
			hero_deplacement(data, i, pos);
		}
	}
}

static void enemy_turn(data_t *data)
{
	sfVector2f pos;

	for (int i = 0; i < data->fight[data->id]->number_enemy; i++)
		if (data->fight[data->id]->enemy[i]->select
		&& !data->fight[data->id]->enemy[i]->played)
			check_enemy_deplacement(data, i, pos);
}

void deplacement(data_t *data)
{
	if (data->fight[data->id]->enemy_turn) {
		enemy_turn(data);
	} else
		hero_turn(data);
}
