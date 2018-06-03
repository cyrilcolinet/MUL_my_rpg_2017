/*
** EPITECH PROJECT, 2018
** talk_to_totem
** File description:
** rpg
*/

#include "rpg.h"

static void capture_img(rpg_t *rpg)
{
	sfImage *img = sfRenderWindow_capture(rpg->win);

	reset_to_normal_rect(rpg);
	sfTexture_updateFromImage(rpg->texture, img, 0, 0);
	if (rpg->texture == NULL)
		return;
	if (rpg->capture != NULL)
		sfSprite_destroy(rpg->capture);
	rpg->capture = sfSprite_create();
	sfSprite_setTexture(rpg->capture, rpg->texture, sfFalse);
	sfImage_destroy(img);
}

void talk_to_totem(rpg_t *rpg, int id)
{
	capture_img(rpg);
	cb_goto_custom_view(rpg, gameSkills);
	rpg->map[rpg->map_id]->it[id]->active = false;
	rpg->map[rpg->map_id]->it[id]->in_zone = false;
}
