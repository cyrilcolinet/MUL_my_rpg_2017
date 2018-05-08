/*
** EPITECH PROJECT, 2018
** enemy_attack_anim.c
** File description:
** rpg
*/

#include "battle.h"

void enemy_attack_anim(data_t *data, battle_t *battle, sfVector2f pos)
{
	int x = pos.x;
	int y = pos.y;

	battle->time = sfTime_Zero;
	sfClock_restart(battle->clock);
	while (sfTime_asSeconds(battle->time)
	< sfTime_asSeconds(sfSeconds(1))) {
		battle->time = sfClock_getElapsedTime(battle->clock);
		sfRectangleShape_setFillColor
			(battle->fight[battle->id]->map[y * 12 + x], sfBlue);
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
