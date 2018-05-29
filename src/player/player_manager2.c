/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** function for player managment
*/

#include "rpg.h"

sfBool animate_player(player_t *player, sfClock *clock)
{
	return sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) -
		sfTime_asMilliseconds(player->time_0) > 35 ? sfTrue : sfFalse;
}

//TODO replace int **layer by map_t * with the layer in it (when done replace layer by map->layer)
//sfVector2f tile represent the two tile id to be used for the given direction
sfBool player_collide(player_t *player, int **layer)
{
	sfFloatRect player_rect = {player->render_state->transform.matrix[2] +
		8, player->render_state->transform.matrix[5] + 8, 8, 8};
	sfVector2i tiles[4];
	sfVector2i to_check[4] = {{0, 1}, {2, 3}, {0, 2}, {1, 3}};

	tiles[0].y = (int)floor(player_rect.top / 8);
	tiles[0].x = (int)floor(player_rect.left / 8);
	tiles[1].y = (int)floor(player_rect.top / 8) + 1;
	tiles[1].x = (int)floor(player_rect.left / 8);
	tiles[2].y = (int)floor(player_rect.top / 8);
	tiles[2].x = (int)floor(player_rect.left / 8) + 1;
	tiles[3].y = (int)floor(player_rect.top / 8) + 1;
	tiles[3].x = (int)floor(player_rect.left / 8) + 1;
	if (layer[tiles[to_check[player->direction].x].y][tiles
		[to_check[player->direction].x].x] != 1 ||
		layer[tiles[to_check[player->direction].y].y][tiles[to_check
		[player->direction].y].x] != 1)
		return sfTrue;
	return sfFalse;
}
