/*
** EPITECH PROJECT, 2018
** event_management
** File description:
** rpg
*/

#include "rpg.h"

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

static void mouse_coord(battle_t *battle, sfEvent *event)
{
	if (event->type == sfEvtMouseMoved) {
		battle->mouse.x = event->mouseMove.x;
		battle->mouse.y = event->mouseMove.y;
	}
}

void battle_event_management(rpg_t *rpg, battle_t *battle, sfEvent *event)
{
	mouse_coord(battle, event);
	if (!battle->fight[battle->id]->enemy_turn)
		interaction(battle, event);
	if (event->type == sfEvtKeyReleased) {
		if (event->key.code == sfKeyN) {
			reset_map_state(battle);
			battle->hero->played = true;
		}
		if (event->key.code == sfKeyI
		&& !battle->fight[battle->id]->enemy_turn) {
			inventory_capture_img(rpg);
			cb_goto_custom_view(rpg, gameInventory);
		}
	}
}
