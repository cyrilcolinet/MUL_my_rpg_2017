/*
** EPITECH PROJECT, 2018
** display_current_target
** File description:
** rpg
*/

#include "test.h"

static bool is_in_form(data_t *data, sfVector2f pos, sfVector2f size)
{
	int x = data->mouse.x;
	int y = data->mouse.y;

	if ((x >= pos.x && x <= pos.x + size.x)
	&& (y >= pos.y && y <= pos.y + size.y))
		return (true);
	return (false);
}

static bool is_enemy_form(data_t *data, sfVector2f pos,
		sfVector2f size, int i)
{
	pos = sfRectangleShape_getPosition(
		data->fight[data->id]->enemy[i]->form);
	size = sfRectangleShape_getSize(
		data->fight[data->id]->enemy[i]->form);
	if (is_in_form(data, pos, size))
		return (true);
	return (false);
}

static bool is_enemy_frame(data_t *data, sfVector2f pos,
		sfVector2f size, int i)
{
	pos = sfRectangleShape_getPosition(
		data->fight[data->id]->enemy[i]->frame);
	size = sfRectangleShape_getSize(
		data->fight[data->id]->enemy[i]->frame);
	if (is_in_form(data, pos, size))
		return (true);
	return (false);
}

void display_current_target(data_t *data)
{
	sfVector2f pos;
	sfVector2f size;

	for (int i = 0; i < data->fight[data->id]->number_enemy; i++) {
		if (is_enemy_form(data, pos, size, i)
		|| is_enemy_frame(data, pos, size, i)) {
			sfRectangleShape_setFillColor(
				data->fight[data->id]->enemy[i]->frame, sfYellow);
			sfRectangleShape_setFillColor(
				data->fight[data->id]->enemy[i]->form, sfYellow);
		} else {
			sfRectangleShape_setFillColor(
				data->fight[data->id]->enemy[i]->frame, sfRed);
			sfRectangleShape_setFillColor(
				data->fight[data->id]->enemy[i]->form, sfRed);
		}
	}
}
