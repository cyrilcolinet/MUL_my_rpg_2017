/*
** EPITECH PROJECT, 2018
** enemy_deplacement_anim
** File description:
** rpg
*/

#include "battle.h"

static void display_other_enemy(data_t *data, battle_t *battle, int x)
{
	sfVector2f pos;
	int id = battle->id;

	for (int i = 0; i < battle->fight[id]->number_enemy; i++) {
		if (i != x && battle->fight[id]->enemy[i]->alive) {
			pos.x = MAP_X + battle->fight[id]->enemy[i]->
				pos.x * B_X + 15;
			pos.y = MAP_Y + battle->fight[id]->enemy[i]->
				pos.y * B_Y - 5;
			sfSprite_setPosition
				(battle->fight[id]->enemy[i]->form, pos);
			sfRenderWindow_drawSprite(data->window,
				battle->fight[id]->enemy[i]->form, NULL);
		}
	}
}

static void draw_anim(data_t *data, battle_t *battle, int x)
{
	sfRenderWindow_clear(data->window, sfBlack);
	battle->fight[battle->id]->enemy[x]->rec.left += 64;
	sfSprite_setTextureRect(
		battle->fight[battle->id]->enemy[x]->form,
		battle->fight[battle->id]->enemy[x]->rec);
	draw_all(data);
	display_hero(data, battle);
	display_other_enemy(data, battle, x);
	sfRenderWindow_drawSprite(data->window,
		battle->fight[battle->id]->enemy[x]->form, NULL);
	sfRenderWindow_display(data->window);
}

static void anim(data_t *data, battle_t *battle, int x)
{
	sfVector2f pos = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[x]->form);

	for (int i = 0; i < 9;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.08)))
			battle->time = sfClock_getElapsedTime(battle->clock);
		pos.y += 1 * (B_Y / 8);
		sfSprite_setPosition(
			battle->fight[battle->id]->enemy[x]->form, pos);
		draw_anim(data, battle, x);
		i++;
	}
	sfRenderWindow_clear(data->window, sfBlack);
	battle->fight[battle->id]->enemy[x]->rec.left = 0;
	sfSprite_setTextureRect(
		battle->fight[battle->id]->enemy[x]->form,
		battle->fight[battle->id]->enemy[x]->rec);
}

bool enemy_go_down(data_t *data, battle_t *battle, int x,
		sfVector2f pos)
{
	sfVector2f hero = {battle->hero->pos.x, battle->hero->pos.y};
	int b = hero.y - pos.y;
	int c = pos.y;
	int d = pos.x;

	if (pos.y <= 8 && b > 0 && battle->map[c + 1][d] == 0) {
		pos.y += 1;
		battle->fight[battle->id]->enemy[x]->pos.y += 1;
		battle->fight[battle->id]->enemy[x]->rec.top = 128;
		anim(data, battle, x);
		draw_all(data);
		display_enemy(data, battle);
		display_hero(data, battle);
		sfRenderWindow_display(data->window);
		return (true);
	}
	return (false);
}
