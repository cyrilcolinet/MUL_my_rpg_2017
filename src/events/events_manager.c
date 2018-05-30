/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** events_manager functions
*/

# include "rpg.h"

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

void keyboard_events(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtKeyReleased) {
		if (event->key.code == sfKeyEscape) {
			if (rpg->state == gameWait) {
				sfRenderWindow_close(rpg->win);
			} else if (rpg->state != gameRun && \
			rpg->state != gamePause) {
				cb_return_action(rpg, NULL);
			}
		}
	}
}

bool can_be_paused(rpg_t *rpg)
{
	state_e current = rpg->state;

	if (current == gameBattle || current == gameRun)
		return (true);

	return (false);
}

void focus_events(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtLostFocus && can_be_paused(rpg))
		cb_goto_pause_view(rpg, NULL);
}

void poll_event(rpg_t *rpg, sfEvent *event)
{
	while (sfRenderWindow_pollEvent(rpg->win, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(rpg->win);
		else {
			views_events(rpg, event);
			mouse_events(rpg, event);
			keyboard_events(rpg, event);
			focus_events(rpg, event);
		}
	}
}
