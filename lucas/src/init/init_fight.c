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
	enemy->frame = sfRectangleShape_create();
	sfRectangleShape_setSize(enemy->form, size);
	size.x = 60;
	size.y = 60;
	sfRectangleShape_setSize(enemy->frame, size);
	sfRectangleShape_setFillColor(enemy->form, sfRed);
	sfRectangleShape_setOutlineColor(enemy->form, sfWhite);
	sfRectangleShape_setOutlineThickness(enemy->form, 1);
	sfRectangleShape_setFillColor(enemy->frame, sfRed);
	sfRectangleShape_setOutlineColor(enemy->frame, sfBlack);
	sfRectangleShape_setOutlineThickness(enemy->frame, 3);
}

static fight_t *create_fight(void)
{
	fight_t *fight;

	fight = malloc(sizeof(fight_t));
	fight->pos.x = MAP_X - 1;
	fight->pos.y = MAP_Y - 1;
	create_map(fight);
	fight->number_enemy = 5;
	fight->enemy_turn = false;
	return (fight);
}

static enemy_t *create_enemy(int nb, int n)
{
	enemy_t *enemy;

	enemy = malloc(sizeof(enemy_t));
	enemy->pos.x = 11 + n;
	enemy->pos.y = 0 + nb;
	enemy_form(enemy);
	enemy->select = false;
	enemy->played = false;
	enemy->alive = true;
	enemy->hp = 20;
	enemy->dmg = 5;
	enemy->armor = 1;
	return (enemy);
}

void init_fight(data_t *data)
{
	data->number_fight = 5;
	data->fight = malloc (sizeof(fight_t *) * data->number_fight);
	for (int i = 0; i < data->number_fight; i++) {
		data->fight[i] = create_fight();
		if (i == 1)
			data->fight[i]->number_enemy = 2;
		if (i == 2)
			data->fight[i]->number_enemy = 7;
		if (i == 3)
			data->fight[i]->number_enemy = 10;
		if (i == 4)
			data->fight[i]->number_enemy = 12;
		data->fight[i]->enemy = malloc(sizeof(enemy_t *)
					* data->fight[i]->number_enemy);
		for (int j = 0; j < data->fight[i]->number_enemy; j++) {
			if (j > 9)
				data->fight[i]->enemy[j] = create_enemy(j - 10, -1);
			else
				data->fight[i]->enemy[j] = create_enemy(j, 0);
		}
	}
}
