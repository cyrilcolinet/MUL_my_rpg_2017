/*
** EPITECH PROJECT, 2018
** player_deplacement
** File description:
** rpg
*/

#include "rpg.h"

static bool player_deplacement_left(rpg_t *rpg
		, sfVector2f pos, sfKeyCode key)
{
	if (sfKeyboard_isKeyPressed(key)
	&& check_valid_deplacement(rpg, pos, -8, 0)) {
		pos = sfSprite_getPosition(rpg->player);
		pos.x -= 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 64;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
		return (true);
	}
	return (false);
}

static bool player_deplacement_right(rpg_t *rpg
		, sfVector2f pos, sfKeyCode key)
{
	if (sfKeyboard_isKeyPressed(key)
	&& check_valid_deplacement(rpg, pos, 8, 0)) {
		pos = sfSprite_getPosition(rpg->player);
		pos.x += 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 192;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
		return (true);
	}
	return (false);
}

static bool player_deplacement_up(rpg_t *rpg
		, sfVector2f pos, sfKeyCode key)
{
	if (sfKeyboard_isKeyPressed(key)
	&& check_valid_deplacement(rpg, pos, 0, -8)) {
		pos = sfSprite_getPosition(rpg->player);
		pos.y -= 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 0;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
		return (true);
	}
	return (false);
}

static bool player_deplacement_down(rpg_t *rpg
		, sfVector2f pos, sfKeyCode key)
{
	if (sfKeyboard_isKeyPressed(key)
	&& check_valid_deplacement(rpg, pos, 0, 8)) {
		pos = sfSprite_getPosition(rpg->player);
		pos.y += 8;
		sfSprite_setPosition(rpg->player, pos);
		rpg->player_rect.top = 128;
		rpg->player_rect.left += 64;
		if (rpg->player_rect.left > 192)
			rpg->player_rect.left = 0;
		sfSprite_setTextureRect(rpg->player, rpg->player_rect);
		return (true);
	}
	return (false);
}

void player_deplacement(rpg_t *rpg)
{
	sfVector2f pos;

	rpg->timer = sfClock_getElapsedTime(rpg->clock);
	if (sfTime_asSeconds(rpg->timer)
	>= sfTime_asSeconds(sfSeconds(0.01))) {
		if (!player_deplacement_left(rpg, pos, sfKeyLeft) &&
		!player_deplacement_right(rpg, pos, sfKeyRight) &&
		!player_deplacement_up(rpg, pos, sfKeyUp) &&
		!player_deplacement_down(rpg, pos, sfKeyDown)) {
			rpg->player_rect.left = 0;
			sfSprite_setTextureRect(rpg->player, rpg->player_rect);
		}
		sfClock_restart(rpg->clock);
		rpg->timer = sfTime_Zero;
	}
}
