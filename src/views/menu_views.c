/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** menu_views functions
*/

# include "rpg.h"

void pause_view(rpg_t *rpg)
{
	sfSprite *sp = get_sprite(rpg, "bg_pause");

	if (rpg->capture == NULL || sp == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, rpg->capture, NULL);
	sfRenderWindow_drawSprite(rpg->win, sp, NULL);
}

void credits_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_credits");

	if (sprite == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
}

void settings_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_settings");
	slider_t *vol = get_slider(rpg, "sld_volume");

	if (sprite == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);

	if (vol != NULL) {
		sfRenderWindow_drawText(rpg->win, vol->text, NULL);
	}
}

void settings_keymapping_view(rpg_t *rpg)
{
	if (rpg->capture == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, rpg->capture, NULL);
}
