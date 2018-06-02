/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** battle destroyer
*/

# include "rpg.h"

void free_fight(battle_t *battle, int n)
{
	for (int i = 0; i < 120; i++)
		sfRectangleShape_destroy(battle->fight[n]->map[i]);
	free(battle->fight[n]->map);
	for (int i = 0; i < battle->fight[n]->number_enemy; i++) {
		sfSprite_destroy(battle->fight[n]->enemy[i]->form);
		sfRectangleShape_destroy(battle->fight[n]->enemy[i]->frame);
		free(battle->fight[n]->enemy[i]);
	}

	free(battle->fight[n]->enemy);
	free(battle->fight[n]);
}

void free_hero_spells(rpg_t *rpg)
{
	for (int i = 0; i < 4; i++) {
		if (rpg->battle->hero->spell[i]->form != NULL)
			sfSprite_destroy(rpg->battle->hero->spell[i]->form);
		if (rpg->battle->hero->spell[i]->texture != NULL)
			sfTexture_destroy(rpg->battle->hero->spell[i]->texture);
		sfRectangleShape_destroy(rpg->battle->hero->spell[i]->icone);
		free(rpg->battle->hero->spell[i]);
	}
	free(rpg->battle->hero->spell);
}

void destroy_battle(rpg_t *rpg)
{
	for (int i = 0; i < rpg->battle->number_fight; i++)
		free_fight(rpg->battle, i);
	free(rpg->battle->fight);
	sfSprite_destroy(rpg->battle->hero->form);
	sfText_destroy(rpg->battle->text);
	sfClock_destroy(rpg->battle->clock);
//	free_hero_spells(rpg);
	free(rpg->battle->hero);
	for (int i = 0; i < 10; i++)
		free(rpg->battle->map[i]);
	free(rpg->battle->map);
	sfTexture_destroy(rpg->battle->head);
	sfRectangleShape_destroy(rpg->battle->icone);
	sfRectangleShape_destroy(rpg->battle->background);
	free(rpg->battle->texture);
}
