/*
** EPITECH PROJECT, 2018
** check_valid_deplacement
** File description:
** rpg
*/

#include "rpg.h"

bool check_valid_deplacement(rpg_t *rpg, sfVector2f pos, int x, int y)
{
	int id = rpg->map_id;
	int a = 0;
	int b = 0;

	pos = sfSprite_getPosition(rpg->player);
	pos.x += (32 + x);
	pos.y += (32 + y);
	a = pos.y / 8;
	b = pos.x / 8;
	if (rpg->map[id]->layer[a][b] == 1)
		return (true);
	return (false);
}
