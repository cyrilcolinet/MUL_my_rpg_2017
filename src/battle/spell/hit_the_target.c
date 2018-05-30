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

static void damage_2_man(rpg_t *rpg, int x, int y)
{
	int a = 0;
	int b = 0;
	int id = rpg->battle->hero->spell_id;

	for (int j = 0; j < rpg->battle->fight
		[rpg->battle->id]->number_enemy; j++) {
		a = rpg->battle->fight[rpg->battle->id]->enemy[j]->pos.x;
		b = rpg->battle->fight[rpg->battle->id]->enemy[j]->pos.y;
		if (rpg->battle->fight[rpg->battle->id]->enemy[j]->alive
		&& a == x && y == b)
			check_dead(rpg, rpg->battle, j,
			rpg->battle->hero->spell[id]->val);
	}
}
static void set_damage2(rpg_t *rpg, int i, int x , int y)
{
	int id = rpg->battle->hero->spell_id;

	if (y > rpg->battle->hero->pos.y) {
		check_dead(rpg, rpg->battle, i,
		rpg->battle->hero->spell[id]->val);
		if (rpg->battle->map[y][x] == 2 && y + 1 <= 9
		&& rpg->battle->map[y + 1][x] == 2)
			damage_2_man(rpg, x, y + 1);
	}
	if (y < rpg->battle->hero->pos.y) {
		check_dead(rpg, rpg->battle, i,
		rpg->battle->hero->spell[id]->val);
		if (rpg->battle->map[y][x] == 2 && y - 1 >= 0
		&& rpg->battle->map[y - 1][x] == 2)
			damage_2_man(rpg, x, y - 1);
	}
}

static void set_damage(rpg_t *rpg, battle_t *battle, int i, int val)
{
	int x = battle->hero->spell[battle->hero->spell_id]->pos.x;
	int y = battle->hero->spell[battle->hero->spell_id]->pos.y;
	int a = battle->fight[battle->id]->enemy[i]->pos.x;
	int b = battle->fight[battle->id]->enemy[i]->pos.y;

	if (battle->map[y][x] == 2 && (a != x || b != y))
		return;
	if (x > battle->hero->pos.x) {
		check_dead(rpg, battle, i, val);
		if (battle->map[y][x] == 2 && x + 1 <= 11
		&& battle->map[y][x + 1] == 2)
			damage_2_man(rpg, x + 1, y);
	}
	if (x < battle->hero->pos.x) {
		check_dead(rpg, battle, i, val);
		if (battle->map[y][x] == 2 && x - 1 >= 0
		&& battle->map[y][x - 1] == 2)
			damage_2_man(rpg, x - 1, y);
	}
	set_damage2(rpg, i, x, y);
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
		    ((x == a && y == b)))/*  || (abs(x - a) == 1 && y == b) */
		/* || (abs(y - b) == 1 && a == x))) */ {
			printf("POS %d  %d \n", a, b);
			set_damage(rpg, battle, j, val);
		}
	}
}
