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

	for (int i = 0; rpg->map[id]->it[i]; i++) {
		rec = rpg->map[id]->it[i]->rec;
		if ((x > rec.left && x < rec.left + rec.width)
		&& (y > rec.top && y < rec.top + rec.height)) {
			sfText_setString(rpg->text, rpg->map[id]->it[i]->msg[2]);
			rpg->map[id]->it[i]->in_zone = true;
			sfRenderWindow_drawText(rpg->win, rpg->text, NULL);
		}
	}
}

static void reset_in_zone(rpg_t *rpg)
{
	for (int i = 0; rpg->map[rpg->map_id]->it[i]; i++)
		rpg->map[rpg->map_id]->it[i]->in_zone = false;
}

static void set_up_text(rpg_t *rpg, sfVector2f pos)
{
	pos.x = 500;
	pos.y = 50;
	sfText_setColor(rpg->text, sfWhite);
	sfText_setPosition(rpg->text, pos);
	sfText_setCharacterSize(rpg->text, 45);
}

void player_interaction(rpg_t *rpg)
{
	sfVector2f pos;
	sfVector2i curr;

	reset_in_zone(rpg);
	pos = sfSprite_getPosition(rpg->player->sprite);
	curr.x = pos.x + 32;
	curr.y = pos.y + 32;
	set_up_text(rpg, pos);
	if (rpg->map[rpg->map_id]->layer[curr.y / 8][curr.x / 8] == 2) {
		if (rpg->map_id == 0)
			check_map(rpg, 0, curr);
		else if (rpg->map_id == 1)
			check_map(rpg, 1, curr);
	}
	call_interaction(rpg);
}
