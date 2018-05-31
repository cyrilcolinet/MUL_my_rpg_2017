/*
** EPITECH PROJECT, 2018
** destroy_player
** File description:
** rpg
*/

#include "rpg.h"

void destroy_player(rpg_t *rpg)
{
	sfClock_destroy(rpg->player->clock);
	free(rpg->player->name);
	sfSprite_destroy(rpg->player->sprite);
	free(rpg->player);
}
