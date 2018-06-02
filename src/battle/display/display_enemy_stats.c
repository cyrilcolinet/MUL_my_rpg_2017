/*
** EPITECH PROJECT, 2018
** display_enemy_stats
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

static void display_stat(rpg_t *rpg, sfVector2f pos, int i, int id)
{
	char *str = NULL;

	sfText_setPosition(rpg->battle->text, pos);
	if (id == 0)
		str = my_itoa(rpg->battle->
			fight[rpg->battle->id]->enemy[i]->hp);
	else if (id == 1)
		str = my_itoa(rpg->battle->
			fight[rpg->battle->id]->enemy[i]->dmg);
	if (id == 2)
		str = my_itoa(rpg->battle->
			fight[rpg->battle->id]->enemy[i]->armor);
	else if (id == 4)
		str = my_itoa(i + 1);
	sfText_setString(rpg->battle->text, str);
	free(str);
	sfRenderWindow_drawText(rpg->win, rpg->battle->text, NULL);
}

static void display_info(rpg_t *rpg, sfVector2f coord, int i)
{
	sfVector2f pos = {coord.x, coord.y + 40};

	pos.x = coord.x + 75;
	display_icone(rpg, pos, 0);
	pos.x += 30;
	display_stat(rpg, pos, i, 0);
	pos.x = coord.x + 75;
	pos.y += 25;
	display_icone(rpg, pos, 1);
	pos.x += 30;
	display_stat(rpg, pos, i, 1);
	pos.x = coord.x + 75;
	pos.y += 25;
	display_icone(rpg, pos, 2);
	pos.x += 30;
	display_stat(rpg, pos, i, 2);
}

static void display_name_frame(rpg_t *rpg, sfVector2f coord, int i)
{
	sfVector2f pos = {coord.x, coord.y};

	sfText_setPosition(rpg->battle->text, pos);
	sfText_setString(rpg->battle->text, "Enemy");
	sfRenderWindow_drawText(rpg->win, rpg->battle->text, NULL);
	pos.x += 70;
	display_stat(rpg, pos, i, 4);
	pos.x = coord.x;
	pos.y += 40;
	sfRectangleShape_setPosition(
	rpg->battle->fight[rpg->battle->id]->enemy[i]->frame, pos);
	sfRenderWindow_drawRectangleShape(rpg->win,
	rpg->battle->fight[rpg->battle->id]->enemy[i]->frame, NULL);
}

void display_enemy_stats(rpg_t *rpg, sfVector2f coord)
{
	sfVector2f pos;

	if (rpg->battle->fight[rpg->battle->id]->number_enemy < 6)
		coord.x += 80;
	for (int i = 0; i < rpg->battle->fight
		[rpg->battle->id]->number_enemy; i++) {
		if (i < 6) {
			pos.x = coord.x;
			pos.y = (i) * 120 + coord.y;
		} else if (i > 5) {
			pos.x = coord.x + 150;
			pos.y = (i - 6) * 120 + coord.y;
		}
		display_name_frame(rpg, pos, i);
		display_info(rpg, pos, i);
	}
}
