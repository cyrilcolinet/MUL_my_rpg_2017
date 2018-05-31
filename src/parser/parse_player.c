/*
** EPITECH PROJECT, 2018
** parse_player
** File description:
** rpg
*/

#include "rpg.h"

void parse_player(rpg_t *rpg)
{
	sfVector2f pos = {48, 672};

	rpg->player->sprite = sfSprite_create();
	rpg->player->rec.top = 192;
	rpg->player->rec.left = 0;
	rpg->player->rec.width = 64;
	rpg->player->rec.height = 64;
	sfSprite_setPosition(rpg->player->sprite, pos);
	sfSprite_setTexture(rpg->player->sprite, rpg->battle->hero->img, true);
	sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rec);
	rpg->player->clock = sfClock_create();
}
