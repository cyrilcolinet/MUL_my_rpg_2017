/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** function for player managment
*/

#include "rpg.h"

void update_direction(player_t *player, direction_e direction)
{
	switch (direction) {
		case left:
			player->rect.top = 64;
		break;
		case right:
			player->rect.top = 192;
		break;
		case up:
			player->rect.top = 0;
		break;
		case down:
			player->rect.top = 128;
		break;
	}
	player->direction = direction;
	sfSprite_setTextureRect(*player->sprite, player->rect);
}

void next_state(player_t *player)
{
	player->rect.left = (player->rect.left + 64) % 576;
	sfSprite_setTextureRect(*player->sprite, player->rect);
}

void state_reset(player_t *player)
{
	player->rect.left = 0;
	sfSprite_setTextureRect(*player->sprite, player->rect);
}