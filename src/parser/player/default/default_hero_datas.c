/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** default_hero_datas loader functions
*/

# include "rpg.h"

void default_hero_spells_extra(spell_t **spell)
{
	(*spell)->form = sfSprite_create();
	sfSprite_setTexture((*spell)->form, (*spell)->texture, true);
	sfSprite_setTextureRect((*spell)->form, (*spell)->rec);
}

void default_hero_spells(rpg_t *rpg, hero_t *hero)
{
	char *names[] = { "heal", "fire", "ice", "storm" };
	sfIntRect rec = { 0, 0, 128, 128 };
	sfVector2f pos = { 0, 0 };

	hero->spell = malloc(sizeof(spell_t *) * 4);
	if (hero->spell == NULL)
		return;

	for (int i = 0; i < 4; i++) {
		hero->spell[i] = malloc(sizeof(spell_t));
		if (hero->spell[i] == NULL)
			continue;
		hero->spell[i]->texture = get_texture(rpg, names[i]);
		hero->spell[i]->unlock = false;
		hero->spell[i]->val = 50;
		hero->spell[i]->level = 1;
		hero->spell[i]->rec = rec;
		hero->spell[i]->pos = pos;
		default_hero_spells_extra(&hero->spell[i]);
	}
}

void default_hero_datas(rpg_t *rpg)
{
	hero_t *hero = rpg->battle->hero;
	sfVector2f scale = { 1.25, 1.25 };
	sfIntRect rec = { 0, 0, 64, 64 };
	sfVector2f pos = { 0, 5 };

	hero->hp = hero->hp_max = 120;
	hero->dmg = 40;
	hero->armor = 30;
	hero->sword = false;
	hero->pos = pos;
	hero->rec = rec;
	hero->alive = true;
	hero->played = hero->select = hero->move = hero->attack = false;
	hero->target = hero->spell_id = -1;
	hero->form = sfSprite_create();
	sfSprite_setPosition(hero->form, pos);
	sfSprite_setTexture(hero->form, rpg->player->texture, true);
	sfSprite_setTextureRect(hero->form, rec);
	sfSprite_setScale(hero->form, scale);
	default_hero_spells(rpg, hero);
}
