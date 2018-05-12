/*
** EPITECH PROJECT, 2018
** cast_spell
** File description:
** rpg
*/

#include "rpg.h"

static void display_case(battle_t *battle)
{
	int x = battle->mouse.x;
	int y = battle->mouse.y;
	sfVector2f pos;
	sfVector2f size;

	for (int i = 0; i < 120; i++) {
		pos = sfRectangleShape_getPosition(
			battle->fight[battle->id]->map[i]);
		size = sfRectangleShape_getSize(
			battle->fight[battle->id]->map[i]);
		if (x > pos.x && x < pos.x + size.x
		&& y > pos.y && y < pos.y + size.y) {
			sfRectangleShape_setFillColor(
			battle->fight[battle->id]->map[i],
			sfColor_fromRGBA(255, 255, 0, 100));
		} else
			sfRectangleShape_setFillColor(
			battle->fight[battle->id]->map[i], sfTransparent);
			
	}
}

static void cast_simple_case_spell(battle_t *battle, int a)
{
	if (!battle->hero->spell[a]->cast)
		display_case(battle);
	else {
		/* if (a == 0) */
		/* 	cast_heal(rpg, battle); */
		/* else if (a == 1) */
		/* 	cast_fire(rpg, battle); */
	}
}

static void cast_double_case_spell(battle_t *battle, int a)
{
	if (1) {
	}
}

void cast_spell(rpg_t *rpg, battle_t *battle, int a)
{
	if (a == 0 || a == 1)
		cast_simple_case_spell(battle, a);
	else if ( a == 2 || a == 3)
		cast_double_case_spell(battle, a);
}
