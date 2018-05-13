/*
** EPITECH PROJECT, 2018
** display_interface
** File description:
** rpg
*/

#include "rpg.h"

static void display_icone(rpg_t *rpg, sfVector2f pos, int id)
{
	sfRectangleShape_setPosition(rpg->battle->icone, pos);
	sfRectangleShape_setTexture(rpg->battle->icone,
		rpg->battle->texture[id], sfTrue);
	sfRenderWindow_drawRectangleShape(rpg->win,
		rpg->battle->icone, NULL);
}

static void display_stat_hero(rpg_t *rpg, sfVector2f pos, int id)
{
	char *str = NULL;

	sfText_setPosition(rpg->battle->text, pos);
	if (id == 0)
		str = my_itoa(rpg->battle->hero->hp);
	else if (id == 1)
		str = my_itoa(rpg->battle->hero->dmg);
	if (id == 2)
		str = my_itoa(rpg->battle->hero->armor);
	sfText_setString(rpg->battle->text, str);
	free(str);
	sfRenderWindow_drawText(rpg->win, rpg->battle->text, NULL);
}

void display_interface(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos;
	sfVector2f coord = {1630, 200};

	display_enemy_stats(rpg, coord);
	pos.x = 10;
	pos.y = 200;
	sfText_setPosition(battle->text, pos);
	sfText_setString(battle->text, "Hero");
	sfRenderWindow_drawText(rpg->win, battle->text, NULL);
	pos.y += 30;
	display_icone(rpg, pos, 0);
	pos.x += 30;
	display_stat_hero(rpg, pos, 0);
	pos.x = 10;
	pos.y += 30;
	display_icone(rpg, pos, 1);
	pos.x += 30;
	display_stat_hero(rpg, pos, 1);
	pos.x = 10;
	pos.y += 30;
	display_icone(rpg, pos, 2);
	pos.x += 30;
	display_stat_hero(rpg, pos, 2);
}
