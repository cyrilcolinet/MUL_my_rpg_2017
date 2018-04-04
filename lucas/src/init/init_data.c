/*
** EPITECH PROJECT, 2018
** init_data
** File description:
** rpg
*/

#include "test.h"

void init_data(data_t *data)                                                 
{
	sfVideoMode mode;

	mode.width = 1920;
	mode.height = 1080;
	mode.bitsPerPixel = 32;
	data->window = sfRenderWindow_create(mode, "test", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(data->window, 30);

	data->x = 56;
	data->x = 43;
	init_fight(data);
	init_hero(data);
	init_rune(data);
}
