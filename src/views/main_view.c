/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main_view displaing
*/

# include "rpg.h"

void animate_book_sprite(rpg_t *rpg, assets_t *asset)
{
	sfTime t = sfClock_getElapsedTime(rpg->clock);
	static float refresh = 0.1;

	if (sfTime_asSeconds(t) >= refresh) {
	 	asset->rec.left += asset->rec.width + 1;
		if (asset->rec.left >= asset->rec.width * 6) {
			asset->rec.left = 0;
			asset->rec.top += asset->rec.height + 1;
			if (asset->rec.top >= asset->rec.height * 7) {
				asset->rec.top = 0;
			}
		}
		sfSprite_setTextureRect(asset->sp, asset->rec);
		refresh += 0.1;
	}

	if (refresh >= (0.1 * 41)) {
		sfClock_restart(rpg->clock);
		refresh = 0.1;
	}
}

void draw_history_button(rpg_t *rpg)
{
	assets_t *asset = get_asset(rpg, "booksheet");
	sfVector2f pos = { 930, 730 };

	if (asset == NULL)
		return;

	sfSprite_setPosition(asset->sp, pos);
	animate_book_sprite(rpg, asset);
	sfRenderWindow_drawSprite(rpg->win, asset->sp, NULL);
}

void main_view(rpg_t *rpg)
{
	sfSprite *sp = get_sprite(rpg, "bg_main");

	if (sp == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sp, NULL);
	draw_history_button(rpg);
}
