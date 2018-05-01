/*
** EPITECH PROJECT, 2018
** cook
** File description:
** events_manager functions
*/

# include "cook.h"

void mouse_manager(cook_t *cook, sfEvent *event)
{
	sfEventType type = event->type;

	if (type == sfEvtMouseButtonPressed) {
		mouse_button_pressed(cook, event->mouseButton);
	} else if (type == sfEvtMouseButtonReleased) {
		mouse_button_released(cook, event->mouseButton);
	} else if (type == sfEvtMouseMoved) {
		mouse_moved(cook, event->mouseMove);
	}
}

void poll_event(cook_t *cook, sfEvent *event)
{
	while (sfRenderWindow_pollEvent(cook->win, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(cook->win);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(cook->win);

		mouse_manager(cook, event);
	}
}
