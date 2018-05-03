/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main function
*/

# include "rpg.h"

int main(int ac, char **av, char **env)
{
	game_t *game = NULL;

	(void)args;
	(void)argv;
	CHECK_DO(env == NULL, return (CL_ERROR_CODE);)
	game = init_game();
	while (sfRenderWindow_isOpen(game->window)) {
		while (sfRenderWindow_pollEvent(game->window, &game->event)) {
			event_close_window(game->event, game->window);
			game->state_list[game->state]->event_handler(game);
		}
		sfRenderWindow_clear(game->window, sfBlack);
		game->state_list[game->state]->display_handler(game->state_list[game->state]->state_item, game->ressource, game->window);
		sfRenderWindow_display(game->window);
	}
	del_game(game);
	return 0;
}
