/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** array of pointers of the function representating the states of the game
*/

#include "cook.h"

void fct_pointers(cook_t *cook)
{
	void (*fun_ptr_arr[])(cook_t *) = {
		NULL,
		wait_loop,
		run_loop,
		NULL,
		NULL,
		options_view,
		credits_view
	};

	(*fun_ptr_arr[cook->state])(cook);
}
