/*
** EPITECH PROJECT, 2018
** check_deplacement
** File description:
** rpg
*/

#include "battle.h"

static bool go_top(battle_t *battle, int x, int y, int n)
{
	sfColor color = sfColor_fromRGBA(0, 255, 0, 128);
	int nb = (y - n) * 12 + x;

	if (y - n < 0 || battle->map[y - n][x] == 2)
		return (false);
	set_color(battle, nb, color);
	battle->map[y - n][x] = 3;
	for (int a = 1; a < 4 - n; a++) {
		if (x + a > 11 || battle->map[y - n][x + a] == 2)
			break;
		set_color(battle, nb + a, color);
		battle->map[y - n][x + a] = 3;
	}
	for (int a = 1; a < 4 - n; a++) {
		if (x - a < 0 || battle->map[y - n][x - a] == 2)
			break;
		set_color(battle, nb - a, color);
		battle->map[y - n][x - a] = 3;
	}
	return (true);
}

static bool go_bot(battle_t *battle, int x, int y, int n)
{
	sfColor color = sfColor_fromRGBA(0, 255, 0, 128);
	int nb = (y + n) * 12 + x;

	if (y + n > 9 || battle->map[y + n][x] == 2)
		return (false);
	set_color(battle, nb, color);
	battle->map[y + n][x] = 3;
	for (int a = 1; a < 4 - n; a++) {
		if (x + a > 11 || battle->map[y + n][x + a] == 2)
			break;
		set_color(battle, nb + a, color);
		battle->map[y + n][x + a] = 3;
	}
	for (int a = 1; a < 4 - n; a++) {
		if (x - a < 0 || battle->map[y + n][x - a] == 2)
			break;
		set_color(battle, nb - a, color);
		battle->map[y + n][x - a] = 3;
	}
	return (true);
}

static bool go_left(battle_t *battle, int x, int y, int n)
{
	sfColor color = sfColor_fromRGBA(0, 255, 0, 128);
	int nb = y * 12 + x - n;

	if (x - n < 0 || battle->map[y][x - n] == 2)
		return (false);
	set_color(battle, nb, color);
	battle->map[y][x - n] = 3;
	for (int a = 1; a < 4 - n; a++) {
		if (y + a > 9 || battle->map[y + a][x - n] == 2)
			break;
		set_color(battle, nb + a * 12, color);
		battle->map[y + a][x - n] = 3;
	}
	for (int a = 1; a < 4 - n; a++) {
		if (y - a < 0 || battle->map[y - a][x - n] == 2)
			break;
		set_color(battle, nb - a * 12, color);
		battle->map[y - a][x - n] = 3;
	}
	return (true);
}

static bool go_right(battle_t *battle, int x, int y, int n)
{
	sfColor color = sfColor_fromRGBA(0, 255, 0, 128);
	int nb = y * 12 + x + n;

	if (x + n > 11 || battle->map[y][x + n] == 2)
		return (false);
	set_color(battle, nb, color);
	battle->map[y][x + n] = 3;
	for (int a = 1; a < 4 - n; a++) {
		if (y + a > 9 || battle->map[y + a][x + n] == 2)
			break;
		set_color(battle, nb + a * 12, color);
		battle->map[y + a][x + n] = 3;
	}
	for (int a = 1; a < 4 - n; a++) {
		if (y - a < 0 || battle->map[y - a][x + n] == 2)
			break;
		set_color(battle, nb - a * 12, color);
		battle->map[y - a][x + n] = 3;
	}
	return (true);
}

void check_deplacement(battle_t *battle)
{
	int x = battle->hero->pos.x;
	int y = battle->hero->pos.y;

	for (int i = 1; i < 4; i++)
		if (!go_top(battle, x, y, i))
			break;
	for (int i = 1; i < 4; i++)
		if (!go_bot(battle, x, y, i))
			break;
	for (int i = 1; i < 4; i++)
		if (!go_left(battle, x, y, i))
			break;
	for (int i = 1; i < 4; i++)
		if (!go_right(battle, x, y, i))
			break;
}
