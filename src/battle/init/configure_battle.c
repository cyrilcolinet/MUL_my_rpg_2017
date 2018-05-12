/*
** EPITECH PROJECT, 2018
** init_battle
** File description:
** rpg
*/

# include "rpg.h"

sfRectangleShape **create_battle_map(sfVector2f *pos)
{
	sfRectangleShape **map = malloc(sizeof(*map) * 120);
	sfVector2f size = { B_X, B_Y };
	sfColor color = sfColor_fromRGBA(125, 125, 135, 90);
	int i = 0;

	if (map == NULL)
		return (NULL);
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 12; col++) {
			map[i] = sfRectangleShape_create();
			sfRectangleShape_setPosition(map[i], *pos);
			sfRectangleShape_setSize(map[i], size);
			sfRectangleShape_setFillColor(map[i], sfTransparent);
			sfRectangleShape_setOutlineColor(map[i], color);
			sfRectangleShape_setOutlineThickness(map[i++], 1);
			(*pos).x += B_X;
		}
		(*pos).x = MAP_X - 1;
		(*pos).y += B_Y;
	}
	return (map);
}
