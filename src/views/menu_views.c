/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** menu_views functions
*/

# include "rpg.h"

void pause_view(rpg_t *rpg)
{
	sfTexture *texture = sfTexture_createFromImage(rpg->img, NULL);
	sfSprite *sp = NULL;
	sfSprite *sp1 = get_sprite(rpg, "bg_pause");

	if (texture == NULL || sp1 == NULL)
		return;

	sp = sfSprite_create();
	sfSprite_setTexture(sp, texture, sfFalse);
	sfRenderWindow_drawSprite(rpg->win, sp, NULL);
	sfRenderWindow_drawSprite(rpg->win, sp1, NULL);
	sfSprite_destroy(sp);
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
	sfTexture *texture = sfTexture_createFromImage(rpg->img, NULL);
	sfSprite *sprite = NULL;

	if (texture == NULL)
		return;

	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfFalse);
	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	sfSprite_destroy(sprite);
}
