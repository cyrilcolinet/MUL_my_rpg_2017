/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** args_handling functions
*/

# include "rpg.h"

int check_arguments(int ac, char **av)
{
	if (ac == 2 && my_strequ(av[1], "-h")) {
		my_putstr("USAGE:\n\t./my_rpg [-h, -d]\n\n");
		my_putstr("DESCRIPTION:\n\t[-h]\t");
		my_putstr("Display help page (this page).\n");
		my_putstr("\t[-d]\tActivate debug mode.\n");
		return (0);
	} else if (ac == 2 && my_strequ(av[1], "-d")) {
		debug = true;
		info("Debug mode enabled.");
		return (-1);
	} else if (ac != 1) {
		write(2, "Invalid number of arguments.\n", 29);
		write(2, "Usage: ./my_rpg [-h]\n", 22);
		return (84);
	}

	return (-1);
}
