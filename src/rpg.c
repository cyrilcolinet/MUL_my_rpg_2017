/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg functions
*/

# include "rpg.h"

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
	return (status);
}

int rpg_main(int ac, char **av)
{
	int status = check_arguments(ac, av);
	rpg_t *rpg = NULL;
	sfVector2f size = { 218, 208 };

	if (status != -1)
		return (status);
	rpg = configure_struct();
	rpg->texture = sfTexture_create(1920, 1080);
	if (rpg == NULL)
		return (84);
	sfRenderWindow_setFramerateLimit(rpg->win, 60);
	sfRectangleShape_setSize(rpg->shape, size);
	sfRectangleShape_setFillColor(rpg->shape, sfTransparent);
	sfRectangleShape_setOutlineColor(rpg->shape, sfWhite);
	sfRectangleShape_setOutlineThickness(rpg->shape, 5);
	status = rpg_game(rpg);
	exit_game(rpg);
	free(rpg);

	return (status);
}
