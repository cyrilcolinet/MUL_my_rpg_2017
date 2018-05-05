/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** array of pointers of the function representating the states of the game
*/

#include "rpg.h"

void fct_pointers(rpg_t *rpg)
{
	void (*fun_ptr_arr[])(rpg_t *) = {
		NULL,
		wait_loop,
		run_loop,
		NULL,
		NULL,
		options_view,
		credits_view
	};

	(*fun_ptr_arr[rpg->state])(rpg);
}
