/*
** EPITECH PROJECT, 2018
** textboxe
** File description:
** rpg
*/

#include "test.h"

void test(void)
{
	data_t *data = malloc(sizeof(data_t));

	init_data(data);
	data->id = 0;
	data->mouse.x = 0;
	data->mouse.y = 0;
	while (sfRenderWindow_isOpen(data->window)) {
		sfRenderWindow_clear(data->window, sfBlack);

		event_management(data);

		fill_map_state(data, data->id);

		sfRenderWindow_drawRectangleShape
			(data->window, data->background, NULL);
		display_map(data, data->id);
		display_current_target(data);
		display_interface(data);

		sfRenderWindow_display(data->window);
	}
	free_all(data);
}
