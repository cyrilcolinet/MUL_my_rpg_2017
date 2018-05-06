/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** play_view functions
*/

# include "rpg.h"

void play_view(rpg_t *rpg)
{
	sfSprite *sp = get_sprite(rpg, "map1");

	if (sp == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sp, NULL);
	draw_history_button(rpg);
}
