/*
** EPITECH PROJECT, 2018
** display_current_target
** File description:
** rpg
*/

#include "battle.h"

static bool is_in_form(battle_t *battle, sfVector2f pos, sfVector2f size)
{
	int x = battle->mouse.x;
	int y = battle->mouse.y;

	if ((x >= pos.x && x <= pos.x + size.x)
	&& (y >= pos.y && y <= pos.y + size.y))
		return (true);
	return (false);
}

static bool is_enemy_form(battle_t *battle, sfVector2f pos,
		sfVector2f size, int i)
{
	pos = sfRectangleShape_getPosition(
		battle->fight[battle->id]->enemy[i]->form);
	size = sfRectangleShape_getSize(
		battle->fight[battle->id]->enemy[i]->form);
	if (is_in_form(battle, pos, size))
		return (true);
	return (false);
}

static bool is_enemy_frame(battle_t *battle, sfVector2f pos,
		sfVector2f size, int i)
{
	pos = sfRectangleShape_getPosition(
		battle->fight[battle->id]->enemy[i]->frame);
	size = sfRectangleShape_getSize(
		battle->fight[battle->id]->enemy[i]->frame);
	if (is_in_form(battle, pos, size))
		return (true);
	return (false);
}

void display_current_target(battle_t *battle)
{
	sfVector2f pos;
	sfVector2f size;

	for (int i = 0; i < battle->fight[battle->id]->number_enemy; i++) {
		if (is_enemy_form(battle, pos, size, i)
		|| is_enemy_frame(battle, pos, size, i)) {
			sfRectangleShape_setFillColor(
			battle->fight[battle->id]->enemy[i]->frame, sfYellow);
			sfRectangleShape_setFillColor(
			battle->fight[battle->id]->enemy[i]->form, sfYellow);
		} else {
			sfRectangleShape_setFillColor(
			battle->fight[battle->id]->enemy[i]->frame, sfRed);
			sfRectangleShape_setFillColor(
			battle->fight[battle->id]->enemy[i]->form, sfRed);
		}
	}
}
