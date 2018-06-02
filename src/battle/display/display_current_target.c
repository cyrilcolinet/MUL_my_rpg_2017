/*
** EPITECH PROJECT, 2018
** display_current_target
** File description:
** rpg
*/

#include "rpg.h"

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
	pos = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[i]->form);
	size.x = 64;
	size.y = 64;
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

static void display_arrow(rpg_t *rpg, battle_t *battle, int i, sfVector2f pos)
{
	sfRectangleShape_setTexture(
		battle->icone, battle->texture[3], sfTrue);
	pos = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[i]->form);
	pos.x += 32;
	pos.y -= 16;
	sfRectangleShape_setPosition(battle->icone, pos);
	sfRenderWindow_drawRectangleShape(rpg->win,
			rpg->battle->icone, NULL);
	sfRectangleShape_setFillColor(
		battle->fight[battle->id]->enemy[i]->frame, sfYellow);
}

void display_current_target(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos = {0, 0};
	sfVector2f size = {0, 0};

	for (int i = 0; i < battle->fight[
		battle->id]->number_enemy; i++) {
		sfRectangleShape_setFillColor(
		battle->fight[battle->id]->enemy[i]->frame, sfGreen);
		if (battle->fight[battle->id]->enemy[i]->alive
		&& (is_enemy_form(battle, pos, size, i)
		|| is_enemy_frame(battle, pos, size, i)))
			display_arrow(rpg, battle, i, pos);
		if (!battle->fight[battle->id]->enemy[i]->alive)
			sfRectangleShape_setFillColor(
			battle->fight[battle->id]->
			enemy[i]->frame, sfRed);
	}
}
