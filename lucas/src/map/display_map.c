/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** rpg
*/

#include "test.h"

void display_map(data_t *data, int id)
{
	sfVector2f pos;

	for (int i = 0; i < 120; i++) {
		sfRenderWindow_drawRectangleShape
			(data->window, data->fight[id]->map[i], NULL);
	}
	for (int i = 0; i < data->fight[id]->number_enemy; i++) {
		pos.x = MAP_X + data->fight[id]->enemy[i]->pos.x * B_X + 35;
		pos.y = MAP_Y + data->fight[id]->enemy[i]->pos.y * B_Y + 5;
		sfRectangleShape_setPosition(data->fight[id]->enemy[i]->form, pos);
		sfRenderWindow_drawRectangleShape
			(data->window, data->fight[id]->enemy[i]->form, NULL);
	}
	pos.x = MAP_X + data->hero->pos.x * B_X + 35;
	pos.y = MAP_Y + data->hero->pos.y * B_Y + 5;
	sfRectangleShape_setPosition(data->hero->form, pos);
	sfRenderWindow_drawRectangleShape
		(data->window, data->hero->form, NULL);
}
