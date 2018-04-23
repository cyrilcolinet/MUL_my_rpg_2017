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

static void right_click(data_t *data)
{
	sfVector2f pos;

	if (data->hero->select) {
		for (int i = 0; i < 120; i++) {
			pos = sfRectangleShape_getPosition
				(data->fight[data->id]->map[i]);
			hero_deplacement(data, i, pos);
		}
	}
	for (int i = 0; i < data->fight[data->id]->number_enemy; i++)
		if (data->fight[data->id]->enemy[i]->select)
			check_enemy_deplacement(data, i, pos);
}

static void left_click(data_t *data)
{
	sfVector2f pos;

	for (int i = 0; i < 120; i++) {
		pos = sfRectangleShape_getPosition
			(data->fight[data->id]->map[i]);
		if ((data->mouse.x > pos.x && data->mouse.x < pos.x + B_X) &&
		(data->mouse.y > pos.y && data->mouse.y < pos.y + B_Y))
			select_or_unselect(data, i);
	}
}

void deplacement(data_t *data, sfEvent event)
{
	if (event.type == sfEvtKeyPressed) {
	}

	if (event.type == sfEvtMouseButtonPressed) {
		if (event.mouseButton.button == sfMouseLeft)
			left_click(data);
		if (event.mouseButton.button == sfMouseRight)
			right_click(data);
	}
}
