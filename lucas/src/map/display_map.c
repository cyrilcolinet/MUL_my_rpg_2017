/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** rpg
*/

#include "test.h"

void display_map(data_t *data, int id)
{
	for (int i = 0; i < 120; i++) {
		sfRenderWindow_drawRectangleShape
			(data->window, data->fight[id]->map[i], NULL);
	}
	for (int i = 0; i < data->fight[id]->number_enemy; i++) {
		sfRenderWindow_drawRectangleShape
			(data->window, data->fight[id]->enemy[i]->form, NULL);
	}
}
