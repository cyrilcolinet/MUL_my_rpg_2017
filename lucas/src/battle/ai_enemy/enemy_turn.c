/*
** EPITECH PROJECT, 2018
** enemy_deplacement
** File description:
** rpg
*/

#include "battle.h"

static bool check_hero_position(sfVector2f pos, sfVector2f hero)
{
	int a = pos.x - hero.x;
	int b = pos.y - hero.y;

	if ((a == 0 && abs(b) == 1) || (abs(a) == 1 && b == 0))
		return (true);
	return (false);
}

static void check_enemy_deplacement(data_t *data, battle_t *battle
		, int x, sfVector2f pos)
{
	sfVector2f hero = {battle->hero->pos.x, battle->hero->pos.y};

	for (int i = 2; i > 0; i--) {
		if (enemy_go_left(data, battle, x, pos) ||
		enemy_go_right(data, battle, x, pos) ||
		enemy_go_up(data, battle, x, pos) ||
		enemy_go_down(data, battle, x, pos)) {
		}
		pos.x = battle->fight[battle->id]->enemy[x]->pos.x;
		pos.y = battle->fight[battle->id]->enemy[x]->pos.y;
		if (check_hero_position(pos, hero))
			break;
	}
	battle->fight[battle->id]->enemy[x]->played = true;
}

void enemy_turn(data_t *data, battle_t *battle)
{
	sfVector2f pos;

	for (int i = 0; i < battle->fight[battle->id]->number_enemy; i++) {
		pos.x = battle->fight[battle->id]->enemy[i]->pos.x;
		pos.y = battle->fight[battle->id]->enemy[i]->pos.y;
		if (battle->fight[battle->id]->enemy[i]->alive
		&& !battle->fight[battle->id]->enemy[i]->played
		&& !check_enemy_attack(data, battle, i, pos)) {
			check_enemy_deplacement(data, battle, i, pos);
			reset_map_state(battle);
			pos.x = battle->fight[battle->id]->enemy[i]->pos.x;
			pos.y = battle->fight[battle->id]->enemy[i]->pos.y;
			check_enemy_attack(data, battle, i, pos);
		}
	}
	battle->fight[battle->id]->enemy_turn = false;
}
