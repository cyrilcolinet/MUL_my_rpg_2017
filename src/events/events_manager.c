/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** events_manager functions
*/

# include "rpg.h"

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
