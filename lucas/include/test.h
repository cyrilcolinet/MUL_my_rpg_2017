/*
** EPITECH PROJECT, 2018
** test
** File description:
** rpg
*/

#ifndef TEST
#define TEST

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "my.h"

typedef struct enemy {
	sfRectangleShape *form;
	sfSprite *spite;
	sfTexture *texture;
	sfVector2f pos;
	int id;
	int hp;
	int dmg;
	int armor;
} enemy_t;

typedef struct fight {
	sfRectangleShape **map;
	sfVector2f pos;
	sfSprite *spite;
	sfTexture *texture;
	int id;
	int number_enemy;
	enemy_t **enemy;
} fight_t;

typedef struct rune {
	sfSprite *sprite;
	sfTexture *texture;
	int id;
	int power;
	int resis;
} rune_t;

typedef struct hero {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	int hp;
	int dmg;
	int armor;
	int rune;
} hero_t;

typedef struct data {
	sfRenderWindow *window;
	int x;
	int y;
	hero_t *hero;
	fight_t **fight;
	int number_fight;
	rune_t **rune;
	int number_rune;
} data_t;

void test(void);

/* FREE */
void free_all(data_t *data);

/* MAP */
void display_map(data_t *data, int id);

/* EVENT */
void event_management(data_t *data);

/* INIT */
void init_data(data_t *data);
void init_fight(data_t *data);
void init_hero(data_t *data);
void init_rune(data_t *data);

#endif
