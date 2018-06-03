/*
** EPITECH PROJECT, 2018
** check_stat_value
** File description:
** rpg
*/

#include "rpg.h"

static int check_type_equiped(inventory_t *inv, int type)
{
	for (int i = 0; i < 4; i++) {
		if (inv->obj[i]->type ==
		type && inv->obj[i]->unlock && inv->obj[i]->equiped)
			return (i);
	}
	return (-1);
}

char *check_stat_hp_value(inventory_t *inv, battle_t *battle,
	equipement_t *obj)
{
	int nb = battle->hero->hp + obj->hp;
	int id = 0;

	if (nb < battle->hero->hp)
		sfText_setColor(battle->text, sfRed);
	if (obj->type == 0) {
		id = check_type_equiped(inv, 0);
		if (id == -1)
			return (my_itoa(nb));
		nb -= inv->obj[id]->hp;
	} else if (obj->type == 1) {
		id = check_type_equiped(inv, 1);
		if (id == -1)
			return (my_itoa(nb));
		nb -= inv->obj[id]->hp;
	}
	if (nb < battle->hero->hp)
		sfText_setColor(battle->text, sfRed);
	return (my_itoa(nb));
}

char *check_stat_dmg_value(inventory_t *inv, battle_t *battle,
	equipement_t *obj)
{
	int nb = battle->hero->dmg + obj->dmg;
	int id = 0;

	if (nb < battle->hero->dmg)
		sfText_setColor(battle->text, sfRed);
	if (obj->type == 0) {
		id = check_type_equiped(inv, 0);
		if (id == -1)
			return (my_itoa(nb));
		nb -= inv->obj[id]->dmg;
	} else if (obj->type == 1) {
		id = check_type_equiped(inv, 1);
		if (id == -1)
			return (my_itoa(nb));
		nb -= inv->obj[id]->dmg;
	}
	if (nb < battle->hero->dmg)
		sfText_setColor(battle->text, sfRed);
	return (my_itoa(nb));
}

char *check_stat_armor_value(inventory_t *inv, battle_t *battle,
	equipement_t *obj)
{
	int nb = battle->hero->armor + obj->armor;
	int id = 0;

	if (nb < battle->hero->armor)
		sfText_setColor(battle->text, sfRed);
	if (obj->type == 0) {
		id = check_type_equiped(inv, 0);
		if (id == -1)
			return (my_itoa(nb));
		nb -= inv->obj[id]->armor;
	} else if (obj->type == 1) {
		id = check_type_equiped(inv, 1);
		if (id == -1)
			return (my_itoa(nb));
		nb -= inv->obj[id]->armor;
	}
	if (nb < battle->hero->armor)
		sfText_setColor(battle->text, sfRed);
	return (my_itoa(nb));
}

char *check_stat_magic_value(inventory_t *inv, battle_t *battle,
	equipement_t *obj, int i)
{
	int nb = battle->hero->spell[i]->val + obj->magic;
	int id = 0;

	if (nb < battle->hero->spell[i]->val)
		sfText_setColor(battle->text, sfRed);
	if (obj->type == 0) {
		id = check_type_equiped(inv, 0);
		if (id == -1)
			return (my_itoa(nb));
		nb -= inv->obj[id]->magic;
	} else if (obj->type == 1) {
		id = check_type_equiped(inv, 1);
		if (id == -1)
			return (my_itoa(nb));
		nb -= inv->obj[id]->magic;
	}
	if (nb < battle->hero->spell[i]->val)
		sfText_setColor(battle->text, sfRed);
	return (my_itoa(nb));
}
