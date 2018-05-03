/*
** EPITECH PROJECT, 2018
** event_management
** File description:
** rpg
*/

#include "battle.h"

static void exit_function(data_t *data, sfEvent event)
{
	if (event.type == sfEvtClosed
	|| (event.type == sfEvtKeyPressed
	&& event.key.code == sfKeyEscape))
		sfRenderWindow_close(data->window);
}

static void mouse_coord(battle_t *battle, sfEvent event)
{
	if (event.type == sfEvtMouseMoved) {
		battle->mouse.x = event.mouseMove.x;
		battle->mouse.y = event.mouseMove.y;
	}
}

void event_management(data_t *data, battle_t *battle)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(data->window, &event)) {
		exit_function(data, event);
		mouse_coord(battle, event);
		if (battle->run) {
			interaction(battle, event);
			if (event.type == sfEvtKeyPressed) {
				if (event.key.code == sfKeyN) {
					reset_map_state(battle);
					battle->fight[battle->id]->enemy_turn = true;
				}
					if (event.key.code == sfKeyX) {
					battle->hero->played = false;
					battle->hero->move = false;
					battle->hero->attack = false;
					battle->id++;
				}
				if (event.key.code == sfKeyW) {
					battle->hero->played = false;
					battle->hero->move = false;
					battle->hero->attack = false;
					battle->id--;
				}
				if (event.key.code == sfKeyA)
					battle->run = false;
			}
		} else
			if (event.type == sfEvtKeyPressed) {
				if (event.key.code == sfKeyA)
					battle->run = true;
			}
	}
}
