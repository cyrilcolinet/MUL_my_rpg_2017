/*
** EPITECH PROJECT, 2018
** enemy_deplacement_anim
** File description:
** rpg
*/

#include "battle.h"

static void anim(data_t *data, battle_t *battle, sfVector2f pos)
{
	int x = pos.x;
	int y = pos.y;

	battle->time = sfTime_Zero;
	sfClock_restart(battle->clock);
	while (sfTime_asSeconds(battle->time)
	< sfTime_asSeconds(sfSeconds(0.15))) {
		battle->time = sfClock_getElapsedTime(battle->clock);
		sfRectangleShape_setFillColor
			(battle->fight[battle->id]->map[y * 12 + x], sfYellow);
		draw_all(data);
		sfRenderWindow_display(data->window);
	}
	sfRectangleShape_setFillColor
		(battle->fight[battle->id]->map[y * 12 + x], sfTransparent);
	draw_all(data);
}

bool enemy_go_right(data_t *data, battle_t *battle, int x,
		sfVector2f pos)
{
	sfVector2f hero = {battle->hero->pos.x, battle->hero->pos.y};
	int a = hero.x - pos.x;
	int b = pos.y - hero.y;
	int c = pos.y;
	int d = pos.x;

	if (pos.x <= 10 && a > 0 && battle->map[c][d + 1] == 0 ) {
		if (abs(b) > a && ((c >= 1 && battle->map[c - 1][d] == 0)
			|| (c <= 8 && battle->map[c + 1][d] == 0)))
			return (false);
		if (a > 0) {
			pos.x += 1;
			battle->fight[battle->id]->enemy[x]->pos.x += 1;
			sfRectangleShape_setPosition(
				battle->fight[battle->id]->enemy[x]->form, pos);
			anim(data, battle, pos);
			return (true);
		} else if (a == 0 && ((c >= 1 && battle->map[c - 1][d] != 0)
			|| (c <= 8 && battle->map[c + 1][d] != 0))) {
			pos.x += 1;
			battle->fight[battle->id]->enemy[x]->pos.x += 1;
			sfRectangleShape_setPosition(
				battle->fight[battle->id]->enemy[x]->form, pos);
			anim(data, battle, pos);
			return (true);
		}
	}
	return (false);
}
