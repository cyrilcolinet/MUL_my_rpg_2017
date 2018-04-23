/*
** EPITECH PROJECT, 2018
** display_interface
** File description:
** rpg
*/

#include "test.h"

void display_interface(data_t *data)
{
	sfVector2f pos;
	sfVector2f coord = sfText_getPosition(data->text);

	for (int i = 0; i < data->fight[data->id]->number_enemy; i++) {
		pos.x = coord.x;
		pos.y = i * 100 + coord.y;
		sfText_setPosition(data->text, pos);
		sfRenderWindow_drawText(data->window, data->text, NULL);
	}
	sfText_setPosition(data->text, coord);
}
