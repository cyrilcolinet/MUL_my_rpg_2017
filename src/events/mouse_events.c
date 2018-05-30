/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** mouse_events functions
*/

# include "rpg.h"

void mouse_button_pressed(rpg_t *rpg, sfMouseButtonEvent mouse)
{
	button_t *btn = is_button(rpg, mouse.x, mouse.y);

	if (btn != NULL) {
		btn->onClick(rpg, btn);
		return;
	}
	reset_to_normal_rect(rpg);
}

void mouse_button_released(rpg_t *rpg, sfMouseButtonEvent mouse)
{
	button_t *btn = is_button(rpg, mouse.x, mouse.y);

	if (btn != NULL) {
		btn->onStart(rpg, btn);
		return;
	}
	reset_to_normal_rect(rpg);
}

void mouse_moved(rpg_t *rpg, sfMouseMoveEvent mouse)
{
	slider_t *tmp = NULL;
	button_t *btn = is_button(rpg, mouse.x, mouse.y);

	if (btn != NULL) {
		tmp = rpg->slides;
		btn->onHover(rpg, btn);

		if (btn->pressed) {
			while (tmp != NULL) {
				if (my_strequ(tmp->btn->name, btn->name)) {
					if (tmp->onSlide != NULL)
						tmp->onSlide(rpg, tmp);
					return;
				}
				tmp = tmp->next;
			}
		}
		return;
	}
	reset_to_normal_rect(rpg);
}

void mouse_events(rpg_t *rpg, sfEvent *event)
{
	sfEventType type = event->type;

	if (type == sfEvtMouseButtonPressed) {
		mouse_button_pressed(rpg, event->mouseButton);
	} else if (type == sfEvtMouseButtonReleased) {
		mouse_button_released(rpg, event->mouseButton);
	} else if (type == sfEvtMouseMoved) {
		mouse_moved(rpg, event->mouseMove);
	}
}
