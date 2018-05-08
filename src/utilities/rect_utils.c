/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rect_utils functions
*/

# include "rpg.h"

void reset_to_normal_rect(rpg_t *rpg)
{
	button_t *tmp = rpg->btn;
	sfSprite *sprite = NULL;
	sfIntRect rec;

	while (tmp->next != NULL) {
		if (tmp->next->state == rpg->state) {
			sprite = tmp->next->sprite;
			rec = tmp->next->normal_rect;
			tmp->next->pressed = false;
			tmp->next->hovered = false;
			if (sprite != NULL)
				sfSprite_setTextureRect(sprite, rec);
		}
		tmp = tmp->next;
	}
}
