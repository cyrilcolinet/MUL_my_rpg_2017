/*
** EPITECH PROJECT, 2018
** select_or_unselect
** File description:
** rpg
*/

#include "rpg.h"

static bool spell_select(battle_t *battle)
{
	sfVector2f pos;

	for (int i = 0; i < 4; i++) {
		pos = sfRectangleShape_getPosition(
			battle->hero->spell[i]->icone);
		if ((battle->mouse.x > pos.x && battle->mouse.x < pos.x + 50)
		&& (battle->mouse.y > pos.y && battle->mouse.y < pos.y + 50))
			return (true);
	}
	return (false);
}


static void unselect_all(battle_t *battle, int i)
{
	i = battle->hero->pos.x + battle->hero->pos.y * 12;
	sfRectangleShape_setFillColor
		(battle->fight[battle->id]->map[i], sfBlack);
	battle->hero->select = false;
	if (!spell_select(battle))
		battle->hero->spell_id = -1;
	reset_map_state(battle);
}

void select_or_unselect(battle_t *battle, int i)
{
	unselect_all(battle, i);
	if (battle->map[i / 12][i % 12] == 1)
		battle->hero->select = true;
}
