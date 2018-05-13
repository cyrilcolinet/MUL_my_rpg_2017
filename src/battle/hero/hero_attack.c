/*
** EPITECH PROJECT, 2018
** hero_attack
** File description:
** rpg
*/

#include "rpg.h"

static void draw_anim(rpg_t *rpg, battle_t *battle, int i)
{
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->hero->rec.left += 128;
	sfSprite_setTextureRect(
		battle->hero->form, battle->hero->rec);
	draw_all(rpg);
	display_enemy(rpg, battle);
	sfRenderWindow_drawSprite
		(rpg->win, battle->hero->form, NULL);
	display_hero_damage(rpg, battle, i);
	sfRenderWindow_display(rpg->win);
}

static void attack_anim(rpg_t *rpg, battle_t *battle, int x)
{
	sfVector2f pos = sfSprite_getPosition(battle->hero->form);

	battle->hero->rec.width = 128;
	battle->hero->rec.height = 128;
	for (int i = 0; i < 10;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.1)))
			battle->time = sfClock_getElapsedTime(
				battle->clock);
		draw_anim(rpg, battle, x);
		i++;
		if (i == 5)
			battle->hero->rec.left = 0;
	}
	pos.x += 32;
	pos.y += 32;
	sfSprite_setPosition(battle->hero->form, pos);
}

static void do_damage_attack(battle_t *battle, int i)
{
	battle->hero->rec.top = (
		(battle->hero->rec.top - (9 * 64)) / 128) * 64;
	battle->hero->rec.left = 0;
	battle->hero->rec.width = 64;
	battle->hero->rec.height = 64;
	sfSprite_setTextureRect(
		battle->hero->form, battle->hero->rec);
	battle->hero->attack = true;
	battle->fight[battle->id]->enemy[i]->hp -= battle->hero->dmg;
	battle->hero->target = -1;
	if (battle->fight[battle->id]->enemy[i]->hp <= 0)
		battle->fight[battle->id]->enemy[i]->alive = false;
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

void hero_attack(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos;
	int i = battle->hero->target;
	int a = 0;

	for (; a < 4; a++)
		if (battle->hero->spell[a]->unlock)
			break;
	if (battle->hero->move && a > 3 && !can_attack(battle)) {
		battle->hero->attack = true;
		return;
	}
	if (i != -1) {
		reset_map_state(battle);
		pos = battle->fight[battle->id]->enemy[i]->pos;
		set_attack_orientation(battle, pos);
		attack_anim(rpg, battle, i);
		do_damage_attack(battle, i);
		if (!battle->fight[battle->id]->enemy[i]->alive)
			display_enemy_dead_animation(rpg, battle, i);
		reset_map_state(battle);
	}
}
