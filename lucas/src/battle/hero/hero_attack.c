/*
** EPITECH PROJECT, 2018
** hero_attack
** File description:
** rpg
*/

#include "battle.h"

static void draw_anim(data_t *data, battle_t *battle)
{
	sfRenderWindow_clear(data->window, sfBlack);
	battle->hero->rec.left += 64;
	sfSprite_setTextureRect(
		battle->hero->form, battle->hero->rec);
	draw_all(data);
	display_enemy(data, battle);
	display_hero(data, battle);
	sfRenderWindow_display(data->window);
}

static void attack_anim(data_t *data, battle_t *battle)
{
	for (int i = 0; i < 11;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.08)))
			battle->time = sfClock_getElapsedTime(
				battle->clock);
		draw_anim(data, battle);
		i++;
		if (i == 6)
			battle->hero->rec.left = 0;
	}
	sfRenderWindow_clear(data->window, sfBlack);
	battle->hero->rec.left = 0;
	battle->hero->rec.top -= 9 * 64;
	sfSprite_setTextureRect(
		battle->hero->form, battle->hero->rec);
}

static bool can_attack(battle_t *battle)
{
	int x = battle->hero->pos.x;
	int y = battle->hero->pos.y;

	if ((x - 1 >= 0 && battle->map[y][x - 1] == 2) ||
	(x + 1 <= 11 && battle->map[y][x + 1] == 2) ||
	(y - 1 >= 0 && battle->map[y - 1][x] == 2) ||
	(y + 1 <= 9 && battle->map[y + 1][x] == 2))
		return (true);
	return (false);
}

static void set_attack_orientation(battle_t *battle, sfVector2f pos)
{
	if (battle->hero->pos.x > pos.x)
		battle->hero->rec.top = 10 * 64;
	else if (battle->hero->pos.x < pos.x)
		battle->hero->rec.top = 12 * 64;
	if (battle->hero->pos.y > pos.y)
		battle->hero->rec.top = 9 * 64;
	else if (battle->hero->pos.y < pos.y)
		battle->hero->rec.top = 11 * 64;
}

void hero_attack(data_t *data, battle_t *battle)
{
	sfVector2f pos;
	int i;

	if (battle->hero->move && !can_attack(battle)) {
		battle->hero->attack = true;
		return;
	}
	if (battle->hero->target != -1) {
		reset_map_state(battle);
		i = battle->hero->target;
		pos = battle->fight[battle->id]->enemy[i]->pos;
		set_attack_orientation(battle, pos);
		attack_anim(data, battle);
		battle->hero->attack = true;
		battle->fight[battle->id]->enemy[i]->hp -= battle->hero->dmg;
		battle->hero->target = -1;
		if (battle->fight[battle->id]->enemy[i]->hp <= 0)
			battle->fight[battle->id]->enemy[i]->alive = false;
	}
}
