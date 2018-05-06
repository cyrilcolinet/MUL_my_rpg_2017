/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** actions_callback functions
*/

# include "rpg.h"

void cb_quit_action(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	sfRenderWindow_close(rpg->win);
}

void cb_return_action(rpg_t *rpg, button_t *btn)
{
	(void)btn;
	state_e cpy = rpg->state;

	reset_to_normal_rect(rpg);
	rpg->state = rpg->last_st;
	rpg->last_st = cpy;
}

void cb_void_action(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	return;
}

void cb_click_action(rpg_t *rpg, button_t *btn)
{
	sfIntRect rec;
	(void)rpg;

	btn->pressed = true;
	rec = btn->rect;
	rec.top += btn->normal_rect.height * 2;

	sfSprite_setTextureRect(btn->sprite, rec);
}

void cb_hover_action(rpg_t *rpg, button_t *btn)
{
	sfIntRect rec;
	(void)rpg;

	rec = btn->rect;
	rec.top += btn->normal_rect.height;

	sfSprite_setTextureRect(btn->sprite, rec);
}
