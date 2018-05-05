/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** events_manager functions
*/

# include "rpg.h"

void mouse_manager(rpg_t *rpg, sfEvent *event)
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

void poll_event(rpg_t *rpg, sfEvent *event)
{
	while (sfRenderWindow_pollEvent(rpg->win, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(rpg->win);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(rpg->win);

		mouse_manager(rpg, event);
	}
}
