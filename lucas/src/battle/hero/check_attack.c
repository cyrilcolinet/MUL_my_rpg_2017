/*
** EPITECH PROJECT, 2018
** attack
** File description:
** rpg
*/

#include "battle.h"

static void detect_top_bot(battle_t *battle, int y, int x)
{
	if (y >= 1 && battle->map[y - 1][x] == 2) {
		sfRectangleShape_setFillColor(
		battle->fight[battle->id]->map[(y - 1) * 12 + x],
		sfColor_fromRGBA(255, 0, 0, 128));
	}
	if (y <= 8 && battle->map[y + 1][x] == 2) {
		sfRectangleShape_setFillColor(
		battle->fight[battle->id]->map[(y + 1) * 12 + x],
		sfColor_fromRGBA(255, 0, 0, 128));
	}
}

static void detect_left_right(battle_t *battle, int y, int x)
{
	if (x >= 1 && battle->map[y][x - 1] == 2) {
		sfRectangleShape_setFillColor(
		battle->fight[battle->id]->map[y * 12 + x - 1],
		sfColor_fromRGBA(255, 0, 0, 128));
	}
	if (x <= 10 && battle->map[y][x + 1] == 2) {
		sfRectangleShape_setFillColor(
		battle->fight[battle->id]->map[y * 12 + x + 1],
		sfColor_fromRGBA(255, 0, 0, 128));
	}
}

static void enemy_detection(battle_t *battle, int y, int x)
{
	if (battle->map[y][x] == 3 || battle->map[y][x] == 1) {
		detect_top_bot(battle, y, x);
		detect_left_right(battle, y, x);
	}
}

void check_attack(battle_t *battle)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			enemy_detection(battle, i, j);
		}
	}
}
