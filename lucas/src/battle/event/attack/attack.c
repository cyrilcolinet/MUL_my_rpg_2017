/*
** EPITECH PROJECT, 2018
** attack
** File description:
** rpg
*/

#include "battle.h"

static void attack_part2(battle_t *battle, int i, sfVector2f pos)
{
	sfVector2f pos2;
	int a = pos.y * 12 + pos.x;

	pos2 = sfRectangleShape_getPosition(battle->fight[battle->id]->map[a]);
	if ((battle->mouse.x > pos2.x && battle->mouse.x < pos2.x + B_X) &&
	(battle->mouse.y > pos2.y && battle->mouse.y < pos2.y + B_Y)) {
		if (battle->fight[battle->id]->enemy[i]->alive)
		    battle->hero->target = i;
	}
}

void attack(battle_t *battle)
{
	sfVector2f pos;
	int a;
	int b;

	for (int i = 0; i < battle->fight[battle->id]->number_enemy; i++) {
		pos.x = battle->fight[battle->id]->enemy[i]->pos.x;
		pos.y = battle->fight[battle->id]->enemy[i]->pos.y;
		a = abs(pos.x - battle->hero->pos.x);
		b = abs(pos.y - battle->hero->pos.y);
		if ((a == 1 && b == 0) || (a == 0 && b == 1))
			attack_part2(battle, i, pos);
	}
}
