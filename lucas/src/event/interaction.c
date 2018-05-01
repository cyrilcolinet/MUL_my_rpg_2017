/*
** EPITECH PROJECT, 2018
** interaction
** File description:
** rpg
*/

#include "test.h"

static void right_click(data_t *data)
{
	deplacement(data);
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

static void change_turn(data_t *data)
{
	int n = 0;

	if (!data->fight[data->id]->enemy_turn && !data->hero->played && data->hero->move)
		data->hero->played = true;
	if (data->hero->played && !data->fight[data->id]->enemy_turn) {
		for (int i = 0; i < data->fight[data->id]->number_enemy; i++)
			data->fight[data->id]->enemy[i]->played = false;
		data->fight[data->id]->enemy_turn = true;
	}
	if (data->fight[data->id]->enemy_turn) {
		for (int i = 0; i < data->fight[data->id]->number_enemy; i++) {
			if (data->fight[data->id]->enemy[i]->played)
				n++;
		}
		if (n == data->fight[data->id]->number_enemy) {
			data->hero->move = false;
			data->hero->played = false;
			data->hero->attack = false;
			data->fight[data->id]->enemy_turn = false;
		}
	}
}

void interaction(data_t *data, sfEvent event)
{
	if (event.type == sfEvtKeyPressed) {
	}

	if (event.type == sfEvtMouseButtonPressed) {
		if (event.mouseButton.button == sfMouseLeft)
			left_click(data);
		if (event.mouseButton.button == sfMouseRight)
			right_click(data);
	}
	check_deplacement(data);
	attack(data, event);
	change_turn(data);
}
