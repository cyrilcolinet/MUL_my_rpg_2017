/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player destroyer
*/

# include "rpg.h"

void destroy_content(rpg_t *rpg)
{
	for (int i = 0; rpg->map[i]; i++) {
		sfSprite_destroy(rpg->map[i]->sprite);
		for (int j = 0; rpg->map[i]->layer[j]; j++)
			free(rpg->map[i]->layer[j]);
		free(rpg->map[i]->layer);
		free(rpg->map[i]->it);
		free(rpg->map[i]);
	}
	free(rpg->map);
}
