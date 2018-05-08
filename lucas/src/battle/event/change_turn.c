/*
** EPITECH PROJECT, 2018
** change_turn
** File description:
** rpg
*/

#include "battle.h"

static void change_enemy_turn(battle_t *battle, int n, int nb)
{
	if (battle->fight[battle->id]->enemy_turn) {
		for (int i = 0; i < nb; i++) {
			if (battle->fight[battle->id]->enemy[i]->played)
				n++;
		}
		if (n == nb) {
			battle->hero->move = false;
			battle->hero->played = false;
			battle->hero->attack = false;
			battle->fight[battle->id]->enemy_turn = false;
		}
	}
}

void change_turn(battle_t *battle)
{
	int n = 0;
	int nb = battle->fight[battle->id]->number_enemy;

	if (!battle->fight[battle->id]->enemy_turn &&
	!battle->hero->played && battle->hero->attack)
		battle->hero->played = true;
	if (battle->hero->played && !battle->fight[battle->id]->enemy_turn) {
		for (int i = 0; i < nb; i++)
			battle->fight[battle->id]->enemy[i]->played = false;
		battle->hero->select = false;
		battle->hero->played = false;
		battle->hero->attack = false;
		battle->hero->move = false;
		battle->fight[battle->id]->enemy_turn = true;
	}
	change_enemy_turn(battle, n, nb);
}
