/*
** EPITECH PROJECT, 2018
** display_enemy_stats
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

static void display_stat(data_t *data, sfVector2f pos, int i, int id)
{
	char *str = NULL;

	sfText_setPosition(data->battle->text, pos);
	if (id == 0)
		str = my_itoa(data->battle->
			fight[data->battle->id]->enemy[i]->hp);
	else if (id == 1)
		str = my_itoa(data->battle->
			fight[data->battle->id]->enemy[i]->dmg);
	if (id == 2)
		str = my_itoa(data->battle->
			fight[data->battle->id]->enemy[i]->armor);
	else if (id == 4)
		str = my_itoa(i + 1);
	sfText_setString(data->battle->text, str);
	free(str);
	sfRenderWindow_drawText(data->window, data->battle->text, NULL);
}

static void display_info(data_t *data, sfVector2f coord, int i)
{
	sfVector2f pos = {coord.x, coord.y + 20};

	pos.x = coord.x + 75;
	display_icone(data, pos, 0);
	pos.x += 30;
	display_stat(data, pos, i, 0);
	pos.x = coord.x + 75;
	pos.y += 25;
	display_icone(data, pos, 1);
	pos.x += 30;
	display_stat(data, pos, i, 1);
	pos.x = coord.x + 75;
	pos.y += 25;
	display_icone(data, pos, 2);
	pos.x += 30;
	display_stat(data, pos, i, 2);
}

static void display_name_frame(data_t *data, sfVector2f coord, int i)
{
	sfVector2f pos = {coord.x, coord.y};

	sfText_setPosition(data->battle->text, pos);
	sfText_setString(data->battle->text, "Enemy");
	sfRenderWindow_drawText(data->window, data->battle->text, NULL);
	pos.x += 70;
	display_stat(data, pos, i, 4);
	pos.x = coord.x;
	pos.y += 20;
	sfRectangleShape_setPosition(
		data->battle->fight[data->battle->id]->enemy[i]->frame, pos);
	sfRenderWindow_drawRectangleShape(data->window,
		data->battle->fight[data->battle->id]->enemy[i]->frame, NULL);
}

void display_enemy_stats(data_t *data, sfVector2f coord)
{
	sfVector2f pos;

	if (data->battle->fight[data->battle->id]->number_enemy < 6)
		coord.x += 80;
	for (int i = 0; i < data->battle->fight
		[data->battle->id]->number_enemy; i++) {
		if (i < 6) {
			pos.x = coord.x;
			pos.y = (i) * 120 + coord.y;
		} else if (i > 5) {
			pos.x = coord.x + 150;
			pos.y = (i - 6) * 120 + coord.y;
		}
		display_name_frame(data, pos, i);
		display_info(data, pos, i);
	}
}
