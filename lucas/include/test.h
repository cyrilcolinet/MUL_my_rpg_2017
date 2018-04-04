/*
** EPITECH PROJECT, 2018
** test
** File description:
** rpg
*/

#ifndef TEST
#define TEST

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "my.h"

#define MAP_X 225
#define MAP_Y 130
#define B_X 114
#define B_Y 72

typedef struct enemy {
	sfRectangleShape *form;
	sfSprite *spite;
	sfTexture *texture;
	sfVector2f pos;
	int hp;
	int dmg;
	int armor;
} enemy_t;

typedef struct fight {
	sfRectangleShape **map;
	sfVector2f pos;
	sfSprite *spite;
	sfTexture *texture;
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
	sfRectangleShape *form;
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
	int **map;
	hero_t *hero;
	fight_t **fight;
	rune_t **rune;
	int id;
	int number_fight;
	int number_rune;
} data_t;

void test(void);

/* FREE */
void free_all(data_t *data);

/* MAP */
void display_map(data_t *data, int id);
void fill_map_state(data_t *data, int id);

/* EVENT */
void event_management(data_t *data);
void deplacement(data_t *data, sfEvent event);

/* INIT */
void init_data(data_t *data);
void init_fight(data_t *data);
void init_hero(data_t *data);
void init_rune(data_t *data);

#endif
