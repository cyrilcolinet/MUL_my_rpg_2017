/*
** EPITECH PROJECT, 2018
** cast_spell
** File description:
** rpg
*/

#include "rpg.h"

static void cast_simple_case_spell(rpg_t *rpg, battle_t *battle, int a)
{
	sfVector2f pos;
	sfVector2f size;

	if (!battle->hero->spell[a]->cast) {
		display_simple_case(battle, pos, size);
	} else {
		if (a == 0)
			cast_heal(rpg, battle);
		else if (a == 1)
			cast_fire(rpg, battle);
	}
}

static void cast_double_case_spell(rpg_t *rpg, battle_t *battle, int a)
{
	sfVector2f pos = sfSprite_getPosition(battle->hero->form);

	if (!battle->hero->spell[a]->cast)
		display_double_case(battle, pos);
	else {
		if (a == 2)
			cast_ice(rpg, battle);
		else if (a == 3)
			cast_storm(rpg, battle);
	}
}

void cast_spell(rpg_t *rpg, battle_t *battle, int a)
{
	if (a == 0 || a == 1)
		cast_simple_case_spell(rpg, battle, a);
	else if ( a == 2 || a == 3)
		cast_double_case_spell(rpg, battle, a);
}
