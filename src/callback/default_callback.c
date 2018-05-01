/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** default_callback functions
*/

# include "cook.h"

void default_hover_callback(cook_t *cook, button_t *btn)
{
	sfIntRect rec;
	(void)cook;

	rec = btn->rect;
	rec.top += 68;

	sfSprite_setTextureRect(btn->sprite, rec);
}

void default_click_callback(cook_t *cook, button_t *btn)
{
	sfIntRect rec;
	(void)cook;

	btn->pressed = true;
	rec = btn->rect;
	rec.top += 68 * 2;

	sfSprite_setTextureRect(btn->sprite, rec);
}

void nothing_callback(cook_t *cook, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(cook);
	return;
}
