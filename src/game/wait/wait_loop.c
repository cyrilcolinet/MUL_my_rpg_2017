/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** wait_loop functions
*/

# include "rpg.h"

void wait_loop(rpg_t *rpg)
{
	sfSprite *sp = NULL;

	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Menu Principal");

	sp = get_sprite(rpg, "bg_main");
	if (sp == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sp, NULL);
}
