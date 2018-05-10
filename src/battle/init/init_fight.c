/*
** EPITECH PROJECT, 2018
** init_fight
** File description:
** rpg
*/

#include "battle.h"

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
			(fight->map[n], sfColor_fromRGBA(125, 125, 135, 90));
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
	sfVector2f size = {60, 60};
	sfVector2f scale = {1.25, 1.25};

	enemy->form = sfSprite_create();
	enemy->rec.top = 64;
	enemy->rec.left = 0;
	enemy->rec.width = 64;
	enemy->rec.height = 64;
	sfSprite_setPosition(enemy->form, enemy->pos);
	enemy->img = sfTexture_createFromFile(
		"src/battle/image/women_fer_knife.png", NULL);
	sfSprite_setTexture(enemy->form, enemy->img, true);
	sfSprite_setTextureRect(enemy->form, enemy->rec);
	sfSprite_setScale(enemy->form, scale);
	enemy->frame = sfRectangleShape_create();
	sfRectangleShape_setSize(enemy->frame, size);
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
	enemy->played = false;
	enemy->alive = true;
	enemy->hp = 20;
	enemy->dmg = 5;
	enemy->armor = 1;
	return (enemy);
}

void init_fight(battle_t *battle)
{
	battle->number_fight = 5;
	battle->fight = malloc (sizeof(fight_t *) * battle->number_fight);
	for (int i = 0; i < battle->number_fight; i++) {
		battle->fight[i] = create_fight();
		if (i == 1)
			battle->fight[i]->number_enemy = 2;
		if (i == 2)
			battle->fight[i]->number_enemy = 7;
		if (i == 3)
			battle->fight[i]->number_enemy = 10;
		if (i == 4)
			battle->fight[i]->number_enemy = 12;
		battle->fight[i]->enemy = malloc(sizeof(enemy_t *)
					* battle->fight[i]->number_enemy);
		for (int j = 0; j < battle->fight[i]->number_enemy; j++) {
			if (j > 9)
				battle->fight[i]->enemy[j] = create_enemy(j - 10, -1);
			else
				battle->fight[i]->enemy[j] = create_enemy(j, 0);
		}
	}
}
