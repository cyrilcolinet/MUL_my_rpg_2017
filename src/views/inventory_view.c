/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** inventory view displing
*/

# include "rpg.h"

static void draw_slot(rpg_t *rpg, inventory_t *inv, int i)
{
	sfRectangleShape_setFillColor(inv->slot[i], sfBlue);
	for (int j = 0; j < 4; j++) {
		if (inv->obj[j]->unlock
		&& inv->obj[j]->pos.x + inv->obj[j]->pos.y * 4 == i) {
			sfRectangleShape_setFillColor(inv->slot[i], sfYellow);
		}
	}
	sfRenderWindow_drawRectangleShape(rpg->win, inv->slot[i], NULL);
}

static void draw_inventory(rpg_t *rpg, inventory_t *inv)
{
	sfRenderWindow_drawRectangleShape(rpg->win, inv->win, NULL);
	sfRenderWindow_drawRectangleShape(rpg->win, inv->armor, NULL);
	sfRenderWindow_drawRectangleShape(rpg->win, inv->weapon, NULL);
	for (int i = 0; i < 12; i++)
		draw_slot(rpg, inv, i);
	draw_stat_player(rpg, rpg->battle);
	draw_obj_stat(rpg, inv);
}

void inventory_view(rpg_t *rpg)
{
	if (rpg->capture == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, rpg->capture, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Iventory");
	draw_inventory(rpg, rpg->player->inventory);
}
