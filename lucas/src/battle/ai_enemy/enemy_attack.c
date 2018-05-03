/*
** EPITECH PROJECT, 2018
** enemy_attack
** File description:
** rpg
*/

#include "battle.h"

static bool attack_up(data_t *data, battle_t *battle, int a, sfVector2f pos)
{
	int x = pos.x;
	int y = pos.y;

	if (y > 0 && battle->map[y - 1][x] == 1) {
		battle->hero->hp -= battle->fight[battle->id]->enemy[a]->dmg;
		enemy_attack_anim(data, battle, pos);
		return (true);
	}
	return (false);
}

static bool attack_down(data_t *data, battle_t *battle, int a, sfVector2f pos)
{
	int x = pos.x;
	int y = pos.y;

	if (y < 9 && battle->map[y + 1][x] == 1) {
		battle->hero->hp -= battle->fight[battle->id]->enemy[a]->dmg;
		enemy_attack_anim(data, battle, pos);
		return (true);
	}
	return (false);
}

static bool attack_left(data_t *data, battle_t *battle, int a, sfVector2f pos)
{
	int x = pos.x;
	int y = pos.y;

	if (x > 0 && battle->map[y][x - 1] == 1) {
		battle->hero->hp -= battle->fight[battle->id]->enemy[a]->dmg;
		enemy_attack_anim(data, battle, pos);
		return (true);
	}
	return (false);
}

static bool attack_right(data_t *data, battle_t *battle, int a, sfVector2f pos)
{
	int x = pos.x;
	int y = pos.y;

	if (x < 11 && battle->map[y][x + 1] == 1) {
		battle->hero->hp -= battle->fight[battle->id]->enemy[a]->dmg;
		enemy_attack_anim(data, battle, pos);
		return (true);
	}
	return (false);
}

bool check_enemy_attack(data_t *data, battle_t *battle, int x, sfVector2f pos)
{
	if (!attack_up(data, battle, x, pos)
	&& !attack_down(data, battle, x, pos)
	&& !attack_left(data, battle, x, pos)
	&& !attack_right(data, battle, x, pos))
		return (false);
	return (true);
}
