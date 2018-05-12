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

void move_player(player_t *player, float factor)
{
	sfVector2f movement[4] = {{-10, 0}, {10, 0}, {0, -10}, {0, 10}};

	player->render_state->transform.matrix[2] += factor *
		movement[player->direction].x;
	player->render_state->transform.matrix[5] += factor *
		movement[player->direction].y;
}

void state_reset(player_t *player)
{
	player->rect.left = 0;
	sfSprite_setTextureRect(*player->sprite, player->rect);
	player->time_0 = sfSeconds(0);
}

void player_displacement(rpg_t *rpg, direction_e direction)
{
	update_direction(rpg->player, direction);
	if (animate_player(rpg->player, rpg->clock)) {
		rpg->player->time_0 = sfClock_getElapsedTime(
		rpg->clock);
		next_state(rpg->player);
		move_player(rpg->player, 1);
		if (player_collide(rpg->player, rpg->player->layer)) {
			move_player(rpg->player, -1);
			state_reset(rpg->player);
		}
	}
}