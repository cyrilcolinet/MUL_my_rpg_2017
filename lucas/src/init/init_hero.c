/*
** EPITECH PROJECT, 2018
** init_hero
** File description:
** rpg
*/

#include "test.h"

void init_hero(data_t *data)
{
	sfVector2f size = {45, 60};

	data->hero = malloc(sizeof(hero_t));
	data->hero->pos.x = 0;
	data->hero->pos.y = 5;
	data->hero->alive = true;
	data->hero->played = false;
	data->hero->select = false;
	data->hero->move = false;
	data->hero->attack = false;
	data->hero->hp = 120;
	data->hero->dmg = 67;
	data->hero->armor = 7;
	data->hero->form = sfRectangleShape_create();
	sfRectangleShape_setPosition(data->hero->form, data->hero->pos);
	sfRectangleShape_setSize(data->hero->form, size);
	sfRectangleShape_setFillColor(data->hero->form, sfBlue);
	sfRectangleShape_setOutlineColor(data->hero->form, sfWhite);
	sfRectangleShape_setOutlineThickness(data->hero->form, 1);
}
