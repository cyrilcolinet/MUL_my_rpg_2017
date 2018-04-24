/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** btn_actions functions
*/

# include "lizz.h"

void lizz_btn_on_hover_def(btn_t *btn, int move)
{
	if (!btn && !btn->asset)
		return;

	btn->asset->rect->top += move;
	sfSprite_setTextureRect(btn->asset->sprite, *btn->asset->rect);
}
