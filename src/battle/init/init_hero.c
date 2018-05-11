/*
** EPITECH PROJECT, 2018
** init_hero
** File description:
** rpg
*/

#include "rpg.h"

void init_hero(battle_t *battle)
{
	sfVector2f scale = {1.25, 1.25};

	battle->hero = malloc(sizeof(hero_t));
	battle->hero->pos.x = 0;
	battle->hero->pos.y = 5;
	battle->hero->alive = true;
	battle->hero->played = false;
	battle->hero->select = false;
	battle->hero->move = false;
	battle->hero->attack = false;
	battle->hero->sword = true;
	battle->hero->target = -1;
	battle->hero->hp = 120;
	battle->hero->dmg = 67;
	battle->hero->armor = 7;
	battle->hero->rec.top = 192;
	battle->hero->rec.left = 0;
	battle->hero->rec.width = 64;
	battle->hero->rec.height = 64;
	battle->hero->form = sfSprite_create();
	sfSprite_setPosition(battle->hero->form, battle->hero->pos);
	battle->hero->img = sfTexture_createFromFile(
		"assets/champion/man_fer_sword.png", NULL);
	sfSprite_setTexture(battle->hero->form, battle->hero->img, true);
	sfSprite_setTextureRect(battle->hero->form, battle->hero->rec);
	sfSprite_setScale(battle->hero->form, scale);
}
