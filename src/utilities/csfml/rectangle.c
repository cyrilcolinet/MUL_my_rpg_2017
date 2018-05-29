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

	while (tmp != NULL) {
		if (tmp->state == rpg->state) {
			sprite = tmp->sprite;
			rec = tmp->normal_rect;
			tmp->pressed = false;
			tmp->hovered = false;
			if (sprite != NULL)
				sfSprite_setTextureRect(sprite, rec);
		}
		tmp = tmp->next;
	}
}
