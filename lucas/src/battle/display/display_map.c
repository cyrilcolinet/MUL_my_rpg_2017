/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** rpg
*/

#include "battle.h"

void display_hero(data_t *data, battle_t *battle)
{
	sfVector2f pos;

	pos.x = MAP_X + battle->hero->pos.x * B_X + 15;
	pos.y = MAP_Y + battle->hero->pos.y * B_Y - 5;
	sfSprite_setPosition(battle->hero->form, pos);
	sfRenderWindow_drawSprite
		(data->window, battle->hero->form, NULL);
}

void display_enemy(data_t *data, battle_t *battle)
{
	sfVector2f pos;
	int id = battle->id;

	for (int i = 0; i < battle->fight[id]->number_enemy; i++) {
		if (battle->fight[id]->enemy[i]->alive) {
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

void display_map(data_t *data, battle_t *battle, int id)
{
	for (int i = 0; i < 120; i++) {
		sfRenderWindow_drawRectangleShape
			(data->window, battle->fight[id]->map[i], NULL);
	}
}
