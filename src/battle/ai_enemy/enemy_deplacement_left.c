/*
** EPITECH PROJECT, 2018
** enemy_deplacement_anim
** File description:
** rpg
*/

#include "rpg.h"

static void display_other_enemy(rpg_t *rpg, battle_t *battle, int a)
{
	sfVector2f pos;
	int id = battle->id;

	for (int i = 0; i < battle->fight[id]->number_enemy; i++) {
		if (i != a && battle->fight[id]->enemy[i]->alive) {
			pos.x = MAP_X + battle->fight[id]->enemy[i]->
				pos.x * B_X + 15;
			pos.y = MAP_Y + battle->fight[id]->enemy[i]->
				pos.y * B_Y - 5;
			sfSprite_setPosition
				(battle->fight[id]->enemy[i]->form, pos);
			sfRenderWindow_drawSprite(rpg->win,
				battle->fight[id]->enemy[i]->form, NULL);
		}
	}
}

static void draw_anim(rpg_t *rpg, battle_t *battle, int x)
{
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->fight[battle->id]->enemy[x]->rec.left += 64;
	sfSprite_setTextureRect(
		battle->fight[battle->id]->enemy[x]->form,
		battle->fight[battle->id]->enemy[x]->rec);
	draw_all(rpg);
	display_hero(rpg, battle);
	display_other_enemy(rpg, battle, x);
	sfRenderWindow_drawSprite(rpg->win,
		battle->fight[battle->id]->enemy[x]->form, NULL);
	sfRenderWindow_display(rpg->win);
}

static void anim(rpg_t *rpg, battle_t *battle, int x)
{
	sfVector2f pos = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[x]->form);

	for (int i = 0; i < 9;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.08)))
			battle->time = sfClock_getElapsedTime(battle->clock);
		pos.x += -1 * (B_Y / 8);
		sfSprite_setPosition(
			battle->fight[battle->id]->enemy[x]->form, pos);
		draw_anim(rpg, battle, x);
		i++;
	}
	sfRenderWindow_clear(rpg->win, sfBlack);
}

static void go_left(rpg_t *rpg, battle_t *battle, int x, sfVector2f pos)
{
	pos.x -= 1;
	battle->fight[battle->id]->enemy[x]->pos.x -= 1;
	battle->fight[battle->id]->enemy[x]->rec.top = 64;
	anim(rpg, battle, x);
	battle->fight[battle->id]->enemy[x]->rec.left = 0;
	sfSprite_setTextureRect(
		battle->fight[battle->id]->enemy[x]->form,
		battle->fight[battle->id]->enemy[x]->rec);
	draw_all(rpg);
	display_enemy(rpg, battle);
	display_hero(rpg, battle);
	sfRenderWindow_display(rpg->win);
}

bool enemy_go_left(rpg_t *rpg, battle_t *battle, int x,
		sfVector2f pos)
{
	sfVector2f hero = {battle->hero->pos.x, battle->hero->pos.y};
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
