/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** play loader
*/

#include "rpg.h"

void load_map(lua_State *state, play_t *play)
{
	char *base_path = NULL;
	char *ext = NULL;
	char *name = NULL;

	CHECK_DO(!load_table(state, MAP_DATA_PATH), return;)
	play->map_number = get_number_s(state, "number");
	play->map = cl_calloc(sizeof(map_t *) * (play->map_number + 1));
	base_path = get_string_s(state, "dir");
	ext = get_string_s(state, "ext");
	goto_table_s(state, "maps");
	for (uint64_t i = 1; i <= play->map_number; i++) {
		name = get_string_n(state, i);
		play->map[i - 1] = init_map(tricat(base_path, name, ext),
			state);
		free(name);
	}
	lua_pop(state, 2);
}