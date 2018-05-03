/*
** EPITECH PROJECT, 2018
** test
** File description:
** rpg
*/

#include "battle.h"

void draw_all(data_t *data)
{
	sfRenderWindow_drawRectangleShape
		(data->window, data->battle->background, NULL);
	display_map(data, data->battle, data->battle->id);
	display_current_target(data->battle);
	display_interface(data, data->battle);
}

void test(void)
{
	data_t *data = malloc(sizeof(data_t));

	init_data(data);
	data->battle->id = 0;
	data->battle->run = false;
	data->battle->mouse.x = 0;
	data->battle->mouse.y = 0;
	while (sfRenderWindow_isOpen(data->window)) {
		sfRenderWindow_clear(data->window, sfBlack);
		event_management(data, data->battle);
		if (data->battle->run) {
			if (data->battle->fight[data->battle->id]->enemy_turn)
				enemy_turn(data, data->battle);
			fill_map_state(data->battle, data->battle->id);
			draw_all(data);
		}
		sfRenderWindow_display(data->window);
	}
	free_all(data);
}
