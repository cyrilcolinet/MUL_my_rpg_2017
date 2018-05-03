/*
** EPITECH PROJECT, 2018
** display_interface
** File description:
** rpg
*/

#include "battle.h"

static void display_icone(data_t *data, sfVector2f pos, int id)
{
	sfRectangleShape_setPosition(data->battle->icone, pos);
	sfRectangleShape_setTexture(data->battle->icone,
		data->battle->texture[id], sfTrue);
	sfRenderWindow_drawRectangleShape(data->window,
		data->battle->icone, NULL);
}

static void display_stat_hero(data_t *data, sfVector2f pos, int id)
{
	char *str = NULL;

	sfText_setPosition(data->battle->text, pos);
	if (id == 0)
		str = my_itoa(data->battle->hero->hp);
	else if (id == 1)
		str = my_itoa(data->battle->hero->dmg);
	if (id == 2)
		str = my_itoa(data->battle->hero->armor);
	sfText_setString(data->battle->text, str);
	free(str);
	sfRenderWindow_drawText(data->window, data->battle->text, NULL);
}

void display_interface(data_t *data, battle_t *battle)
{
	sfVector2f pos;
	sfVector2f coord = {1630, 200};

	display_enemy_stats(data, coord);
	if (battle->hero->select) {
		pos.x = 10;
		pos.y = 200;
		sfText_setPosition(battle->text, pos);
		sfText_setString(battle->text, "Hero");
		sfRenderWindow_drawText(data->window, battle->text, NULL);
		pos.y += 30;
		display_icone(data, pos, 0);
		pos.x += 30;
		display_stat_hero(data, pos, 0);
		pos.x = 10;
		pos.y += 30;
		display_icone(data, pos, 1);
		pos.x += 30;
		display_stat_hero(data, pos, 1);
		pos.x = 10;
		pos.y += 30;
		display_icone(data, pos, 2);
		pos.x += 30;
		display_stat_hero(data, pos, 2);
	}
}
