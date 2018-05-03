/*
** EPITECH PROJECT, 2018
** deplacement
** File description:
** rpg
*/

#include "battle.h"

void hero_deplacement(battle_t *battle, int i, sfVector2f pos)
{
	if ((battle->mouse.x > pos.x && battle->mouse.x < pos.x + B_X) &&
	(battle->mouse.y > pos.y && battle->mouse.y < pos.y + B_Y))
		if (battle->map[i / 12][i % 12] == 3) {
			battle->hero->select = false;
			battle->hero->move = true;
			battle->hero->pos.x = i % 12;
			battle->hero->pos.y = i / 12;
			reset_map_state(battle);
		}
}

static void hero_turn(battle_t *battle)
{
	sfVector2f pos;

	if (battle->hero->select) {
		for (int i = 0; i < 120; i++) {
			pos = sfRectangleShape_getPosition
				(battle->fight[battle->id]->map[i]);
			hero_deplacement(battle, i, pos);
		}
	}
}

void deplacement(battle_t *battle)
{
	if (!battle->fight[battle->id]->enemy_turn)
		hero_turn(battle);
}
