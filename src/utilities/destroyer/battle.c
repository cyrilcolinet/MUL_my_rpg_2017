/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** battle destroyer
*/

# include "rpg.h"

void destroy_figth(fight_t *fight)
{
	for (int i = 0; i < 120; i++)
		sfRectangleShape_destroy(fight->map[i]);
	free(fight->map);

	for (int i = 0; i < fight->number_enemy; i++) {
		if (fight->
			enemy[i]->
			form)
			sfSprite_destroy(fight->enemy[i]->form);
		sfRectangleShape_destroy(fight->enemy[i]->frame);
		free(fight->enemy[i]);
	}

	free(fight->enemy);
	free(fight);
}

void destroy_hero_values(hero_t *hero)
{
	sfSprite_destroy(hero->form);

	for (int i = 0; i < 4; i++) {
		if (hero->spell[i]->form != NULL)
			sfSprite_destroy(hero->spell[i]->form);
		sfRectangleShape_destroy(hero->spell[i]->icone);
		free(hero->spell[i]);
	}

	free(hero->spell);
	free(hero);
}

void destroy_battle(rpg_t *rpg)
{
	for (int i = 0; i < rpg->battle->number_fight; i++)
		destroy_figth(rpg->battle->fight[i]);
	free(rpg->battle->fight);

	if (rpg->battle->hero != NULL)
		destroy_hero_values(rpg->battle->hero);
	sfText_destroy(rpg->battle->text);
	sfClock_destroy(rpg->battle->clock);

	for (int i = 0; i < 10; i++)
		free(rpg->battle->map[i]);
	free(rpg->battle->map);
	sfRectangleShape_destroy(rpg->battle->icone);
	sfRectangleShape_destroy(rpg->battle->background);
}
