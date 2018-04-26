/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ressource
*/

#include "rpg.h"

char *tricat(char const *str1, char const *str2, char const *str3)
{
	uint64_t len = 0;
	char *str = NULL;

	len = cl_strlen(str1) + cl_strlen(str2) + cl_strlen(str3);
	str = cl_calloc(sizeof(char) * (len + 1));
	for (uint64_t i = 0; i < cl_strlen(str1); i++)
		str[i] = str1[i];
	for (uint64_t i = 0; i < cl_strlen(str2); i++)
		str[i + cl_strlen(str1)] = str2[i];
	for (uint64_t i = 0; i < cl_strlen(str3); i++)
		str[i + cl_strlen(str1) + cl_strlen(str2)] = str3[i];
	return str;
}

void load_tilesets(lua_State *state, ressource_t *ressource)
{
	char *base_path = NULL;
	char *ext = NULL;
	char *name = NULL;

	load_table(state, TILESET_DATA_PATH);
	ressource->number_tileset = get_number_s(state, "number");
	base_path = get_string_s(state, "dir");
	ext = get_string_s(state, "ext_img");
	ressource->tileset = cl_calloc(sizeof(tileset_t *) * ressource->number_tileset);
	goto_table_s(state, "tilesets");
	for (uint64_t i = 1; i <= ressource->number_tileset; i++) {
		name = get_string_n(state, i);
		ressource->tileset[i - 1] = init_tileset(tricat(base_path, name, ext));
		free(name);
	}
	lua_pop(state, 2);
}

ressource_t *init_ressource(lua_State *state)
{
	ressource_t *ressource = NULL;

	ressource = cl_calloc(sizeof(ressource_t));
	load_tilesets(state, ressource);
	return ressource;
}

void del_ressource(void *self)
{
	ressource_t *_self = NULL;

	_self = (ressource_t *)self;
	for (uint64_t i = 0; i < _self->number_tileset; i++)
		del_tileset(_self->tileset[i]);
	free(_self->tileset);
	free(_self);
}