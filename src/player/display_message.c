/*
** EPITECH PROJECT, 2018
** display_message
** File description:
** rpg
*/

#include "rpg.h"

static void check_map(rpg_t *rpg, map_t *map, int i, quest_t *quest)
{
	sfText_setString(rpg->text, map->it[i]->msg[0]);
	if (i == 1 && quest->id < 4)
		sfText_setString(rpg->text, map->it[i]->msg[1]);
	else if (i == 1 && quest->id > 4)
		sfText_setString(rpg->text, map->it[i]->msg[2]);
	if (i == 2 && quest->id < 6)
		sfText_setString(rpg->text, map->it[i]->msg[1]);
	else if (i == 2 && quest->id > 6)
		sfText_setString(rpg->text, map->it[i]->msg[2]);
	if (i == 3 && quest->id < 1)
		sfText_setString(rpg->text, map->it[i]->msg[1]);
	else if (i == 3 && quest->id > 1)
		sfText_setString(rpg->text, map->it[i]->msg[2]);
}

static void check_map2(rpg_t *rpg, map_t *map, int i, quest_t *quest)
{
	sfText_setString(rpg->text, map->it[i]->msg[0]);
	if (i == 3 && quest->id < 9)
		sfText_setString(rpg->text, map->it[i]->msg[1]);
	else if (i == 3 && quest->id == 9)
		sfText_setString(rpg->text, map->it[i]->msg[0]);
	else
		sfText_setString(rpg->text, map->it[i]->msg[2]);
}

void display_message(rpg_t *rpg, int id, int i, quest_t *quest)
{
	if (id == 0)
		check_map(rpg, rpg->map[0], i, quest);
	else if (id == 1)
		check_map2(rpg, rpg->map[1], i, quest);
	sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
}
