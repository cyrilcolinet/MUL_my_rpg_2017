/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main_view displaing
*/

# include "rpg.h"

void draw_history_button(rpg_t *rpg)
{
	sfTexture *texture = get_texture(rpg, "booksheet");
	sfSprite *sprite = NULL;
	sfVector2f pos = { 930, 740 };

	if (texture == NULL)
		return;

	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfFalse);
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(rpg->win, sprite, sfFalse);
	sfSprite_destroy(sprite);
}

void main_view(rpg_t *rpg)
{
	sfSprite *sp = get_sprite(rpg, "bg_main");

	if (sp == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sp, NULL);
	draw_history_button(rpg);
}
