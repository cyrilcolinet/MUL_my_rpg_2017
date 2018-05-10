/*
** EPITECH PROJECT, 2018
** enemy_deplacement_anim
** File description:
** rpg
*/

#include "rpg.h"

static void display_other_enemy(rpg_t *rpg, battle_t *battle, int x)
{
	sfvector2f pos;
	int id = battle->id;

	for (int i = 0; i < battle->fight[id]->number_enemy; i++) {
		if (i != x && battle->fight[id]->enemy[i]->alive) {
			pos.x = map_x + battle->fight[id]->enemy[i]->
				pos.x * b_x + 15;
			pos.y = map_y + battle->fight[id]->enemy[i]->
				pos.y * b_y - 5;
			sfsprite_setposition
				(battle->fight[id]->enemy[i]->form, pos);
			sfrenderwindow_drawsprite(rpg->win,
				battle->fight[id]->enemy[i]->form, null);
		}
	}
}

static void draw_anim(rpg_t *rpg, battle_t *battle, int x)
{
	sfrenderwindow_clear(rpg->win, sfblack);
	battle->fight[battle->id]->enemy[x]->rec.left += 64;
	sfsprite_settexturerect(
		battle->fight[battle->id]->enemy[x]->form,
		battle->fight[battle->id]->enemy[x]->rec);
	draw_all(rpg);
	display_hero(rpg, battle);
	display_other_enemy(rpg, battle, x);
	sfrenderwindow_drawsprite(rpg->win,
		battle->fight[battle->id]->enemy[x]->form, null);
	sfrenderwindow_display(rpg->win);
}

static void anim(rpg_t *rpg, battle_t *battle, int x)
{
	sfvector2f pos = sfsprite_getposition(
		battle->fight[battle->id]->enemy[x]->form);

	for (int i = 0; i < 9;) {
		sfclock_restart(battle->clock);
		battle->time = sftime_zero;
		while (sftime_asseconds(battle->time)
		< sftime_asseconds(sfseconds(0.08)))
			battle->time = sfclock_getelapsedtime(battle->clock);
		pos.x += -1 * (b_x / 8);
		sfsprite_setposition(
			battle->fight[battle->id]->enemy[x]->form, pos);
		draw_anim(rpg, battle, x);
		i++;
	}
	sfrenderwindow_clear(rpg->win, sfblack);
}

static void go_left(rpg_t *rpg, battle_t *battle, int x, sfvector2f pos)
{
	pos.x -= 1;
	battle->fight[battle->id]->enemy[x]->pos.x -= 1;
	battle->fight[battle->id]->enemy[x]->rec.top = 64;
	anim(rpg, battle, x);
	battle->fight[battle->id]->enemy[x]->rec.left = 0;
	sfsprite_settexturerect(
		battle->fight[battle->id]->enemy[x]->form,
		battle->fight[battle->id]->enemy[x]->rec);
	draw_all(rpg);
	display_enemy(rpg, battle);
	display_hero(rpg, battle);
	sfrenderwindow_display(rpg->win);
}

bool enemy_go_left(rpg_t *rpg, battle_t *battle, int x,
		sfvector2f pos)
{
	sfvector2f hero = {battle->hero->pos.x, battle->hero->pos.y};
	int a = pos.x - hero.x;
	int b = pos.y - hero.y;
	int c = pos.y;
	int d = pos.x;

	if (pos.x >= 1 && battle->map[c][d - 1] == 0) {
		if (abs(b) > a && ((c >= 1 && battle->map[c - 1][d] == 0)
			|| (c <= 8 && battle->map[c + 1][d] == 0)))
			return (false);
		if (a > 0) {
			go_left(rpg, battle, x, pos);
			return (true);
		} else if (a == 0 && ((c >= 1 && battle->map[c - 1][d] != 0)
			|| (c <= 8 && battle->map[c + 1][d] != 0))) {
			go_left(rpg, battle, x, pos);
			return (true);
		}
	}
	return (false);
}
