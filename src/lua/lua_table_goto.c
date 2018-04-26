/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lua table get
*/

#include "rpg.h"

bool load_table(lua_State *state, char const *path)
{
	return !(luaL_dofile(state, path) || !lua_istable(state, -1));
}

bool goto_table_s(lua_State *state, char const *key)
{
	lua_pushstring(state, key);
	CHECK_DO(lua_gettable(state, -2) == LUA_TTABLE, return false;)
	return true;
}

bool goto_table_n(lua_State *state, uint64_t key)
{
	lua_pushnumber(state, key);
	CHECK_DO(lua_gettable(state, -2) == LUA_TTABLE, return false;)
	return true;
}