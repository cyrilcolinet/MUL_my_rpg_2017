/*
** EPITECH PROJECT, 2018
** attack
** File description:
** rpg
*/

#include "test.h"

void attack(data_t *data, sfEvent event)
{
	int x = data->hero->pos.x;
	int y = data->hero->pos.y;

	if (data->hero->select) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 12; j++) {
				if ((i != y || j != x) && (abs(i - y) < 4
				&& abs(j - x) < 4) && (abs(i - y) + abs(j - x) < 4)
				&& data->map[i][j] == 2) {
					sfRectangleShape_setFillColor(data->fight
						[data->id]->map[i * 12 + j], sfRed);
				}
			}
		}
	}
}
