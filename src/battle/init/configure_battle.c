/*
** EPITECH PROJECT, 2018
** init_battle
** File description:
** rpg
*/

#include "rpg.h"

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
	battle->texture[0] = sfTexture_createFromFile("assets/icone/hp.png", NULL);
	battle->texture[1] = sfTexture_createFromFile("assets/icone/dmg.png", NULL);
	battle->texture[2] = sfTexture_createFromFile
		("assets/icone/armor.png", NULL);
	battle->texture[3] = sfTexture_createFromFile("assets/map/fight_3.png", NULL);
	battle->background = sfRectangleShape_create();
	pos.x = 0;
	pos.y = 0;
	sfRectangleShape_setPosition(battle->background, pos);
	pos.x = 1920;
	pos.y = 1080;
	sfRectangleShape_setSize(battle->background, pos);
	sfRectangleShape_setTexture(battle->background, battle->texture[3], sfTrue);
}

void configure_battle(rpg_t *rpg)
{
	sfVector2f pos = {1600, 50};

	rpg->battle = malloc(sizeof(battle_t));
	rpg->battle->map = malloc(sizeof(int *) * 10);
	for (int i = 0; i < 10; i++) {
		rpg->battle->map[i] = malloc(sizeof(int) * 12);
		for (int n = 0; n < 12; n++)
			rpg->battle->map[i][n] = 0;
	}
	rpg->battle->font = sfFont_createFromFile("./Cyberspace.otf");
	rpg->battle->text = create_text(rpg->battle->font, "Interface", pos, sfWhite);
	rpg->battle->clock = sfClock_create();
	init_fight(rpg->battle);
	init_hero(rpg->battle);
	init_texture(rpg->battle, pos);
}
