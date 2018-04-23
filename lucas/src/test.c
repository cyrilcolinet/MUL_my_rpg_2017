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
	data->id = 1;
	while (sfRenderWindow_isOpen(data->window)) {
		sfRenderWindow_clear(data->window, sfBlack);
		event_management(data);
		fill_map_state(data, data->id);
		display_interface(data);
		display_map(data, data->id);
		sfRenderWindow_display(data->window);
	}
	free_all(data);
}
