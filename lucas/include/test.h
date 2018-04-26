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
	bool select;
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
	bool select;
	int hp;
	int dmg;
	int armor;
	int rune;
} hero_t;

typedef struct data {
	sfRenderWindow *window;
	hero_t *hero;
	fight_t **fight;
	rune_t **rune;
	sfVector2f mouse;
	sfFont *font;
	sfText *text;
	int **map;
	int id;
	int number_fight;
	int number_rune;
} data_t;

void test(void);

/* FREE */
void free_all(data_t *data);

/* MAP */
void display_map(data_t *data, int id);
void display_interface(data_t *data);
void fill_map_state(data_t *data, int id);

/* EVENT */
void event_management(data_t *data);

/*EVENT->DEPLACEMENT*/
void deplacement(data_t *data, sfEvent event);
void reset_map_state(data_t *data);
void hero_deplacement(data_t *data, int i, sfVector2f pos);
void enemy_deplacement(data_t *data, int i, int x, sfVector2f pos);
void select_or_unselect(data_t *data, int i);
void check_deplacement(data_t *data);

/*EVENT->DEPLACEMENT*/
void attack(data_t *data, sfEvent event);

/* INIT */
void init_data(data_t *data);
void init_fight(data_t *data);
void init_hero(data_t *data);
void init_rune(data_t *data);

sfText *create_text(sfFont *font, char *str, sfVector2f pos, sfColor color);

#endif
