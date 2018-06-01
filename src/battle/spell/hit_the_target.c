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

static void set_damage2(rpg_t *rpg, int i, int b , int y)
{
	int x = rpg->battle->hero->spell[rpg->battle->hero->spell_id]->pos.x;
	int a = rpg->battle->fight[rpg->battle->id]->enemy[i]->pos.x;
	int id = rpg->battle->hero->spell_id;

	if (y > rpg->battle->hero->pos.y && b >= y
	&& b - y <= 1 && a == x) {
		check_dead(rpg, rpg->battle, i,
		rpg->battle->hero->spell[id]->val);
	}
	if (y < rpg->battle->hero->pos.y && y >= b
	&& y - b <= 1 && a == x) {
		check_dead(rpg, rpg->battle, i,
		rpg->battle->hero->spell[id]->val);
	}
}

static void set_damage(rpg_t *rpg, battle_t *battle, int i, int val)
{
	int x = battle->hero->spell[battle->hero->spell_id]->pos.x;
	int y = battle->hero->spell[battle->hero->spell_id]->pos.y;
	int a = battle->fight[battle->id]->enemy[i]->pos.x;
	int b = battle->fight[battle->id]->enemy[i]->pos.y;

	if (x > battle->hero->pos.x && a >= x
	&& a - x <= 1 && y == b) {
		check_dead(rpg, battle, i, val);
	}
	if (x < battle->hero->pos.x && x >= a
	&& x - a <= 1 && y == b) {
		check_dead(rpg, battle, i, val);
	}
	set_damage2(rpg, i, b, y);
}

void hit_the_target(rpg_t *rpg, battle_t *battle, int i, int val)
{
	int x = i % 12;
	int y = i / 12;
	int a = 0;
	int b = 0;

	for (int j = 0; j < battle->fight[battle->id]
		->number_enemy; j++) {
		a = battle->fight[battle->id]->enemy[j]->pos.x;
		b = battle->fight[battle->id]->enemy[j]->pos.y;
		if (battle->fight[battle->id]->enemy[j]->alive &&
		((x == a || y == b))) {
			set_damage(rpg, battle, j, val);
		}
	}
}
