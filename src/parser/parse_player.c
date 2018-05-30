/*
** EPITECH PROJECT, 2018
** parse_player
** File description:
** rpg
*/

#include "rpg.h"

void parse_player(rpg_t *rpg)
{
//	sfVector2f pos = {48, 672};
	sfVector2f pos = {48, 296};

	rpg->player = sfSprite_create();
	rpg->player_rect.top = 192;
	rpg->player_rect.left = 0;
	rpg->player_rect.width = 64;
	rpg->player_rect.height = 64;
	sfSprite_setPosition(rpg->player, pos);
	sfSprite_setTexture(rpg->player, rpg->battle->hero->img, true);
	sfSprite_setTextureRect(rpg->player, rpg->player_rect);
}
