/*
** EPITECH PROJECT, 2018
** hero_attack
** File description:
** rpg
*/

#include "battle.h"

static void attack_anim(data_t *data, battle_t *battle, sfVector2f pos)
{
	int x = pos.x;
	int y = pos.y;

	battle->time = sfTime_Zero;
	sfClock_restart(battle->clock);
	while (sfTime_asSeconds(battle->time)
	< sfTime_asSeconds(sfSeconds(1))) {
		battle->time = sfClock_getElapsedTime(battle->clock);
		sfRectangleShape_setFillColor
		(battle->fight[battle->id]->map[y * 12 + x], sfWhite);
		draw_all(data);
		display_enemy(data, battle);
		display_hero(data, battle);
		sfRenderWindow_display(data->window);
	}
	sfRectangleShape_setFillColor
	(battle->fight[battle->id]->map[y * 12 + x], sfTransparent);
	draw_all(data);
	display_enemy(data, battle);
	display_hero(data, battle);
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
		attack_anim(data, battle, pos);
		battle->hero->attack = true;
		battle->fight[battle->id]->enemy[i]->hp -= battle->hero->dmg;
		battle->hero->target = -1;
		if (battle->fight[battle->id]->enemy[i]->hp <= 0)
			battle->fight[battle->id]->enemy[i]->alive = false;
	}
}
