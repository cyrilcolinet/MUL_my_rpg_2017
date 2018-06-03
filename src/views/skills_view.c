/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** skills views
*/

# include "rpg.h"

void skills_view(rpg_t *rpg)
{
	if (rpg->capture == NULL)
		return;
	sfRenderWindow_drawSprite(rpg->win, rpg->capture, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Skills");
}
