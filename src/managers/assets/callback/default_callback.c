/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** default_callback functions
*/

# include "rpg.h"

void default_hover_callback(rpg_t *rpg, button_t *btn)
{
	sfIntRect rec;
	(void)rpg;

	rec = btn->rect;
	rec.top += btn->normal_rect.height;

	sfSprite_setTextureRect(btn->sprite, rec);
}

void default_click_callback(rpg_t *rpg, button_t *btn)
{
	sfIntRect rec;
	(void)rpg;

	btn->pressed = true;
	rec = btn->rect;
	rec.top += btn->normal_rect.height * 2;

	sfSprite_setTextureRect(btn->sprite, rec);
}

void nothing_callback(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	return;
}
