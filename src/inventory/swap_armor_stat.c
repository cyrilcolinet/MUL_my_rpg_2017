/*
** EPITECH PROJECT, 2018
** swap_armor_stat
** File description:
** rpg
*/

#include "rpg.h"

static int is_armor_equiped(inventory_t *inv)
{
	for (int i = 0; i < 4; i++) {
		if (inv->obj[i]->type == 0
		&& inv->obj[i]->unlock && inv->obj[i]->equiped)
			return (i);
	}
	return (-1);
}

void swap_armor_stat(rpg_t *rpg, battle_t *battle,
		equipement_t *obj, inventory_t *inv)
{
	int nb = is_armor_equiped(inv);

	if (nb == -1) {
		battle->hero->hp += obj->hp;
		battle->hero->dmg += obj->dmg;
		battle->hero->armor += obj->armor;
		for (int i = 0; i < 4; i++)
			battle->hero->spell[i]->val += obj->magic;
	} else {
		battle->hero->hp += (obj->hp - inv->obj[nb]->hp);
		battle->hero->dmg += (obj->dmg - inv->obj[nb]->dmg);
		battle->hero->armor += (obj->armor - inv->obj[nb]->armor);
		for (int i = 0; i < 4; i++)
			battle->hero->spell[i]->val +=
				(obj->magic - inv->obj[nb]->magic);
		inv->obj[nb]->equiped = false;
	}
	obj->equiped = true;
}

void unequip_armor_stat(rpg_t *rpg, battle_t *battle,
	inventory_t *inv, int nb)
{
	battle->hero->hp -= inv->obj[nb]->hp;
	battle->hero->dmg -= inv->obj[nb]->dmg;
	battle->hero->armor -= inv->obj[nb]->armor;
	for (int i = 0; i < 4; i++)
		battle->hero->spell[i]->val -= inv->obj[nb]->magic;
	inv->obj[nb]->equiped = false;
	inv->obj[nb]->pos.x = 0;
	inv->obj[nb]->pos.y = 0;
}
