/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ressource header
*/

# ifndef _RESSOURCE_H
# define _RESSOURCE_H

# undef TILESET_DATA_PATH
# define TILESET_DATA_PATH 		("assets/data/tilesets.lua")

# undef TILESET_NAME_LEN
# define TILESET_NAME_LEN 		(128)

#undef MAP_DATA_PATH
#define MAP_DATA_PATH "assets/data/maps.lua"

#undef PATH_CHAR
#define PATH_CHAR '/'

# undef EXT_CHAR
# define EXT_CHAR 				('.')

typedef struct tileset_s {
	sfRenderStates tileset;
	uint8_t id;
	uint64_t height;
	uint64_t width;
} tileset_t;

typedef struct ressource_s {
	tileset_t **tileset;
	uint64_t number_tileset;
} ressource_t;

//ressource
ressource_t *init_ressource(lua_State *state);
void 	del_ressource(void *self);
void 	load_tilesets(lua_State *state, ressource_t *ressource);

//tileset
tileset_t *init_tileset(char const *name);
void 	del_tileset(void *self);

# endif
