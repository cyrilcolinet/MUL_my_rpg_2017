/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** inventory view displing
*/

# include "rpg.h"

void inventory_view(rpg_t *rpg)
{
	if (rpg->capture == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, rpg->capture, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Iventory");
}
