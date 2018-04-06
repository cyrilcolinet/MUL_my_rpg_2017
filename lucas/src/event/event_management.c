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

static void mouse_coord(data_t *data, sfEvent event)
{
	if (event.type == sfEvtMouseMoved) {
		data->mouse.x = event.mouseMove.x;
		data->mouse.y = event.mouseMove.y;
	}
}

void event_management(data_t *data)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(data->window, &event)) {
		exit_function(data, event);
		mouse_coord(data, event);
		deplacement(data, event);
	}
}
