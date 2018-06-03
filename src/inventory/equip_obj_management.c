/*
** EPITECH PROJECT, 2018
** equip_obj_management
** File description:
** rpg
*/

#include "rpg.h"

static void swap_obj_stat(rpg_t *rpg, battle_t *battle,
	equipement_t *obj, inventory_t *inv)
{
	if (obj->type == 0) {
		obj->pos = sfRectangleShape_getPosition(inv->armor);
		swap_armor_stat(rpg, battle, obj, inv);
	} else if (obj->type == 1) {
		obj->pos = sfRectangleShape_getPosition(inv->weapon);
		swap_weapon_stat(rpg, battle, obj, inv);
	}
}

static void check_weapon(rpg_t *rpg, inventory_t *inv, int j)
{
	if (inv->obj[j]->type == 1 && inv->obj[j]->unlock
	&& inv->obj[j]->equiped)
		unequip_weapon_stat(rpg, rpg->battle, inv, j);
}

static void check_armor(rpg_t *rpg, inventory_t *inv, int j)
{
	if (inv->obj[j]->type == 0 && inv->obj[j]->unlock
	&& inv->obj[j]->equiped)
		unequip_armor_stat(rpg, rpg->battle, inv, j);
}

static void check_obj_slot(rpg_t *rpg, inventory_t *inv, int i)
{
	for (int j = 0; j < 4; j++) {
		if (inv->obj[j]->unlock
		&& inv->obj[j]->pos.x + inv->obj[j]->pos.y * 4 == i)
			swap_obj_stat(rpg, rpg->battle, inv->obj[j], inv);
	}
}

void equip_obj_management(rpg_t *rpg, inventory_t *inv)
{
	sfVector2f pos = sfRectangleShape_getPosition(inv->weapon);

	if ((inv->mouse.x < pos.x + 100 && inv->mouse.x > pos.x)
	&& (inv->mouse.y < pos.y + 100 && inv->mouse.y > pos.y))
		for (int j = 0; j < 4; j++)
			check_weapon(rpg, inv, j);
	pos = sfRectangleShape_getPosition(inv->armor);
	if ((inv->mouse.x < pos.x + 100 && inv->mouse.x > pos.x)
	&& (inv->mouse.y < pos.y + 100 && inv->mouse.y > pos.y))
		for (int j = 0; j < 4; j++)
			check_armor(rpg, inv, j);
	for (int i = 0; i < 12; i++) {
		pos = sfRectangleShape_getPosition(inv->slot[i]);
		if ((inv->mouse.x < pos.x + 100 && inv->mouse.x > pos.x)
		&& (inv->mouse.y < pos.y + 100 && inv->mouse.y > pos.y))
			check_obj_slot(rpg, inv, i);
	}
}
