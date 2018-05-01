/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** sprite_manager_functions
*/

# include "cook.h"

sfSprite *get_sprite(cook_t *cook, int id)
{
	assets_t *tmp = cook->assets;

	while (tmp->next != NULL) {
		if (tmp->next->id == id)
			return (tmp->next->sp);
		tmp = tmp->next;
	}

	return (NULL);
}

sfTexture *get_texture(cook_t *cook, int id)
{
	assets_t *tmp = cook->assets;

	while (tmp->next != NULL) {
		if (tmp->next->id == id) {
			return (tmp->next->texture);
		}
		tmp = tmp->next;
	}

	return (NULL);
}