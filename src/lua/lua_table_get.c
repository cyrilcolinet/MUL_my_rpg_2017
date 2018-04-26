/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lua table goto
*/

#include "rpg.h"

char *get_string_s(lua_State *state, char const *key)
{
	char *string = NULL;

	lua_pushstring(state, key);
	lua_gettable(state, -2);
	string = cl_strdup(lua_tostring(state, -1));
	lua_pop(state, 1);
	return string;
}

char *get_string_n(lua_State *state, uint64_t key)
{
	char *string = NULL;

	lua_pushnumber(state, key);
	lua_gettable(state, -2);
	string = cl_strdup(lua_tostring(state, -1));
	lua_pop(state, 1);
	return string;
}

int64_t get_number_s(lua_State *state, char const *key)
{
	int64_t number = 0;

	lua_pushstring(state, key);
	lua_gettable(state, -2);
	number = lua_tonumber(state, -1);
	lua_pop(state, 1);
	return number;
}

int64_t get_number_n(lua_State *state, uint64_t key)
{
	int64_t number = 0;

	lua_pushnumber(state, key);
	lua_gettable(state, -2);
	number = lua_tonumber(state, -1);
	lua_pop(state, 1);
	return number;
}