/*
** EPITECH PROJECT, 2018
** deplacement
** File description:
** rpg
*/

#include "test.h"

static void clear_map_state(data_t *data)
{
	int x;
	int y;
	int id = data->id;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			data->map[i][j] = 0;
	for (int i = 0; i < data->fight[id]->number_enemy; i++) {
		x = data->fight[id]->enemy[i]->pos.x;
		y = data->fight[id]->enemy[i]->pos.y;
		data->map[y][x] = 2;
	}
	x = data->hero->pos.x;
	y = data->hero->pos.y;
	data->map[y][x] = 1;
	for (int i = 0; i < 120; i++)
		sfRectangleShape_setFillColor(data->fight
			[data->id]->map[i], sfBlack);
}

static void move_hero(data_t *data, int i, sfVector2f pos)
{
	if ((data->mouse.x > pos.x && data->mouse.x < pos.x + B_X) &&
	(data->mouse.y > pos.y && data->mouse.y < pos.y + B_Y))
		if (data->map[i / 12][i % 12] == 3) {
			data->hero->select = false;
			data->hero->pos.x = i % 12;
			data->hero->pos.y = i / 12;
			clear_map_state(data);
		}
}

static void deplacement_hero(data_t *data)
{
	sfVector2f pos;

	if (data->hero->select) {
		for (int i = 0; i < 120; i++) {
			pos = sfRectangleShape_getPosition
				(data->fight[data->id]->map[i]);
			move_hero(data, i, pos);
		}
	}
}

void deplacement(data_t *data, sfEvent event)
{
	if (event.type == sfEvtKeyPressed) {
	}

	if (event.type == sfEvtMouseButtonPressed) {
		if (event.mouseButton.button == sfMouseLeft)
			selection_deplacement(data);
		if (data->hero->select &&
		event.mouseButton.button == sfMouseRight)
			deplacement_hero(data);
	}
}
