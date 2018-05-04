/*
** EPITECH PROJECT, 2018
** my_rpg_2017
*

* File description:
** lua header
*/

#ifndef _LUA_H
#define _LUA_H

#ifndef lua_h
#include "../extern_libs/lua-5.3.4/src/lua.h"
#endif

#ifndef lauxlib_h
#include "../extern_libs/lua-5.3.4/src/lauxlib.h"
#endif

#ifndef lualib_h
#include "../extern_libs/lua-5.3.4/src/lualib.h"
#endif

bool load_table(lua_State *state, char const *path);
bool goto_table_s(lua_State *state, char const *key);
bool goto_table_n(lua_State *state, uint64_t key);

char *get_string_s(lua_State *state, char const *key);
char *get_string_n(lua_State *state, uint64_t key);
int64_t get_number_s(lua_State *state, char const *key);
int64_t  get_number_n(lua_State *state, uint64_t key);

#endif