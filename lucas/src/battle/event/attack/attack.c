/*
** EPITECH PROJECT, 2018
** attack
** File description:
** rpg
*/

#include "battle.h"

//static void enemy_detection();

void attack(battle_t *battle, sfEvent event)
{
	int x = battle->hero->pos.x;
	int y = battle->hero->pos.y;
	sfVector2f pos;

	if (battle->hero->select) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 12; j++) {
				if ((i != y || j != x) && (abs(i - y) < 4
				&& abs(j - x) < 4) && (abs(i - y) + abs(j - x) < 4)
				&& battle->map[i][j] == 2) {
					sfRectangleShape_setFillColor(battle->fight
						[battle->id]->map[i * 12 + j], sfRed);
				}
			}
		}
	}
	battle->hero->attack = true;
}
