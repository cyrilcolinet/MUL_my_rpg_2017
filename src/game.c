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
	lua_State *state = NULL;

	state = luaL_newstate();
	game = cl_calloc(sizeof(game_t));
	game->window = init_window();
	game->state_list = NULL;
	game->state = PLAY;
	game->prev = PLAY;
	game->tick = 0;
	game->game_clock = sfThread_create(&game_update_tick, game);
	lua_close(state);
	sfThread_launch(game->game_clock);
	return game;
}

void del_game(void *self)
{
	game_t *_self = NULL;

	_self = (game_t *)self;
	sfRenderWindow_destroy(_self->window);
	for (u_int64_t i = 0; i < NBR_STATES; i++)
		_self->state_list[i]->del(_self->state_list[i]);
	del_play(_self->state_list[0]);
	free(_self->state_list);
	sfThread_terminate(_self->game_clock);
	sfThread_destroy(_self->game_clock);
	free(_self);
}

void game_update_tick(void *data)
{
	game_t *game = NULL;
	uint8_t *tick = NULL;
	sfClock *clock = NULL;

	game = (game_t *)data;
	tick = &game->tick;
	clock = sfClock_create();
	while (1)
		 *tick = (u_int32_t)floor(((sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) % 250) * 120) / 250);
}