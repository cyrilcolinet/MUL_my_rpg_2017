/*
** EPITECH PROJECT, 2018
** swap_weapon_stat
** File description:
** rpg
*/

#include "rpg.h"

static int is_weapon_equiped(inventory_t *inv)
{
	for (int i = 0; i < 4; i++) {
		if (inv->obj[i]->type == 1
		&& inv->obj[i]->unlock && inv->obj[i]->equiped)
			return (i);
	}
	return (-1);
}

void swap_weapon_stat(rpg_t *rpg, battle_t *battle,
		equipement_t *obj, inventory_t *inv)
{
	int nb = is_weapon_equiped(inv);

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
	}
	if (my_strcmp(obj->name, "sword") == 0)
		battle->hero->sword = true;
	obj->equiped = true;
}
