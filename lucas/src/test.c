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
	while (sfRenderWindow_isOpen(data->window)) {
		sfRenderWindow_clear(data->window, sfBlack);
		event_management(data);
		display_map(data, 1);

		sfRenderWindow_display(data->window);
	}
	free_all(data);
}
