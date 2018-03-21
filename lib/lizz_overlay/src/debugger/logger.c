/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** logger debug functions
*/

# include "lizz.h"
# include "utils.h"
# include "debug.h"

void lizz_info(char *msg)
{
	if (_debug) {
		lizz_print(1, " INF -> ");
		lizz_print(1, msg);
	}
}

void lizz_error(char *msg)
{
	if (_debug) {
		lizz_print(2, " ERR -> ");
		lizz_print(2, msg);
	}
}
