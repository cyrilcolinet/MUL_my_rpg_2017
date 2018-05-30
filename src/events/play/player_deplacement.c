/*
** EPITECH PROJECT, 2018
** player_deplacement
** File description:
** rpg
*/

#include "rpg.h"

static void player_deplacement_left(rpg_t *rpg, sfEvent *event
		, sfVector2f pos)
{
	if (event->key.code == sfKeyLeft
	&& check_valid_deplacement(rpg, pos, -8, 0)) {
		pos = sfSprite_getPosition(rpg->player);
		pos.x -= 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 64;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
	}
}

static void player_deplacement_right(rpg_t *rpg, sfEvent *event
		, sfVector2f pos)
{
	if (event->key.code == sfKeyRight
	&& check_valid_deplacement(rpg, pos, 8, 0)) {
		pos = sfSprite_getPosition(rpg->player);
		pos.x += 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 192;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
	}
}

static void player_deplacement_up(rpg_t *rpg, sfEvent *event
		, sfVector2f pos)
{
	if (event->key.code == sfKeyUp
	&& check_valid_deplacement(rpg, pos, 0, -8)) {
		pos = sfSprite_getPosition(rpg->player);
		pos.y -= 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 0;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
	}
}

static void player_deplacement_down(rpg_t *rpg, sfEvent *event
		, sfVector2f pos)
{
	if (event->key.code == sfKeyDown
	&& check_valid_deplacement(rpg, pos, 0, 8)) {
		pos = sfSprite_getPosition(rpg->player);
		pos.y += 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 128;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
	}
}

void player_deplacement(rpg_t *rpg, sfEvent *event)
{
	sfVector2f pos;

	if (event->type == sfEvtMouseMoved)
		return;
	if (event->type == sfEvtKeyPressed) {
		player_deplacement_left(rpg, event, pos);
		player_deplacement_right(rpg, event, pos);
		player_deplacement_up(rpg, event, pos);
		player_deplacement_down(rpg, event, pos);
	} else {
		rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
	}
}
