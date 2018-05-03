/*
** EPITECH PROJECT, 2018
** init_hero
** File description:
** rpg
*/

#include "battle.h"

void init_hero(battle_t *battle)
{
	sfVector2f size = {45, 60};

	battle->hero = malloc(sizeof(hero_t));
	battle->hero->pos.x = 0;
	battle->hero->pos.y = 5;
	battle->hero->alive = true;
	battle->hero->played = false;
	battle->hero->select = false;
	battle->hero->move = false;
	battle->hero->attack = false;
	battle->hero->hp = 120;
	battle->hero->dmg = 67;
	battle->hero->armor = 7;
	battle->hero->form = sfRectangleShape_create();
	sfRectangleShape_setPosition(battle->hero->form, battle->hero->pos);
	sfRectangleShape_setSize(battle->hero->form, size);
	sfRectangleShape_setFillColor(battle->hero->form, sfBlue);
	sfRectangleShape_setOutlineColor(battle->hero->form, sfWhite);
	sfRectangleShape_setOutlineThickness(battle->hero->form, 1);
}
