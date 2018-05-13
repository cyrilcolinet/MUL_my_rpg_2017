/*
** EPITECH PROJECT, 2018
** cast_fire
** File description:
** rpg
*/

#include "rpg.h"

static void draw_anim(rpg_t *rpg, battle_t *battle, int i)
{
	sfVector2f pos = battle->hero->spell[1]->pos;

	if (i % 6 == 5)
		battle->hero->rec.left = 0;
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->hero->spell[1]->rec.left += 128;
	sfSprite_setTextureRect(battle->hero->spell[1]->form,
		battle->hero->spell[1]->rec);
	battle->hero->rec.left += 64;
	sfSprite_setTextureRect(battle->hero->form,
			battle->hero->rec);
	draw_all(rpg);
	display_hero(rpg, rpg->battle);
	display_enemy(rpg, rpg->battle);
	sfRenderWindow_drawSprite(rpg->win,
			battle->hero->spell[1]->form, NULL);
	display_spell_damage(rpg, battle, pos.y * 12 + pos.x,
			battle->hero->spell[1]->val);
	sfRenderWindow_display(rpg->win);
}

static void burn_the_target(battle_t *battle, int i, int val)
{
	int x = i % 12;
	int y = i / 12;
	int a = 0;
	int b = 0;

	if (battle->map[y][x] == 1) {
		battle->hero->hp -= val;
	}
	for (int j = 0 ;j < battle->fight[
	battle->id]->number_enemy; j++) {
		a = battle->fight[battle->id]->enemy[j]->pos.x;
		b = battle->fight[battle->id]->enemy[j]->pos.y;
		if (battle->map[y][x] == 2 && x == a && y == b) {
			battle->fight[battle->id]->enemy[j]->hp -= val;
		}
	}
}
	
static void reset_spell(battle_t *battle)
{
	sfVector2f pos = battle->hero->spell[1]->pos;

	battle->hero->rec.top -= 4 * 64;
	battle->hero->rec.left = 0;
	sfSprite_setTextureRect(battle->hero->form,
			battle->hero->rec);
	battle->hero->spell[1]->rec.left = 0;
	battle->hero->spell[1]->rec.top = 0;
	sfSprite_setTextureRect(battle->hero->spell[1]->form,
		battle->hero->spell[1]->rec);
	battle->hero->attack = true;
	burn_the_target(battle, pos.y * 12 + pos.x,
		battle->hero->spell[1]->val);
}

void cast_fire(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos;

	pos.x = battle->hero->spell[1]->pos.x * B_X + MAP_X - 8;
	pos.y = battle->hero->spell[1]->pos.y * B_Y + MAP_Y - 32;
	sfSprite_setPosition(battle->hero->spell[1]->form, pos);
	for (int i = 0; i < 12;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.12)))
			battle->time = sfClock_getElapsedTime(
				battle->clock);
		draw_anim(rpg, battle, i);
		i++;
		if (i % 4 == 3) {
			battle->hero->spell[1]->rec.left = 0;
			battle->hero->spell[1]->rec.top += 128;
		}
	}
	reset_spell(battle);
}
