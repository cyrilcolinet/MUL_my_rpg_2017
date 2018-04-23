/*
** EPITECH PROJECT, 2018
** hero_deplacement
** File description:
** RPG
*/

#include "test.h"

void hero_deplacement(data_t *data, int i, sfVector2f pos)
{
	if ((data->mouse.x > pos.x && data->mouse.x < pos.x + B_X) &&
	(data->mouse.y > pos.y && data->mouse.y < pos.y + B_Y))
		if (data->map[i / 12][i % 12] == 3) {
			data->hero->select = false;
			data->hero->pos.x = i % 12;
			data->hero->pos.y = i / 12;
			reset_map_state(data);
		}
}
