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
	sfVector2f pos = {1600, 150};

	mode.width = 1920;
	mode.height = 1080;
	mode.bitsPerPixel = 32;
	data->window = sfRenderWindow_create(mode, "test", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(data->window, 30);
	data->map = malloc(sizeof(int *) * 10);
	for (int i = 0; i < 10; i++) {
		data->map[i] = malloc(sizeof(int) * 12);
		for (int n = 0; n < 12; n++)
			data->map[i][n] = 0;
	}
	data->font = sfFont_createFromFile("./Cyberspace.otf");
	data->text = create_text(data->font, "Interface", pos, sfWhite);
	init_fight(data);
	init_hero(data);
	init_rune(data);
}
