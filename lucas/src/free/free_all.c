/*
** EPITECH PROJECT, 2018
** free
** File description:
** rpg
*/

#include "test.h"

static void free_fight(data_t *data, int n)
{
	for (int i = 0; i < 120; i++) {
		sfRectangleShape_destroy(data->fight[n]->map[i]);
	}
	free(data->fight[n]->map);
	for (int i = 0; i < data->fight[n]->number_enemy; i++) {
		sfRectangleShape_destroy(data->fight[n]->enemy[i]->form);
		free(data->fight[n]->enemy[i]);
	}
	free(data->fight[n]->enemy);
	free(data->fight[n]);
}

void free_all(data_t *data)
{
	for (int i = 0; i < data->number_fight; i++)
		free_fight(data, i);
	free(data->fight);
	sfRenderWindow_destroy(data->window);
	free(data);
}
