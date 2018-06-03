/*
** EPITECH PROJECT, 2018
** destroy_player
** File description:
** rpg
*/

#include "rpg.h"

static void destroy_quest(quest_t *quest)
{
	sfRectangleShape_destroy(quest->win);
	free(quest->unlock);
	free(quest->done);
	for (int i = 0; i < 3; i++) {
		my_freetab(quest->pnj[i]->dialogue);
		sfSprite_destroy(quest->pnj[i]->sprite);
		free(quest->pnj[i]);
	}
	free(quest->pnj);
	free(quest);
}

static void destroy_equipement(inventory_t *inv)
{
	for (int i = 0; i < 4; i++) {
		free(inv->obj[i]);
	}
	free(inv->obj);
}

static void destroy_inventory(inventory_t *inv)
{
	sfRectangleShape_destroy(inv->win);
	sfRectangleShape_destroy(inv->current);
	sfRectangleShape_destroy(inv->armor);
	sfRectangleShape_destroy(inv->weapon);
	for (int i = 0; i < 12; i++)
		sfRectangleShape_destroy(inv->slot[i]);
	free(inv->slot);
	destroy_equipement(inv);
	free(inv);
}

void destroy_player(rpg_t *rpg)
{
	sfClock_destroy(rpg->player->clock);
	free(rpg->player->name);
	sfSprite_destroy(rpg->player->sprite);
	destroy_inventory(rpg->player->inventory);
	destroy_quest(rpg->player->quest);
	free(rpg->player);
}
