/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rpg main functions
*/

# include "rpg.h"

static bool get_debugger(int ac, char **av)
{
	if (ac > 2) {
		write(2, "Wrong argument number.\n", 23);
		write(2, "Usage: ./my_rpg [-d]\n", 21);
		return (false);
	}

	if (ac == 2 && my_strequ(av[1], "-d"))
		return (true);

	return (false);
}

int game_loop(rpg_t *rpg)
{
	
}

int game(rpg_t *rpg)
{
	int status = 0;
	sfVideoMode mode = { 1920, 1080, 32 };

	rpg->win = sfRenderWindow_create(mode, "RPG", sfFullscreen, NULL);
	if (rpg->win == NULL)
		return (84);

	sfRenderWindow_setFramerateLimit(rpg->win, 60);
	sfRenderWindow_setMouseCursorVisible(rpg->win, sfFalse);

	status = game_loop(rpg);
	return (status);
}

int rpg_main(int ac, char **av)
{
	int status = 0;
	bool debug = get_debugger(ac, av);
	rpg_t *rpg = initialize_struct();

	if (rpg == NULL)
		return (84);
	if (lizz_start(&rpg->lizz, debug) < 0)
		return (84);
	if ((status = init_config(rpg)) != 0)
		return (status);

	status = game(rpg);
	lizz_stop(rpg->lizz);
	free_all(rpg);
	return (status);
}
