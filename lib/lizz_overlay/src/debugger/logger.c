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
	if (lizz->debug) {
		lizz_print(2, msg);
	}
}
