/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** event
*/

#include "rpg.h"

void event_close_window(sfEvent event, sfRenderWindow *window)
{
	if (event.type == sfEvtClosed ||
		(event.type == sfEvtKeyReleased &&
		event.key.code == sfKeyEscape))
		sfRenderWindow_close(window);
}