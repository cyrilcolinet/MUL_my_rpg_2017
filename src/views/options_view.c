/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** options_view functions
*/

# include "cook.h"

void options_view(cook_t *cook)
{
	sfSprite *sprite = get_sprite(cook, aOptionsBg);
	slider_t *vol = get_slider(cook, slideVolume);

	sfRenderWindow_clear(cook->win, sfBlack);
	sfRenderWindow_setTitle(cook->win, "Legacy Of The Kek | Options");
	sfRenderWindow_drawSprite(cook->win, sprite, NULL);

	if (vol != NULL) {
		sfRenderWindow_drawText(cook->win, vol->text, NULL);
	}
}
