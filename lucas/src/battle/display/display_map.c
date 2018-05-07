/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** rpg
*/

#include "battle.h"

void display_map(data_t *data, battle_t *battle, int id)
{
	sfVector2f pos;

	if (battle->hero->select) {
		for (int i = 0; i < 120; i++) {
			sfRenderWindow_drawRectangleShape
				(data->window, battle->fight[id]->map[i], NULL);
		}
	}
	for (int i = 0; i < battle->fight[id]->number_enemy; i++) {
		pos.x = MAP_X + battle->fight[id]->enemy[i]->pos.x * B_X + 35;
		pos.y = MAP_Y + battle->fight[id]->enemy[i]->pos.y * B_Y + 5;
		sfRectangleShape_setPosition
			(battle->fight[id]->enemy[i]->form, pos);
		sfRenderWindow_drawRectangleShape
			(data->window, battle->fight[id]->enemy[i]->form, NULL);
	}
	pos.x = MAP_X + battle->hero->pos.x * B_X + 35;
	pos.y = MAP_Y + battle->hero->pos.y * B_Y + 5;
	sfRectangleShape_setPosition(battle->hero->form, pos);
	sfRenderWindow_drawRectangleShape
		(data->window, battle->hero->form, NULL);
}
