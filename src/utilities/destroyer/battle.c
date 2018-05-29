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

void free_battle(rpg_t *rpg)
{
	for (int i = 0; i < rpg->battle->number_fight; i++)
		free_fight(rpg->battle, i);

	free(rpg->battle->fight);
	sfSprite_destroy(rpg->battle->hero->form);
	sfText_destroy(rpg->battle->text);
	sfClock_destroy(rpg->battle->clock);
	free(rpg->battle->hero);
	for (int i = 0; i < 10; i++)
		free(rpg->battle->map[i]);
	free(rpg->battle->map);
	sfRectangleShape_destroy(rpg->battle->icone);
	sfRectangleShape_destroy(rpg->battle->background);
	free(rpg->battle->texture);
}
