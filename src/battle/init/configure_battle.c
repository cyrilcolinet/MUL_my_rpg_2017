/*
** EPITECH PROJECT, 2018
** init_battle
** File description:
** rpg
*/

#include "battle.h"

static void init_texture(battle_t *battle, sfVector2f pos)
{
	battle->icone = sfRectangleShape_create();
	pos.x = 30;
	pos.y = 10;
	sfRectangleShape_setPosition(battle->icone, pos);
	pos.x = 20;
	pos.y = 20;
	sfRectangleShape_setSize(battle->icone, pos);
	battle->texture = malloc(sizeof(sfTexture *) * 4);
	battle->texture[0] = sfTexture_createFromFile("src/battle/image/hp.png", NULL);
	battle->texture[1] = sfTexture_createFromFile("src/battle/image/dmg.png", NULL);
	battle->texture[2] = sfTexture_createFromFile
		("src/battle/image/armor.png", NULL);
	battle->texture[3] = sfTexture_createFromFile("src/battle/image/fight_3.png", NULL);
	battle->background = sfRectangleShape_create();
	pos.x = 0;
	pos.y = 0;
	sfRectangleShape_setPosition(battle->background, pos);
	pos.x = 1920;
	pos.y = 1080;
	sfRectangleShape_setSize(battle->background, pos);
	sfRectangleShape_setTexture(battle->background, battle->texture[3], sfTrue);
}

void init_data(data_t *data)
{
	sfVideoMode mode;
	sfVector2f pos = {1600, 50};

	mode.width = 1920;
	mode.height = 1080;
	mode.bitsPerPixel = 32;
	data->window = sfRenderWindow_create(mode, "test", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(data->window, 60);
	data->battle = malloc(sizeof(battle_t));
	data->battle->map = malloc(sizeof(int *) * 10);
	for (int i = 0; i < 10; i++) {
		data->battle->map[i] = malloc(sizeof(int) * 12);
		for (int n = 0; n < 12; n++)
			data->battle->map[i][n] = 0;
	}
	data->battle->font = sfFont_createFromFile("./Cyberspace.otf");
	data->battle->text = create_text(data->battle->font, "Interface", pos, sfWhite);
	data->battle->clock = sfClock_create();
	init_fight(data->battle);
	init_hero(data->battle);
	init_texture(data->battle, pos);
}
