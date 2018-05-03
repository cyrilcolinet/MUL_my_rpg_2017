/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** state interface
*/

#include "rpg.h"

state_interface_t *init_state_interface(void *state_item,
	void (*set_method)(state_interface_t *state_interface))
{
	state_interface_t *state_interface = NULL;

	state_interface = cl_calloc(sizeof(state_interface_t));
	state_interface->state_item = state_item;
	set_method(state_interface);
	return state_interface;
}

void del_state_interface(state_interface_t *state_interface)
{
	state_interface->del(state_interface->state_item);
	free(state_interface);
}