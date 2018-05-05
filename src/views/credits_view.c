/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** credits_view functions
*/

# include "rpg.h"

void credits_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, aCreditsBg);

	sfRenderWindow_clear(rpg->win, sfBlack);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Credits");
	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
}
