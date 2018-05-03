/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** credits_view functions
*/

# include "cook.h"

void credits_view(cook_t *cook)
{
	sfSprite *sprite = get_sprite(cook, aCreditsBg);

	sfRenderWindow_clear(cook->win, sfBlack);
	sfRenderWindow_setTitle(cook->win, "Legacy Of The Kek | Credits");
	sfRenderWindow_drawSprite(cook->win, sprite, NULL);
}
