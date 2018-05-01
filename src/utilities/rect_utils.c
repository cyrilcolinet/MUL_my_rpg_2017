/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** rect_utils functions
*/

# include "cook.h"

void reset_to_normal_rect(cook_t *cook)
{
	button_t *tmp = cook->btn;
	sfSprite *sprite = NULL;
	sfIntRect rec;

	while (tmp->next != NULL) {
		if (tmp->next->state == cook->state) {
			sprite = tmp->next->sprite;
			rec = tmp->next->normal_rect;
			tmp->next->pressed = false;
			sfSprite_setTextureRect(sprite, rec);
		}
		tmp = tmp->next;
	}
}
