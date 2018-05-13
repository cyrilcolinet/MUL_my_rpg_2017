/*
** EPITECH PROJECT, 2018
** hit_the_target
** File description:
** rpg
*/

#include "rpg.h"

static void check_dead(rpg_t *rpg, battle_t *battle, int i, int val)
{
	battle->fight[battle->id]->enemy[i]->hp -= val;
	if (battle->fight[battle->id]->enemy[i]->hp <= 0) {
		battle->fight[battle->id]->enemy[i]->alive = false;
		display_enemy_dead_animation(rpg, battle, i);
	}
}

static void set_damage2(rpg_t *rpg, int i, int y, int val)
{
	if (y > rpg->battle->hero->pos.x) {
		check_dead(rpg, rpg->battle, i, val);
		if (y + 1 <= 9);
	}
	if (y < rpg->battle->hero->pos.x) {
		check_dead(rpg, rpg->battle, i, val);
		if (y - 1 >= 0);
	}
}

static void set_damage(rpg_t *rpg, battle_t *battle, int i, int val)
{
	int x = battle->hero->spell[battle->hero->spell_id]->pos.x;
	int y = battle->hero->spell[battle->hero->spell_id]->pos.y;

	if (x > battle->hero->pos.x) {
		check_dead(rpg, battle, i, val);
		if (x + 1 <= 11);
	}
	if (x < battle->hero->pos.x) {
		check_dead(rpg, battle, i, val);
		if (x - 1 >= 0);
	}
	set_damage2(rpg, i, y, val);
}

void hit_the_target(rpg_t *rpg, battle_t *battle, int i, int val)
{
	int x = i % 12;
	int y = i / 12;
	int a = 0;
	int b = 0;
	int j = 0;

	for (;j < battle->fight[battle->id]->number_enemy; j++) {
		a = battle->fight[battle->id]->enemy[j]->pos.x;
		b = battle->fight[battle->id]->enemy[j]->pos.y;
		if (battle->fight[battle->id]->enemy[j]->alive,
		battle->map[y][x] == 2 && x == a && y == b) {
			set_damage(rpg, battle, j, val);
			break;
		}
	}
}
