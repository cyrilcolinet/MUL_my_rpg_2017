/*
** EPITECH PROJECT, 2018
** deplacement
** File description:
** rpg
*/

#include "rpg.h"

static void set_new_hero_pos(battle_t *battle, int i, sfVector2f pos)
{
	if ((battle->mouse.x > pos.x && battle->mouse.x < pos.x + B_X) &&
	(battle->mouse.y > pos.y && battle->mouse.y < pos.y + B_Y))
		if (battle->map[i / 12][i % 12] == 3) {
			battle->hero->move = true;
			battle->hero->new.x = i % 12;
			battle->hero->new.y = i / 12;
			reset_map_state(battle);
		}
}

void deplacement(battle_t *battle)
{
	sfVector2f pos;

	for (int i = 0; i < 120; i++) {
		pos = sfRectangleShape_getPosition
			(battle->fight[battle->id]->map[i]);
		set_new_hero_pos(battle, i, pos);
	}
}
