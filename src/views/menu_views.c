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
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | En pause");
}

void credits_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_credits");

	if (sprite == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Credits");
}

void settings_view(rpg_t *rpg)
{
	char *name = ((rpg->last_st == gameWait) ? "bg_settings" \
	: "bg_settings1");
	sfSprite *sprite = get_sprite(rpg, name);
	slider_t *vol = get_slider(rpg, "sld_volume_music");

	if (rpg->capture != NULL)
		sfRenderWindow_drawSprite(rpg->win, rpg->capture, NULL);
	if (sprite == NULL)
		return;
	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Options");

	if (vol != NULL) {
		sfRenderWindow_drawText(rpg->win, vol->text, NULL);
	}
}

void history_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_history");

	if (sprite == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Histoire");
}

void select_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_select");

	if (sprite == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
	if (rpg->select_hovered)
		sfRenderWindow_drawRectangleShape(rpg->win, rpg->shape, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Selection");
}
