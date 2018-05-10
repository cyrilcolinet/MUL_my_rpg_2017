/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** goto_view_callback2 functions
*/

# include "rpg.h"

void cb_goto_pause_view(rpg_t *rpg, button_t *btn)
{
	sfTexture *texture = NULL;
	sfImage *img = sfRenderWindow_capture(rpg->win);
	(void)btn;

	reset_to_normal_rect(rpg);
	texture = sfTexture_createFromImage(img, NULL);
	if (texture == NULL)
		return;
	if (rpg->capture != NULL)
		sfSprite_destroy(rpg->capture);
	rpg->capture = sfSprite_create();
	sfSprite_setTexture(rpg->capture, texture, sfFalse);
	sfImage_destroy(img);
	rpg->last_st = rpg->state;
	rpg->state = gamePause;
}

void cb_goto_select_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	rpg->last_st = rpg->state;
	rpg->state = gameSelect;
}
