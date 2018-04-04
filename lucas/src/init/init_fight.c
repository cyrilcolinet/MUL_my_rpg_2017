/*
** EPITECH PROJECT, 2018
** init_fight
** File description:
** rpg
*/

#include "test.h"

static void create_map(fight_t *fight)
{
	sfVector2f size = {114, 72};
	int nb = 0;

	fight->pos.x = 224;
	fight->pos.y = 129;
	fight->map = malloc(sizeof(sfRectangleShape *) * 120);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			fight->map[nb] = sfRectangleShape_create();
			sfRectangleShape_setPosition(fight->map[nb], fight->pos);
			sfRectangleShape_setSize(fight->map[nb], size);
			sfRectangleShape_setFillColor(fight->map[nb], sfTransparent);
			sfRectangleShape_setOutlineColor(fight->map[nb], sfColor_fromRGB(125, 125, 135));
			sfRectangleShape_setOutlineThickness(fight->map[nb], 1);
			fight->pos.x += 114;
			nb++;
		}
		fight->pos.x = 224;
		fight->pos.y += 72;
	}
}

static void enemy_form(enemy_t *enemy)
{
	sfVector2f size = {45, 60};
	
	enemy->form = sfRectangleShape_create();
	sfRectangleShape_setPosition(enemy->form, enemy->pos);
	sfRectangleShape_setSize(enemy->form, size);
	sfRectangleShape_setFillColor(enemy->form, sfRed);
	sfRectangleShape_setOutlineColor(enemy->form, sfWhite);
	sfRectangleShape_setOutlineThickness(enemy->form, 1);
}

static fight_t *create_fight(void)
{
	fight_t *fight;

	fight = malloc(sizeof(fight_t));
	create_map(fight);
	fight->number_enemy = 5;
	return (fight);
}

static enemy_t *create_enemy(int nb)
{
	enemy_t *enemy;

	enemy = malloc(sizeof(enemy_t));
	enemy->pos.x = 1400;
	enemy->pos.y = 208 + nb * 72;
	enemy_form(enemy);
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
		data->fight[i]->id = i;
		data->fight[i]->enemy = malloc(sizeof(enemy_t *)
					* data->fight[i]->number_enemy);
		for (int j = 0; j < data->fight[i]->number_enemy; j++) {
			data->fight[i]->enemy[j] = create_enemy(j);
			data->fight[i]->enemy[j]->id = j;
		}
	}
}
