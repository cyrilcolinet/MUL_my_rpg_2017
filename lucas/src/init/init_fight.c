/*
** EPITECH PROJECT, 2018
** init_fight
** File description:
** rpg
*/

#include "test.h"

static void create_map(fight_t *fight)
{
	sfVector2f size = {B_X, B_Y};
	int n = 0;

	fight->map = malloc(sizeof(sfRectangleShape *) * 120);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			fight->map[n] = sfRectangleShape_create();
			sfRectangleShape_setPosition(fight->map[n], fight->pos);
			sfRectangleShape_setSize(fight->map[n], size);
			sfRectangleShape_setFillColor
				(fight->map[n], sfTransparent);
			sfRectangleShape_setOutlineColor
				(fight->map[n], sfColor_fromRGB(125, 125, 135));
			sfRectangleShape_setOutlineThickness(fight->map[n], 1);
			fight->pos.x += B_X;
			n++;
		}
		fight->pos.x = MAP_X - 1;
		fight->pos.y += B_Y;
	}
}

static void enemy_form(enemy_t *enemy)
{
	sfVector2f size = {45, 60};

	enemy->form = sfRectangleShape_create();
	sfRectangleShape_setSize(enemy->form, size);
	sfRectangleShape_setFillColor(enemy->form, sfRed);
	sfRectangleShape_setOutlineColor(enemy->form, sfWhite);
	sfRectangleShape_setOutlineThickness(enemy->form, 1);
}

static fight_t *create_fight(void)
{
	fight_t *fight;

	fight = malloc(sizeof(fight_t));
	fight->pos.x = MAP_X - 1;
	fight->pos.y = MAP_Y - 1;
	create_map(fight);
	fight->number_enemy = 5;
	return (fight);
}

static enemy_t *create_enemy(int nb)
{
	enemy_t *enemy;

	enemy = malloc(sizeof(enemy_t));
	enemy->pos.x = 11;
	enemy->pos.y = 0 + nb;
	enemy_form(enemy);
	enemy->select = false;
	enemy->hp = 20;
	enemy->dmg = 5;
	enemy->armor = 1;
	return (enemy);
}

void init_fight(data_t *data)
{
	data->number_fight = 2;
	data->fight = malloc (sizeof(fight_t *) * data->number_fight);
	for (int i = 0; i < data->number_fight; i++) {
		data->fight[i] = create_fight();
		data->fight[i]->enemy = malloc(sizeof(enemy_t *)
					* data->fight[i]->number_enemy);
		for (int j = 0; j < data->fight[i]->number_enemy; j++) {
			data->fight[i]->enemy[j] = create_enemy(j);
		}
	}
}
