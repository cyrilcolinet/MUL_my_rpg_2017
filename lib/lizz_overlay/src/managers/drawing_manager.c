/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** drawing_manager functions
*/

# include "utils.h"
# include "lizz.h"

static void draw_buttons(lizz_t *lizz, sfRenderWindow *win, menu_e menu)
{
	btn_t *btn = lizz->btn;

	while (btn != NULL) {
		if (btn->sprite && btn->asset->texture) {
			if (btn->belongsTo == menu)
				sfRenderWindow_drawSprite(win, btn->sprite, NULL);
		}
		btn = btn->next;
	}
}

// TODO: Cette fonction n'affiche qu'une fois les assets, faire
// avec les btn_t et normalement c'est bon
void lizz_draw_elements(lizz_t *lizz, menu_e menu, sfRenderWindow *win)
{
	assets_t *ass = lizz->assets;

	while (ass != NULL) {
		if (ass->sprite && ass->texture && ass->belongsTo == menu) {
			//if (!lizz_startswith(ass->name, LIZZ_BTN_PREFIX))
				sfRenderWindow_drawSprite(win, ass->sprite, NULL);
		}
		ass = ass->next;
	}

	//draw_buttons(lizz, win, menu);
}
