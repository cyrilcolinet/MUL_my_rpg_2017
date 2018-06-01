/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** events for play menu
*/

# include "rpg.h"

static void inventory_capture_img(rpg_t *rpg)
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

void ev_run(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtKeyReleased) {
		if (event->key.code == sfKeyEscape)
			cb_goto_pause_view(rpg, NULL);
		if (event->key.code == sfKeyI) {
			inventory_capture_img(rpg);
			cb_goto_custom_view(rpg, gameInventory);
		}
	}
	if (rpg->battle->run)
		battle_event_management(rpg, rpg->battle, event);
	else if (!rpg->battle->run) {
		event_player_interaction(rpg, event);
	}
}
