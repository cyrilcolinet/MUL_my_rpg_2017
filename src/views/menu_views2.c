/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** menu_views funtions (bis)
*/

# include "rpg.h"

void game_load_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_load");

	if (sprite == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Jouer");
}
