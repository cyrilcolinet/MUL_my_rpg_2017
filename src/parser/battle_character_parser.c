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
	(*hero)->target = (*hero)->spell_id = -1;
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

void configure_spell_default(spell_t **spell)
{
	(*spell)->rec.top = 0;
	(*spell)->rec.left = 0;
	(*spell)->rec.width = 128;
	(*spell)->rec.height = 128;
	(*spell)->pos.x = 0;
	(*spell)->pos.y = 0;
}

void configure_battle_spell(rpg_t *rpg, config_setting_t *set, int id)
{
	spell_t **spell = NULL;
	char *name = NULL;

	if (rpg->battle->hero->spell[id] == NULL)
		return;

	spell = &rpg->battle->hero->spell[id];
	config_setting_lookup_string(set, "name", ((const char **)&name));
	config_setting_lookup_bool(set, "unlock", ((int *)&(*spell)->unlock));
	config_setting_lookup_bool(set, "cast", ((int *)&(*spell)->cast));
	configure_spell_default(spell);

	(*spell)->texture = get_texture(rpg, name);
	(*spell)->form = sfSprite_create();
	sfSprite_setTexture((*spell)->form, (*spell)->texture, sfTrue);
	sfSprite_setTextureRect((*spell)->form, (*spell)->rec);
}

void parse_spell_values(rpg_t *rpg, config_setting_t *set)
{
	config_setting_t *spells = config_setting_lookup(set, "spells");
	config_setting_t *spell = NULL;
	int count = 0;

	if (spells == NULL)
		return;

	count = config_setting_length(spells);
	rpg->battle->hero->spell = malloc(sizeof(spell_t *) * count);
	if (rpg->battle->hero->spell == NULL)
		return;

	for (int i = 0; count > 0 && i < count; i++) {
		rpg->battle->hero->spell[i] = malloc(sizeof(spell_t));
		if (rpg->battle->hero->spell[i] == NULL)
			continue;
		spell = config_setting_get_elem(spells, i);
		if (spell != NULL)
			configure_battle_spell(rpg, spell, i);
	}
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
	rpg->battle->hero->spell_id = -1;
	parse_spell_values(rpg, set);

	return (configure_all_default(rpg, &rpg->battle->hero, texture));
}
