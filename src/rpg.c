/*
** EPITECH PROJECT, 2018
** cook
** File description:
** cook functions
*/

# include "cook.h"

void exit_game(cook_t *cook)
{
	destroy_assets(cook);
	destroy_buttons(cook);
	destroy_slides(cook);
	sfRenderWindow_destroy(cook->win);
	sfSound_destroy(cook->sound);
	info("Window destroyed!");
}

int rpg_game(cook_t *cook)
{
	sfEvent event;
	int status = load_assets(cook);

	if (status != 0)
		return (status);

	info("Starting game loop...");
	while (sfRenderWindow_isOpen(cook->win)) {
		poll_event(cook, &event);
		sfRenderWindow_clear(cook->win, sfBlack);
		fct_pointers(cook);
		draw_buttons(cook);
		sfRenderWindow_display(cook->win);
	}
	info("Window closed. Exiting...");
	exit_game(cook);

	return (status);
}

int rpg_main(int ac, char **av)
{
	int status = check_arguments(ac, av);
	cook_t *cook = NULL;

	if (status != -1)
		return (status);

	cook = configure_struct();
	if (cook == NULL)
		return (84);

	info("Main rpg_t struct correctly configured.");
	status = rpg_game(cook);
	free(cook);
	info("Project correctly exited. Bye!");

	return (status);
}
