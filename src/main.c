/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main function
*/

#include "rpg.h"

int main(int args, char const * const * const argv, char **env)
{
	game_t *game = NULL;
	state_interface_t *state_interface_play = NULL;


	(void)args;
	(void)argv;
	CHECK_DO(env == NULL, return (CL_ERROR_CODE);)
	game = init_game();
//TODO add state list to constructor
	state_interface_play = init_state_interface(init_play("assets/graphics/tilesets/tileset.png", "assets/graphics/spritesheets/pp.png"), &set_method_play);
	game->state_list = cl_calloc(sizeof(state_interface_t) * NBR_STATES);
	game->state_list[0] = state_interface_play;

	while (sfRenderWindow_isOpen(game->window)) {
		while (sfRenderWindow_pollEvent(game->window, &game->event)) {
			event_close_window(game->event, game->window);
			game->state_list[game->state]->event_handler(game);
		}
		sfRenderWindow_clear(game->window, sfBlack);
		game->state_list[game->state]->display_handler(game->state_list[game->state]->state_item, game->window);
		sfRenderWindow_display(game->window);
	}
	del_game(game);
	return 0;
}