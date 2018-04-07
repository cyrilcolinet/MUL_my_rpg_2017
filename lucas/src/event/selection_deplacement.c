/*
** EPITECH PROJECT, 2018
** selection_deplacement
** File description:
** rpg
*/

#include "test.h"

static void display_possible_case(data_t *data, int i, int j)
{
	int x = data->hero->pos.x;
	int y = data->hero->pos.y;

	if ((i != y || j != x) && (abs(i - y) < 4
	&& abs(j - x) < 4) && (abs(i - y) + abs(j - x) < 4)
	&& data->map[i][j] != 2) {
		if (data->hero->select) {
			sfRectangleShape_setFillColor(data->fight
				[data->id]->map[i * 12 + j], sfGreen);
			data->map[i][j] = 3;
		} else if (!data->hero->select && data->map[i][j] == 3) {
			sfRectangleShape_setFillColor(data->fight
				[data->id]->map[i * 12 + j], sfBlack);
			data->map[i][j] = 0;
		}
	}
}

static void check_deplacement(data_t *data)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 12; j++)
			display_possible_case(data, i, j);
}

static void select_or_unselect(data_t *data, int i)
{
	if (data->map[i / 12][i % 12] == 1) {
		sfRectangleShape_setFillColor
			(data->fight[data->id]->map[i], sfYellow);
		data->hero->select = true;
	} else {
		i = data->hero->pos.x + data->hero->pos.y * 12;
		sfRectangleShape_setFillColor
			(data->fight[data->id]->map[i], sfBlack);
		data->hero->select = false;
	}
	check_deplacement(data);
}

void selection_deplacement(data_t *data)
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

