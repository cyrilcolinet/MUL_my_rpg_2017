/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** drawable interface
*/

#include "rpg.h"

draw_interface_t *init_draw_interface(void *draw_item,
	void (*set_method)(draw_interface_t *draw_interface))
{
	draw_interface_t *draw_interface = NULL;

	draw_interface = cl_calloc(sizeof(draw_interface_t));
	draw_interface->draw_item = draw_item;
	set_method(draw_interface);
	return draw_interface;
}

void del_draw_interface(void *self)
{
	draw_interface_t *_self = NULL;

	_self = (draw_interface_t *)self;
	_self->del(_self->draw_item);
	free(_self);
}