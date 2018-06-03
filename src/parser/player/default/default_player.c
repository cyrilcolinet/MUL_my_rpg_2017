/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** load_default_player_values functions
*/

# include "rpg.h"

void default_player_datas(rpg_t *rpg)
{
	sfVector2f pos = { 48, 672 };
	sfIntRect rec = { 192, 0, 64, 64 };

	rpg->player->level = 0;
	rpg->player->skills = 0;
	rpg->player->sexe = 0;
	rpg->player->clock = sfClock_create();
	rpg->player->texture = get_texture(rpg, "man_nu_no");
	rpg->player->rec = rec;
	rpg->player->sprite = sfSprite_create();
	sfSprite_setPosition(rpg->player->sprite, pos);
	sfSprite_setTexture(rpg->player->sprite, rpg->player->texture, true);
	sfSprite_setTextureRect(rpg->player->sprite, rec);
}

bool default_player(rpg_t *rpg)
{
	rpg->player = malloc(sizeof(player_t));
	rpg->battle->hero = malloc(sizeof(hero_t));
	if (!rpg->player || !rpg->battle->hero)
		return (false);

	rpg->player->name = my_strconfigure(19);
	if (rpg->player->name == NULL)
		return (false);

	rpg->map_id = 0;
	default_player_datas(rpg);
	default_hero_datas(rpg);
	load_hero_spells_icons(rpg);
}
