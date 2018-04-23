/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rpg main functions
*/

# include "rpg.h"

static bool get_debugger(int ac, char **av)
{
	if (ac != 2) {
		write(2, "Wrong argument number.\n", 23);
		write(2, "Usage: ./my_rpg [-d]\n", 21);
		return (false);
	}

	if (ac == 2 && my_strequ(av[1], "-d"))
		return (true);

	return (false);
}

int game(rpg_t *rpg)
{
	return (0);
}

int rpg_main(int ac, char **av)
{
	int status = 0;
	bool debug = get_debugger(av, av);
	rpg_t *rpg = initialize_struct();

	if (rpg == NULL)
		return (84);

	if (lizz_start(&rpg->lizz, debug) < 0)
		return (84);

	status = game(rpg);
	lizz_stop(rpg->lizz);
	free_all(rpg);
	return (0);
}
