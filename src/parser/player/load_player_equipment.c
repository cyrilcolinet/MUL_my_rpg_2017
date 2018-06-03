/*
** EPITECH PROJECT, 2018
** load_player_equipment
** File description:
** rpg
*/

#include "rpg.h"

static equipement_t *load_equipment(void)
{
	equipement_t *obj = malloc(sizeof(equipement_t));

	obj->name = "oui";
	obj->texture = sfTexture_create(100, 100);
	obj->unlock = false;
	obj->equiped = false;
	obj->dmg = 10;
	obj->armor = 10;
	obj->hp = 10;
	obj->magic = 10;
	obj->pos.x = -1;
	obj->pos.y = -1;
	obj->type = 0;
	return (obj);
}

void load_player_equipment(rpg_t *rpg, inventory_t *inventory)
{
	rpg->player->inventory->obj = malloc(sizeof(equipement_t *) * 5);
	inventory->obj[4] = NULL;
	for (int i = 0; i < 4; i++)
		inventory->obj[i] = load_equipment();
	/* test */
	inventory->obj[0]->unlock = true;
	inventory->obj[0]->pos.x = 0;
	inventory->obj[0]->pos.y = 0;
	inventory->obj[0]->type = 0;
	inventory->obj[0]->name = "leather armor";
	inventory->obj[1]->unlock = true;
	inventory->obj[1]->pos.x = 3;
	inventory->obj[1]->pos.y = 2;
	inventory->obj[1]->type = 0;
	inventory->obj[1]->hp = -16;
	inventory->obj[1]->dmg = 45;
	inventory->obj[1]->armor = 85;
	inventory->obj[1]->magic = -4;
	inventory->obj[1]->name = "swordddd";
}
