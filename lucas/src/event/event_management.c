/*
** EPITECH PROJECT, 2018
** event_management
** File description:
** rpg
*/

#include "test.h"

static void exit_function(data_t *data, sfEvent event)
{
	if (event.type == sfEvtClosed
	|| (event.type == sfEvtKeyPressed
	&& event.key.code == sfKeyEscape))
		sfRenderWindow_close(data->window);
}

void event_management(data_t *data)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(data->window, &event)) {
		exit_function(data, event);
		deplacement(data, event);
	}
}
