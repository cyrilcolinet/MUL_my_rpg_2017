/*
** EPITECH PROJECT, 2018
** run_loop
** File description:
** loop of the game
*/

# include "rpg.h"

void run_loop(rpg_t *rpg)
{
	sfSprite *sp = get_sprite(rpg, "bg_run");

	if (sp == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sp, NULL);
}
