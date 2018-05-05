/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** sprite_manager_functions
*/

# include "rpg.h"

sfSprite *get_sprite(rpg_t *rpg, char *name)
{
	assets_t *tmp = rpg->assets;

	while (tmp != NULL) {
		if (my_strequ(tmp->name, name))
			return (tmp->sp);
		tmp = tmp->next;
	}

	return (NULL);
}

sfTexture *get_texture(rpg_t *rpg, char *name)
{
	assets_t *tmp = rpg->assets;

	while (tmp != NULL) {
		if (my_strequ(tmp->name, name)) {
			return (tmp->texture);
		}
		tmp = tmp->next;
	}

	return (NULL);
}
