/*
** EPITECH PROJECT, 2018
** load_player_equipment
** File description:
** rpg
*/

#include "rpg.h"

static void load_equipment_obj4(inventory_t *inventory)
{
	inventory->obj[3]->unlock = true;
	inventory->obj[3]->pos.x = 3;
	inventory->obj[3]->pos.y = 0;
	inventory->obj[3]->type = 0;
	inventory->obj[3]->hp = 200;
	inventory->obj[3]->dmg = 0;
	inventory->obj[3]->armor = 35;
	inventory->obj[3]->magic = 20;
	inventory->obj[3]->name = "iron_armor";
}

static void load_equipment_obj3(inventory_t *inventory)
{
	inventory->obj[2]->unlock = true;
	inventory->obj[2]->pos.x = 2;
	inventory->obj[2]->pos.y = 1;
	inventory->obj[2]->type = 0;
	inventory->obj[2]->hp = 50;
	inventory->obj[2]->dmg = 0;
	inventory->obj[2]->armor = 20;
	inventory->obj[2]->magic = 15;
	inventory->obj[2]->name = "leather_armor";
}

static void load_equipment_obj2(inventory_t *inventory)
{
	inventory->obj[1]->unlock = true;
	inventory->obj[1]->pos.x = 1;
	inventory->obj[1]->pos.y = 2;
	inventory->obj[1]->type = 1;
	inventory->obj[1]->hp = 0;
	inventory->obj[1]->dmg = 45;
	inventory->obj[1]->armor = 0;
	inventory->obj[1]->magic = 60;
	inventory->obj[1]->name = "knife";
}

static void load_equipment_obj1(inventory_t *inventory)
{
	inventory->obj[0]->unlock = true;
	inventory->obj[0]->pos.x = 0;
	inventory->obj[0]->pos.y = 1;
	inventory->obj[0]->type = 1;
	inventory->obj[0]->hp = 0;
	inventory->obj[0]->dmg = 80;
	inventory->obj[0]->armor = 5;
	inventory->obj[0]->magic = 30;
	inventory->obj[0]->name = "sword";
}

void load_player_equipment(rpg_t *rpg, inventory_t *inventory)
{
	rpg->player->inventory->obj = malloc(sizeof(equipement_t *) * 5);
	inventory->obj[4] = NULL;
	for (int i = 0; i < 4; i++) {
		inventory->obj[i] = malloc(sizeof(equipement_t));
		inventory->obj[i]->unlock = false;
		inventory->obj[i]->equiped = false;
		inventory->obj[i]->texture = sfTexture_create(100, 100);
	}
	load_equipment_obj1(inventory);
	load_equipment_obj2(inventory);
	load_equipment_obj3(inventory);
	load_equipment_obj4(inventory);
}
