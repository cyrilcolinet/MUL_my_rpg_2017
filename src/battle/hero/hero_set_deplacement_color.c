/*
** EPITECH PROJECT, 2018
** hero_set_deplacement_color
** File description:
** rpg
*/

#include "rpg.h"

void set_color(battle_t *battle, int nb, sfColor color)
{
	sfRectangleShape_setFillColor(
		battle->fight[battle->id]->map[nb], color);
}
