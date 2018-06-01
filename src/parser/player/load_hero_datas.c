/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** load_hero_datas functions
*/

# include "rpg.h"

void load_spell_datas(config_setting_t *set, rpg_t *rpg, int key)
{
	spell_t *spell = rpg->battle->hero->spell[key];
	const char *name = NULL;
	sfIntRect rec = { 0, 0, 128, 128 };
	sfVector2f pos = { 0, 0 };

	config_setting_lookup_string(set, "name", &name);
	config_setting_lookup_bool(set, "unlocked", ((int *) &spell->unlock));
	config_setting_lookup_int(set, "value", &spell->val);
	config_setting_lookup_int(set, "level", &spell->level);

	spell->rec = rec;
	spell->pos = pos;
	spell->texture = get_texture(rpg, ((char *) name));
	spell->form = sfSprite_create();
	sfSprite_setTexture(spell->form, spell->texture, true);
	sfSprite_setTextureRect(spell->form, rec);
}

void load_hero_spells(config_setting_t *set, rpg_t *rpg)
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
	for (int i = 0; count >0 && i < count; i++) {
		rpg->battle->hero->spell[i] = malloc(sizeof(spell_t));
		if (rpg->battle->hero->spell[i] == NULL)
			continue;
		spell = config_setting_get_elem(spells, i);
		if (spell != NULL)
			load_spell_datas(spell, rpg, i);
	}
}

void load_hero_default_values(hero_t *hero, player_t *player)
{
	sfVector2f scale = { 1.25, 1.25 };
	sfIntRect rec = { 0, 0, 64, 64 };
	sfVector2f pos = { 0, 5 };

	hero->pos = pos;
	hero->rec = rec;
	hero->alive = hero->sword = true;
	hero->played = hero->select = hero->move = hero->attack = false;
	hero->target = hero->spell_id = -1;
	hero->form = sfSprite_create();
	sfSprite_setPosition(hero->form, pos);
	sfSprite_setTexture(hero->form, player->texture, true);
	sfSprite_setTextureRect(hero->form, rec);
	sfSprite_setScale(hero->form, scale);
}

void load_hero_datas(config_setting_t *set, rpg_t *rpg)
{
	config_setting_lookup_int(set, "heal", &rpg->battle->hero->hp);
	config_setting_lookup_int(set, "damage", &rpg->battle->hero->dmg);
	config_setting_lookup_int(set, "armor", &rpg->battle->hero->armor);
	load_hero_default_values(rpg->battle->hero, rpg->player);
	load_hero_spells(set, rpg);

	rpg->battle->hero->hp_max = rpg->battle->hero->hp;
	rpg->battle->hero->spell_id = -1;
}
