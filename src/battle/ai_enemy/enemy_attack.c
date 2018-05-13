/*
** EPITECH PROJECT, 2018
** enemy_attack
** File description:
** rpg
*/

#include "rpg.h"

static bool attack_up(rpg_t *rpg, battle_t *battle, int a, sfVector2f pos)
{
	sfVector2f enemy = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[a]->form);
	int x = pos.x;
	int y = pos.y;

	if (y > 0 && battle->map[y - 1][x] == 1) {
		enemy.x -= 44;
		enemy.y -= 44;
		battle->fight[battle->id]->enemy[a]->rec.top = 9 * 64;
		sfSprite_setPosition(
			battle->fight[battle->id]->enemy[a]->form, enemy);
		enemy_attack_anim(rpg, battle, pos, a);
		battle->hero->hp -= battle->fight[battle->id]->enemy[a]->dmg;
		return (true);
	}
	return (false);
}

static bool attack_down(rpg_t *rpg, battle_t *battle, int a, sfVector2f pos)
{
	sfVector2f enemy = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[a]->form);
	int x = pos.x;
	int y = pos.y;

	if (y < 9 && battle->map[y + 1][x] == 1) {
		enemy.x -= 44;
		enemy.y -= 44;
		battle->fight[battle->id]->enemy[a]->rec.top = 13 * 64;
		sfSprite_setPosition(
			battle->fight[battle->id]->enemy[a]->form, enemy);
		enemy_attack_anim(rpg, battle, pos, a);
		battle->hero->hp -= battle->fight[battle->id]->enemy[a]->dmg;
		return (true);
	}
	return (false);
}

static bool attack_left(rpg_t *rpg, battle_t *battle, int a, sfVector2f pos)
{
	sfVector2f enemy = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[a]->form);
	int x = pos.x;
	int y = pos.y;

	if (x > 0 && battle->map[y][x - 1] == 1) {
		enemy.x -= 44;
		enemy.y -= 44;
		if (battle->fight[battle->id]->enemy[a]->sword) {
			enemy.x -= 20;
			enemy.y -= 4;
		}
		battle->fight[battle->id]->enemy[a]->rec.top = 11 * 64;
		sfSprite_setPosition(
			battle->fight[battle->id]->enemy[a]->form, enemy);
		enemy_attack_anim(rpg, battle, pos, a);
		battle->hero->hp -= battle->fight[battle->id]->enemy[a]->dmg;
		return (true);
	}
	return (false);
}

static bool attack_right(rpg_t *rpg, battle_t *battle, int a, sfVector2f pos)
{
	sfVector2f enemy = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[a]->form);
	int x = pos.x;
	int y = pos.y;

	if (x < 11 && battle->map[y][x + 1] == 1) {
		enemy.x -= 44;
		enemy.y -= 44;
		if (battle->fight[battle->id]->enemy[a]->sword) {
			enemy.x += 32;
			enemy.y -= 4;
		}
		battle->fight[battle->id]->enemy[a]->rec.top = 15 * 64;
		sfSprite_setPosition(
			battle->fight[battle->id]->enemy[a]->form, enemy);
		enemy_attack_anim(rpg, battle, pos, a);
		battle->hero->hp -= battle->fight[battle->id]->enemy[a]->dmg;
		return (true);
	}
	return (false);
}

bool check_enemy_attack(rpg_t *rpg, battle_t *battle, int x, sfVector2f pos)
{
	if (!attack_up(rpg, battle, x, pos)
	&& !attack_down(rpg, battle, x, pos)
	&& !attack_left(rpg, battle, x, pos)
	&& !attack_right(rpg, battle, x, pos))
		return (false);
	return (true);
}
