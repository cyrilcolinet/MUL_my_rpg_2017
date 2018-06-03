/*
** EPITECH PROJECT, 2018
** end_battle
** File description:
** rpg
*/

#include "rpg.h"

static void end_battle_display(rpg_t *rpg, battle_t *battle)
{
	for (int i = 0; i < 4; i++)
		battle->hero->spell[i]->cast = false;
	battle->hero->alive = true;
	battle->hero->hp = battle->hero->hp_max;
	battle->hero->select = false;
	battle->hero->played = false;
	battle->hero->move = false;
	battle->hero->attack = false;
	battle->fight[battle->id]->enemy_turn = false;
	battle->run = false;
}

bool end_battle(rpg_t *rpg, battle_t *battle)
{
	if (!battle->hero->alive) {
		end_battle_display(rpg, battle);
		return (true);
	}
	for (int i = 0; i < battle->fight[battle->id]->number_enemy; i++) {
		if (battle->fight[battle->id]->enemy[i]->alive)
			return (false);
	}
	end_battle_display(rpg, battle);
	rpg->player->quest->id++;
	return (true);
}
