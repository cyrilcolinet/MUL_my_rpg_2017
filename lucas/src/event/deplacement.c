/*
** EPITECH PROJECT, 2018
** deplacement
** File description:
** rpg
*/

#include "test.h"

static void go_up(data_t *data)
{
	int x = data->hero->pos.x;
	int y = data->hero->pos.y;

	if (y - 1 >= 0 && data->map[y - 1][x] == 0) {
		data->map[y][x] = 0;
		data->map[y - 1][x] = 1;
		data->hero->pos.y -= 1;
	}
}

static void go_down(data_t *data)
{
	int x = data->hero->pos.x;
	int y = data->hero->pos.y;

	if (y + 1 <= 9 && data->map[y + 1][x] == 0) {
		data->map[y][x] = 0;
		data->map[y + 1][x] = 1;
		data->hero->pos.y += 1;
	}
}

static void go_left(data_t *data)
{
	int x = data->hero->pos.x;
	int y = data->hero->pos.y;

	if (x - 1 >= 0 && data->map[y][x - 1] == 0) {
		data->map[y][x] = 0;
		data->map[y][x - 1] = 1;
		data->hero->pos.x -= 1;
	}
}

static void go_right(data_t *data)
{
	int x = data->hero->pos.x;
	int y = data->hero->pos.y;

	if (x + 1 <= 11 && data->map[y][x + 1] == 0) {
		data->map[y][x] = 0;
		data->map[y][x + 1] = 1;
		data->hero->pos.x += 1;
	}
}

void deplacement(data_t *data, sfEvent event)
{
	if (event.type == sfEvtKeyPressed) {
		if (event.key.code == sfKeyUp)
			go_up(data);
		if (event.key.code == sfKeyDown)
			go_down(data);
		if (event.key.code == sfKeyLeft)
			go_left(data);
		if (event.key.code == sfKeyRight)
			go_right(data);
	}
}
