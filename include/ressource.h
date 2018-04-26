/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ressource header
*/

#ifndef _RESSOURCE_H
#define _RESSOURCE_H

typedef struct {
	sfRenderStates tileset;
	char name[TILESET_NAME_LEN];
	uint64_t height;
	uint64_t width;
} tileset_t;

typedef struct {
	tileset_t **tileset;
	u_int64_t number_tileset;
} ressource_t;

//tileset
tileset_t *init_tileset(char const *name);
void del_tileset(void *self);

#endif