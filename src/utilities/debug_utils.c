/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** debug_utils
*/

# include "rpg.h"

void info(char *msg)
{
	if (debug) {
		my_putstr(" [INF]  ");
		my_putstr(msg);
		my_putchar('\n');
	}
}

void warning(char *msg)
{
	if (debug) {
		my_putstr(" [WARN] ");
		my_putstr(msg);
		my_putchar('\n');
	}
}

void print_key_value_str(char *key, char *value)
{
	if (debug) {
		my_putstr("\t");
		my_putstr(key);
		my_putstr("\t=> ");
		my_putstr(value);
		my_putstr("\n");
	}
}

void print_key_value_int(char *key, int value)
{
	if (debug) {
		my_putstr("\t");
		my_putstr(key);
		my_putstr("\t=> ");
		my_put_nbr(value);
		my_putstr("\n");
	}
}
