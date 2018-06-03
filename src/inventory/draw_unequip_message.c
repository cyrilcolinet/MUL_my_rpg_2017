/*
** EPITECH PROJECT, 2018
** draw_unequip_message
** File description:
** rpg
*/

#include "rpg.h"

static bool is_in_zone(inventory_t *inv)
{
	sfVector2f pos = sfRectangleShape_getPosition(inv->weapon);

	if ((inv->mouse.x > pos.x && inv->mouse.x < pos.x + 100)
	&& (inv->mouse.y > pos.y && inv->mouse.y < pos.y + 100))
		return (true);
	pos = sfRectangleShape_getPosition(inv->armor);
	if ((inv->mouse.x > pos.x && inv->mouse.x < pos.x + 100)
	&& (inv->mouse.y > pos.y && inv->mouse.y < pos.y + 100))
		return (true);
	return (false);
}

void draw_unequip_message(rpg_t *rpg, inventory_t *inv)
{
	sfVector2f pos = {1150, 260};

	if (!is_in_zone(inv))
		return;
	sfText_setColor(rpg->battle->text, sfBlack);
	sfText_setString(rpg->battle->text, "Press 'E' pour desequiper l'objet");
	sfText_setCharacterSize(rpg->battle->text, 40);
	sfText_setPosition(rpg->battle->text, pos);
	sfRenderWindow_drawText(rpg->win, rpg->battle->text, NULL);
}
