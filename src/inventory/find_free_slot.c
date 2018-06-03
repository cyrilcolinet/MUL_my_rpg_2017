/*
** EPITECH PROJECT, 2018
** find_free_slot
** File description:
** rpg
*/

#include "rpg.h"

static bool is_free_slot(inventory_t *inv, int i)
{
	for (int j = 0; j < 4; j++) {
		if (inv->obj[j]->unlock
		&& inv->obj[j]->pos.x + inv->obj[j]->pos.y * 4 == i)
			return (false);
	}
	return (true);
}

sfVector2f find_free_slot(inventory_t *inv)
{
	sfVector2f pos = {-1, -1};

	for (int i = 0; i < 12; i++) {
		if (is_free_slot(inv, i)) {
			pos.x = i % 4;
			pos.y = i / 4;
			return (pos);
		}
	}
	return (pos);
}
