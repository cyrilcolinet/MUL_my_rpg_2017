/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** battle_character functions
*/

# include "rpg.h"

int configure_all_default(rpg_t *rpg, hero_t **hero, char *texture)
{
	sfVector2f scale = { 1.25, 1.25 };
	sfIntRect rec = { 192, 0, 64, 64 };
	sfVector2f pos = { 0, 5 };

	(*hero)->pos = pos;
	(*hero)->alive = (*hero)->sword = true;
	(*hero)->played = (*hero)->select = false;
	(*hero)->move = (*hero)->attack = false;
	(*hero)->target = -1;
	(*hero)->form = sfSprite_create();
	(*hero)->img = get_texture(rpg, texture);
	(*hero)->rec = rec;
	if ((*hero)->img == NULL)
		return (-1);
	sfSprite_setPosition((*hero)->form, (*hero)->pos);
	sfSprite_setTexture((*hero)->form, (*hero)->img, true);
	sfSprite_setTextureRect((*hero)->form, (*hero)->rec);
	sfSprite_setScale((*hero)->form, scale);

	return (0);
}

int configure_battle_characters(rpg_t *rpg)
{
	config_setting_t *set = parse_file(rpg, "heroes/demo.cfg", "hero");
	char *texture = NULL;

	if (set == NULL)
		return (-1);

	rpg->battle->hero = malloc(sizeof(hero_t));
	if (rpg->battle->hero == NULL)
		return (-1);

	config_setting_lookup_string(set, "texture", ((const char **)&texture));
	config_setting_lookup_int(set, "heal", &rpg->battle->hero->hp);
	config_setting_lookup_int(set, "damage", &rpg->battle->hero->dmg);
	config_setting_lookup_int(set, "armor", &rpg->battle->hero->armor);

	return (configure_all_default(rpg, &rpg->battle->hero, texture));
}
