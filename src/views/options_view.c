/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** options_view functions
*/

# include "rpg.h"

void options_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, aOptionsBg);
	slider_t *vol = get_slider(rpg, slideVolume);

	sfRenderWindow_clear(rpg->win, sfBlack);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Options");
	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);

	if (vol != NULL) {
		sfRenderWindow_drawText(rpg->win, vol->text, NULL);
	}
}
