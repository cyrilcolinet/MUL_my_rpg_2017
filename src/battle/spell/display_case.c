/*
** EPITECH PROJECT, 2018
** display_case
** File description:
** rpg
*/

#include "rpg.h"

static void display_color(battle_t *battle, int i)
{
	int x = i % 12;
	int y = i / 12;

	if (battle->map[y][x] == 1) {
		sfRectangleShape_setFillColor(
			battle->fight[battle->id]->map[i],
			sfColor_fromRGBA(0, 0, 255, 100));
	} else if (battle->map[y][x] == 2) {
		sfRectangleShape_setFillColor(
			battle->fight[battle->id]->map[i],
			sfColor_fromRGBA(255, 0, 0, 100));
	} else {
		sfRectangleShape_setFillColor(
			battle->fight[battle->id]->map[i],
			sfColor_fromRGBA(255, 255, 0, 100));
	}
}

void display_simple_case(battle_t *battle, sfVector2f pos, sfVector2f size, int i)
{
	int x = battle->mouse.x;
	int y = battle->mouse.y;

	if (x > pos.x && x < pos.x + size.x
	&& y > pos.y && y < pos.y + size.y) {
		if (abs(x - battle->hero->pos.x) +
		abs(y - battle->hero->pos.y) <= 5) {
			display_color(battle, i);
		}
	}
}

void display_double_case(battle_t *battle, sfVector2f pos)
{
	sfVector2f hero;
	int x = battle->mouse.x;
	int y = battle->mouse.y;

	hero.x = battle->hero->pos.x;
	hero.y = battle->hero->pos.y;
	if (x < pos.x + B_X && x > pos.x) {
		if (y > pos.y + B_Y) {
			if (hero.y + 1 <= 9)
				display_color(battle, (hero.y + 1) * 12 + hero.x);
			if (hero.y + 2 <= 9)
				display_color(battle, (hero.y + 2) * 12 + hero.x);
		}
		if (y < pos.y) {
			if (hero.y - 1 >= 0)
				display_color(battle, (hero.y - 1) * 12 + hero.x);
			if (hero.y - 2 >= 0)
				display_color(battle, (hero.y - 2) * 12 + hero.x);
		}
	}
	else if (x < pos.x) {
		if (hero.x - 1 >= 0)
			display_color(battle, hero.y * 12 + hero.x - 1);
		if (hero.x - 2 >= 0)
			display_color(battle, hero.y * 12 + hero.x - 2);
	}
	else if (x > pos.x + B_X) {
		if (hero.x + 1 <= 11)
			display_color(battle, hero.y * 12 + hero.x + 1);
		if (hero.x + 2 <= 11)
			display_color(battle, hero.y * 12 + hero.x + 2);
	}
}
