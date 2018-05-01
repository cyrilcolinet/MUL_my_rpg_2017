/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** state manager
*/

# include "rpg.h"

void init_main_state(game_t *game)
{
	void *item = NULL;
	char *map = NULL;
	char *sprite = NULL;

	map = "assets/graphics/tilesets/tileset.png";
	sprite = "assets/graphics/spritesheets/yssoufle.png";
	item = init_play(map, sprite);
	if (item == NULL)
		return;

	game->state_list[MAIN] = init_state_interface(item, &set_method_play);
}

void init_play_state(game_t *game)
{
	void *item = NULL;
	char *map = NULL;
	char *sprite = NULL;

	map = "assets/graphics/tilesets/tileset.png";
	sprite = "assets/graphics/spritesheets/pp.png";
	item = init_play(map, sprite);
	if (item == NULL)
		return;

	game->state_list[PLAY] = init_state_interface(item, &set_method_play);
}

int initialize_states(game_t *game)
{
	game->state_list = cl_calloc(sizeof(state_interface_t) * NBR_STATES);

	if (game->state_list == NULL)
		return (84);

	init_main_state(game);
	init_play_state(game);
	return (0);
}
