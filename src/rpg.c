/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rpg functions
*/

# include "rpg.h"

int game_start(game_t *game)
{
	state_interface_t *state = game->state_list[game->state];

	while (sfRenderWindow_isOpen(game->window)) {
		while (sfRenderWindow_pollEvent(game->window, &game->event)) {
			event_close_window(game->event, game->window);
			state->event_handler(game);
		}

		sfRenderWindow_clear(game->window, sfBlack);
		state->display_handler(state->state_item, game->window);
		sfRenderWindow_display(game->window);
	}

	return (0);
}

int main_rpg(void)
{
	int res = 0;
	game_t *game = init_game();

	if (game == NULL)
		return (84);

	res = initialize_states(game);
	if (res != 0)
		return (res);

	res = game_start(game);
	del_game(game);
	return (0);
}
