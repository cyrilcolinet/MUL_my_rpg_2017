/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** mouse_events functions
*/

# include "cook.h"

void mouse_button_pressed(cook_t *cook, sfMouseButtonEvent mouse)
{
	button_t *btn = is_button(cook, mouse.x, mouse.y);

	if (btn != NULL) {
		btn->onClick(cook, btn);
		return;
	}

	reset_to_normal_rect(cook);
}

void mouse_button_released(cook_t *cook, sfMouseButtonEvent mouse)
{
	button_t *btn = is_button(cook, mouse.x, mouse.y);

	if (btn != NULL) {
		btn->onStart(cook, btn);
		return;
	}

	reset_to_normal_rect(cook);
}

void mouse_moved(cook_t *cook, sfMouseMoveEvent mouse)
{
	slider_t *tmp = NULL;
	button_t *btn = is_button(cook, mouse.x, mouse.y);

	if (btn != NULL) {
		tmp = cook->slides;
		btn->onHover(cook, btn);

		if (btn->pressed) {
			while (tmp->next != NULL) {
				if (tmp->next->btn->type == btn->type) {
					tmp->next->onSlide(cook, tmp->next);
					return;
				}
				tmp = tmp->next;
			}
		}

		return;
	}

	reset_to_normal_rect(cook);
}
