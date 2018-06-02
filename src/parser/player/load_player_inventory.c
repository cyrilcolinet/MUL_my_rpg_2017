/*
** EPITECH PROJECT, 2018
** parse_inventory
** File description:
** rpg
*/

#include "rpg.h"

static inventory_t *configure_inventory(player_t *player)
{
	inventory_t *inventory = malloc(sizeof(inventory_t));

	inventory->skin = sfSprite_create();
	inventory->win = sfRectangleShape_create();
	inventory->current = sfRectangleShape_create();
	inventory->slot = malloc(sizeof(sfRectangleShape *) * 13);
	inventory->slot[12] = NULL;
	for (int i = 0; inventory->slot[i]; i++) {
		inventory->slot[i] = sfRectangleShape_create();
	}
	return (inventory);
}

static void init_skin_win(inventory_t *inv)
{
	sfVector2f pos = {460, 240};
	sfVector2f size = {1000, 600};

	sfRectangleShape_setPosition(inv->win, pos);
	sfRectangleShape_setSize(inv->win, size);
	sfRectangleShape_setFillColor(inv->win, sfWhite);
	pos.x = 810;
	pos.y = 340;
	size.x = size.y = 100;
}

static void init_slot(inventory_t *inv)
{
	sfVector2f pos = {810, 340};
	sfVector2f size = {100, 100};

	sfRectangleShape_setPosition(inv->current, pos);
	sfRectangleShape_setSize(inv->current, size);
	sfRectangleShape_setFillColor(inv->current, sfRed);
	for (int i = 0; inv->slot[i]; i++) {
		sfRectangleShape_setPosition(inv->slot[i], pos);
		sfRectangleShape_setSize(inv->slot[i], size);
		sfRectangleShape_setFillColor(inv->slot[i], sfBlue);
		pos.x += (50 + 100);
		if (i % 4 == 3) {
			pos.y += (50 + 100);
			pos.x = 810;
		}
	}
}

void load_player_inventory(rpg_t *rpg)
{
	rpg->player->inventory = configure_inventory(rpg->player);
	init_skin_win(rpg->player->inventory);
	init_slot(rpg->player->inventory);
}
