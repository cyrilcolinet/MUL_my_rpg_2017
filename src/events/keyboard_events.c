/*
** EPITECH PROJECT, 2018
** keyboard_events
** File description:
** rpg
*/

#include "rpg.h"

static void key_escape_pause_exit(rpg_t *rpg, sfEvent *event)
{
	if (event->key.code == sfKeyEscape) {
		if (rpg->state == gameWait) {
			sfRenderWindow_close(rpg->win);
		} else if (rpg->state != gameRun && rpg->state != gamePause) {
			cb_return_action(rpg, NULL);
		}
	}
}

void keyboard_events(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtKeyReleased) {
		key_escape_pause_exit(rpg, event);
	}
}
