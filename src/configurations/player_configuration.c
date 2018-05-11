/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player base settigs
*/

#include "rpg.h"

void configure_player(rpg_t *rpg)
{
	rpg->player = malloc(sizeof(player_t));
	rpg->player->sprite = (void **)&rpg->battle->hero->form;
	rpg->player->direction = up;
	rpg->player->pos.x = 0;
	rpg->player->pos.y = 0;
	rpg->player->rect.top = 0;
	rpg->player->rect.left = 0;
	rpg->player->rect.width = 64;
	rpg->player->rect.height = 64;
	info("Player base settings loaded");
}