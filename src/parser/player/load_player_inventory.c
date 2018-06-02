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

	inventory->win = sfRectangleShape_create();
	inventory->armor = sfRectangleShape_create();
	inventory->weapon = sfRectangleShape_create();
	inventory->current = sfRectangleShape_create();
	inventory->slot = malloc(sizeof(sfRectangleShape *) * 13);
	inventory->slot[12] = NULL;
	for (int i = 0; i < 12; i++) {
		inventory->slot[i] = sfRectangleShape_create();
	}
	inventory->mouse.x = 0;
	inventory->mouse.y = 0;
	return (inventory);
}

static void init_skin_win(inventory_t *inv)
{
	sfVector2f pos = {260, 240};
	sfVector2f size = {1500, 600};

	sfRectangleShape_setPosition(inv->win, pos);
	sfRectangleShape_setSize(inv->win, size);
	sfRectangleShape_setFillColor(inv->win, sfWhite);
	pos.x = 810;
	pos.y = 340;
	size.x = size.y = 100;
}

static void init_slot(inventory_t *inv)
{
	sfVector2f pos = {1110, 340};
	sfVector2f size = {100, 100};

	sfRectangleShape_setPosition(inv->current, pos);
	sfRectangleShape_setSize(inv->current, size);
	sfRectangleShape_setFillColor(inv->current, sfRed);
	for (int i = 0; i < 12; i++) {
		sfRectangleShape_setPosition(inv->slot[i], pos);
		sfRectangleShape_setSize(inv->slot[i], size);
		sfRectangleShape_setFillColor(inv->slot[i], sfBlue);
		pos.x += 150;
		if (i % 4 == 3) {
			pos.y += 150;
			pos.x = 1110;
		}
	}
}

static void init_weapon_armor(inventory_t *inv)
{
	sfVector2f pos = {610, 340};
	sfVector2f size = {100, 100};

	sfRectangleShape_setPosition(inv->armor, pos);
	sfRectangleShape_setSize(inv->armor, size);
	sfRectangleShape_setFillColor(inv->armor, sfRed);
	pos.y += 200;
	sfRectangleShape_setPosition(inv->weapon, pos);
	sfRectangleShape_setSize(inv->weapon, size);
	sfRectangleShape_setFillColor(inv->weapon, sfRed);
}

void load_player_inventory(rpg_t *rpg)
{
	rpg->player->inventory = configure_inventory(rpg->player);
	init_skin_win(rpg->player->inventory);
	init_slot(rpg->player->inventory);
	init_weapon_armor(rpg->player->inventory);
}
