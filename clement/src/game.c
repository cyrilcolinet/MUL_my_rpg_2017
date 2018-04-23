/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** game
*/

#include "rpg.h"

sfRenderWindow *init_window(void)
{
	sfRenderWindow *window = NULL;
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

	window = sfRenderWindow_create(mode, WINDOW_TITLE, sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	return window;
}

game_t *init_game(void)
{
	game_t *game = NULL;

	game = my_calloc(sizeof(game_t));
	game->window = init_window();
	game->state_list = NULL;
	game->state = PLAY;
	game->prev = PLAY;
	game->tick = 10;
	return game;
}

void del_game(game_t *game)
{
	sfRenderWindow_destroy(game->window);
	for (u_int64_t i = 0; i < NBR_STATES; i++)
		game->state_list[i]->del(game->state_list[i]);
	del_play(game->state_list[0]);
	free(game->state_list);
	free(game);
}

void game_update_tick(void *data)
{
	game_t *game = NULL;
	sfInt32 *tick = NULL;
	sfClock *clock = NULL;

	game = data;
	tick = &game->tick;
	clock = game->clock;
	while (1)
		 *tick = (u_int32_t)floor(((sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) % 250) * 120) / 250);
}