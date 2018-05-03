/*
** EPITECH PROJECT, 2018
** free
** File description:
** rpg
*/

#include "battle.h"

static void free_fight(battle_t *battle, int n)
{
	for (int i = 0; i < 120; i++) {
		sfRectangleShape_destroy(battle->fight[n]->map[i]);
	}
	free(battle->fight[n]->map);
	for (int i = 0; i < battle->fight[n]->number_enemy; i++) {
		sfRectangleShape_destroy(battle->fight[n]->enemy[i]->form);
		sfRectangleShape_destroy(battle->fight[n]->enemy[i]->frame);
		free(battle->fight[n]->enemy[i]);
	}
	free(battle->fight[n]->enemy);
	free(battle->fight[n]);
}

void free_all(data_t *data)
{
	for (int i = 0; i < data->battle->number_fight; i++) {
		free_fight(data->battle, i);
	}
	free(data->battle->fight);
	sfRectangleShape_destroy(data->battle->hero->form);
	sfText_destroy(data->battle->text);
	sfFont_destroy(data->battle->font);
	free(data->battle->hero);
	for (int i = 0; i < 10; i++)
		free(data->battle->map[i]);
	free(data->battle->map);
	sfRectangleShape_destroy(data->battle->icone);
	sfRectangleShape_destroy(data->battle->background);
	for (int i = 0; i < 4; i++)
		sfTexture_destroy(data->battle->texture[i]);
	free(data->battle->texture);
	free(data->battle);
	sfRenderWindow_destroy(data->window);
	free(data);
}
