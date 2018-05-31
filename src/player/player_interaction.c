/*
** EPITECH PROJECT, 2018
** player_interaction
** File description:
** rpg
*/

#include "rpg.h"

static void check_map(rpg_t *rpg, int id, sfVector2i pos)
{
	int x = pos.x;
	int y = pos.y;
	sfIntRect rec;
	sfRectangleShape *oui = sfRectangleShape_create();
	sfVector2f lol;

	for (int i = 0; rpg->map[id]->it[i]; i++) {
		rec = rpg->map[id]->it[i]->rec;
		lol.x = rec.left;
		lol.y = rec.top;
		sfRectangleShape_setPosition(oui, lol);
		lol.x = rec.width;
		lol.y = rec.height;
		sfRectangleShape_setSize(oui, lol);
		sfRectangleShape_setFillColor(oui, sfRed);
		sfRenderWindow_drawRectangleShape(rpg->win, oui, NULL);
		if ((x > rec.left && x < rec.left + rec.width)
		    && (y > rec.top && y < rec.top + rec.height)) {
			sfText_setString(rpg->text, rpg->map[id]->it[i]->msg);
		}
	}
	for (int a = 0; a < 136; a++) {
		for (int b = 0; b < 240; b++) {
			if (rpg->map[id]->layer[a][b] == 2) {
				lol.x = b * 8;
				lol.y = a * 8;
				sfRectangleShape_setPosition(oui, lol);
				lol.x = 8;
				lol.y = 8;
				sfRectangleShape_setSize(oui, lol);
				sfRectangleShape_setFillColor(oui, sfGreen);
				sfRenderWindow_drawRectangleShape(rpg->win, oui, NULL);
			}
		}
	}
	sfRectangleShape_destroy(oui);
}

void player_interaction(rpg_t *rpg)
{
	sfVector2f pos;
	sfVector2i curr;

	pos = sfSprite_getPosition(rpg->player);
	curr.x = pos.x + 32;
	curr.y = pos.y + 32;
	if (rpg->map[rpg->map_id]->layer[curr.y / 8][curr.x / 8] == 2) {
		pos.x = 500;
		pos.y = 50;
		sfText_setColor(rpg->text, sfWhite);
		sfText_setPosition(rpg->text, pos);
		sfText_setCharacterSize(rpg->text, 45);
		if (rpg->map_id == 0)
			check_map(rpg, 0, curr);
		else if (rpg->map_id == 1)
			check_map(rpg, 1, curr);
		sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
	}
}
