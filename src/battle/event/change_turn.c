/*
** EPITECH PROJECT, 2018
** change_turn
** File description:
** rpg
*/

#include "rpg.h"

static void end_battle_display(rpg_t *rpg, battle_t *battle, int nb)
{
	sfVector2f pos = {};

	battle->run = false;
	rpg->player->direction = down;
//	sfSprite_setPosition()
}

void end_battle(rpg_t *rpg, battle_t *battle)
{
	if (!battle->hero->alive)
		end_battle_display(rpg, battle, 2);
	for (int i = 0; i < battle->fight[
		battle->id]->number_enemy; i++) {
		if (battle->fight[battle->id]->enemy[i]->alive)
			return;
	}
	end_battle_display(rpg, battle, 1);
}

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
		for (int i = 0; i < nb; i++)
			battle->fight[battle->id]->enemy[i]->played = false;
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
		battle->hero->select = false;
		battle->hero->played = false;
		battle->hero->attack = false;
		battle->hero->move = false;
		battle->hero->spell_id = -1;
		for (int i = 0; i < 4; i++)
			battle->hero->spell[i]->cast = false;
		battle->fight[battle->id]->enemy_turn = true;
	}
	change_enemy_turn(battle, n, nb);
}
