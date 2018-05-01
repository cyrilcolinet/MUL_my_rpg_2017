/*
** EPITECH PROJECT, 2018
** enemy_deplacement
** File description:
** RPG
*/

#include "test.h"

void enemy_deplacement(data_t *data, int i, int x, sfVector2f pos)
{
	if ((data->mouse.x > pos.x && data->mouse.x < pos.x + B_X) &&
	(data->mouse.y > pos.y && data->mouse.y < pos.y + B_Y))
		if (data->map[i / 12][i % 12] == 3) {
			data->fight[data->id]->enemy[x]->select = false;
			data->fight[data->id]->enemy[x]->played = true;
			data->fight[data->id]->enemy[x]->pos.x = i % 12;
			data->fight[data->id]->enemy[x]->pos.y = i / 12;
			reset_map_state(data);
		}
}
