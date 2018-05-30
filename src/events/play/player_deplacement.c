/*
** EPITECH PROJECT, 2018
** player_deplacement
** File description:
** rpg
*/

#include "rpg.h"

static void player_deplacement_side(rpg_t *rpg, sfEvent *event
		, sfVector2f pos)
{
	if (event->key.code == sfKeyLeft) {
		pos = sfSprite_getPosition(rpg->player);
		pos.x -= 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 64;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
	}
	if (event->key.code == sfKeyRight) {
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

static void player_deplacement_up_down(rpg_t *rpg, sfEvent *event
		, sfVector2f pos)
{
	if (event->key.code == sfKeyUp) {
		pos = sfSprite_getPosition(rpg->player);
		pos.y -= 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 0;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
	}
	if (event->key.code == sfKeyDown) {
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

	if (event->type == sfEvtKeyPressed) {
		/* rpg->timer = sfClock_getElapsedTime(rpg->clock); */
		/* if (sfTime_asSeconds(rpg->timer) < sfTime_asSeconds(sfSeconds(0.2))) { */
		player_deplacement_side(rpg, event, pos);
		player_deplacement_up_down(rpg, event, pos);
		/* } else { */
		/* 	sfClock_restart(rpg->clock); */
		/* 	rpg->timer = sfTime_Zero; */
		/* } */
	} else {
		sfClock_restart(rpg->clock);
		rpg->timer = sfTime_Zero;
		rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
	}
}
