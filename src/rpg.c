/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg functions
*/

# include "rpg.h"

void exit_game(rpg_t *rpg)
{
	destroy_assets(rpg);
	destroy_buttons(rpg);
	destroy_slides(rpg);
	sfRenderWindow_destroy(rpg->win);
	sfSound_destroy(rpg->sound);
	sfClock_destroy(rpg->clock);
	info("Window destroyed!");
}

int rpg_game(rpg_t *rpg)
{
	sfEvent event;
	int status = load_assets(rpg);

	if (status != 0)
		return (status);

	while (sfRenderWindow_isOpen(rpg->win)) {
		poll_event(rpg, &event);
		sfRenderWindow_clear(rpg->win, sfBlack);
		display_view(rpg);
		draw_buttons(rpg);
		sfRenderWindow_display(rpg->win);
	}
	info("Window closed. Exiting...");
	exit_game(rpg);

	return (status);
}

int rpg_main(int ac, char **av)
{
	int status = check_arguments(ac, av);
	rpg_t *rpg = NULL;

	if (status != -1)
		return (status);

	rpg = configure_struct();
	if (rpg == NULL)
		return (84);

	info("Main rpg_t struct correctly configured.");
	status = rpg_game(rpg);
	free(rpg);
	info("Project correctly exited. Bye!");

	return (status);
}
