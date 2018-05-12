/*
** EPITECH PROJECT, 2018
** free
** File description:
** rpg
*/

# include "rpg.h"

static void free_fight(battle_t *battle, int n)
{
	for (int i = 0; i < 120; i++) {
		sfRectangleShape_destroy(battle->fight[n]->map[i]);
	}
	free(battle->fight[n]->map);
	for (int i = 0; i < battle->fight[n]->number_enemy; i++) {
		sfSprite_destroy(battle->fight[n]->enemy[i]->form);
		sfRectangleShape_destroy(battle->fight[n]->enemy[i]->frame);
		free(battle->fight[n]->enemy[i]);
	}
	free(battle->fight[n]->enemy);
	free(battle->fight[n]);
}

void free_all(rpg_t *rpg)
{
	for (int i = 0; i < rpg->battle->number_fight; i++) {
		free_fight(rpg->battle, i);
	}
	free(rpg->battle->fight);
	sfSprite_destroy(rpg->battle->hero->form);
	sfTexture_destroy(rpg->battle->hero->img);
	sfText_destroy(rpg->battle->text);
	sfClock_destroy(rpg->battle->clock);
	free(rpg->battle->hero);
	for (int i = 0; i < 10; i++)
		free(rpg->battle->map[i]);
	free(rpg->battle->map);
	sfRectangleShape_destroy(rpg->battle->icone);
	sfRectangleShape_destroy(rpg->battle->background);
	for (int i = 0; i < 4; i++)
		sfTexture_destroy(rpg->battle->texture[i]);
	free(rpg->battle->texture);
	free(rpg->player);
}
