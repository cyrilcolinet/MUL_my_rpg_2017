/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** drawing_manager functions
*/

# include "lizz.h"

void lizz_draw_elements(lizz_t *lizz, menu_e menu, sfRenderWindow *win)
{
	assets_t *ass = lizz->assets;

	while (ass != NULL) {
		if (ass->sprite && ass->texture) {
			if (ass->belongsTo == menu)
				sfRenderWindow_drawSprite(win, ass->sprite, NULL);
		}
		ass = ass->next;
	}
}
