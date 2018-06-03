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
		pos = sfSprite_getPosition(rpg->player->sprite);
		pos.x -= 8;
		sfSprite_setPosition(rpg->player->sprite, pos);
		rpg->player->rec.top = 64;
		rpg->player->rec.left += 64;
		if (rpg->player->rec.left > 192)
			rpg->player->rec.left = 0;
		sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rec);
		return (true);
	}
	return (false);
}

static bool player_deplacement_right(rpg_t *rpg
		, sfVector2f pos, sfKeyCode key)
{
	if (sfKeyboard_isKeyPressed(key)
	&& check_valid_deplacement(rpg, pos, 8, 0)) {
		pos = sfSprite_getPosition(rpg->player->sprite);
		pos.x += 8;
		sfSprite_setPosition(rpg->player->sprite, pos);
		rpg->player->rec.top = 192;
		rpg->player->rec.left += 64;
		if (rpg->player->rec.left > 192)
			rpg->player->rec.left = 0;
		sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rec);
		return (true);
	}
	return (false);
}

static bool player_deplacement_up(rpg_t *rpg
		, sfVector2f pos, sfKeyCode key)
{
	if (sfKeyboard_isKeyPressed(key)
	&& check_valid_deplacement(rpg, pos, 0, -8)) {
		pos = sfSprite_getPosition(rpg->player->sprite);
		pos.y -= 8;
		sfSprite_setPosition(rpg->player->sprite, pos);
		rpg->player->rec.top = 0;
		rpg->player->rec.left += 64;
		if (rpg->player->rec.left > 192)
			rpg->player->rec.left = 0;
		sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rec);
		return (true);
	}
	return (false);
}

static bool player_deplacement_down(rpg_t *rpg
		, sfVector2f pos, sfKeyCode key)
{
	if (sfKeyboard_isKeyPressed(key)
	&& check_valid_deplacement(rpg, pos, 0, 8)) {
		pos = sfSprite_getPosition(rpg->player->sprite);
		pos.y += 8;
		sfSprite_setPosition(rpg->player->sprite, pos);
		rpg->player->rec.top = 128;
		rpg->player->rec.left += 64;
		if (rpg->player->rec.left > 192)
			rpg->player->rec.left = 0;
		sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rec);
		return (true);
	}
	return (false);
}

void player_deplacement(rpg_t *rpg)
{
	sfVector2f pos;

	rpg->player->timer = sfClock_getElapsedTime(rpg->player->clock);
	if (sfTime_asSeconds(rpg->player->timer)
	>= sfTime_asSeconds(sfSeconds(0.05))) {
		if (!player_deplacement_left(rpg, pos, sfKeyLeft) &&
		!player_deplacement_right(rpg, pos, sfKeyRight) &&
		!player_deplacement_up(rpg, pos, sfKeyUp) &&
		!player_deplacement_down(rpg, pos, sfKeyDown)) {
			rpg->player->rec.left = 0;
			sfSprite_setTextureRect(
				rpg->player->sprite, rpg->player->rec);
		}
		sfClock_restart(rpg->player->clock);
		rpg->player->timer = sfTime_Zero;
	}
}
