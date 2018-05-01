/*
** EPITECH PROJECT, 2018
** init_data
** File description:
** rpg
*/

#include "test.h"

static void init_texture(data_t *data, sfVector2f pos)
{
	data->icone = sfRectangleShape_create();
	pos.x = 30;
	pos.y = 10;
	sfRectangleShape_setPosition(data->icone, pos);
	pos.x = 20;
	pos.y = 20;
	sfRectangleShape_setSize(data->icone, pos);
	data->texture = malloc(sizeof(sfTexture *) * 4);
	data->texture[0] = sfTexture_createFromFile("src/image/hp.png", NULL);
	data->texture[1] = sfTexture_createFromFile("src/image/dmg.png", NULL);
	data->texture[2] = sfTexture_createFromFile
		("src/image/armor.png", NULL);
	data->texture[3] = sfTexture_createFromFile("src/image/map.png", NULL);
	data->background = sfRectangleShape_create();
	pos.x = 0;
	pos.y = 0;
	sfRectangleShape_setPosition(data->background, pos);
	pos.x = 1920;
	pos.y = 1080;
	sfRectangleShape_setSize(data->background, pos);
	sfRectangleShape_setTexture(data->background, data->texture[3], sfTrue);
}

void init_data(data_t *data)
{
	sfVideoMode mode;
	sfVector2f pos = {1600, 50};

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
	init_texture(data, pos);
}
