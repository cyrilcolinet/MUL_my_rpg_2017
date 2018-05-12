/*
** EPITECH PROJECT, 2018
** free
** File description:
** rpg
*/

# include "rpg.h"

//will be removed when map_t will be used
static void free_layer(int **layer)
{
	for (int i = 0; i < 34; i++)
		free(layer[i]);
	free(layer);
}

static void free_fight(battle_t *battle, int n)
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

void free_all(rpg_t *rpg)
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
	free(rpg->player->render_state);
	free_layer(rpg->player->layer);
	free(rpg->player);
}
