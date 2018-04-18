/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** drawable header
*/

#ifndef _DRAW_H
#define _DRAW_H

typedef enum {
	LEFT,
	RIGHT,
	UP,
	DOWN
} direction_t;

typedef enum {
	STATIC_1,
	WALK_1,
	STATIC_2,
	WALK_2
} state_t;

typedef struct {
	void *draw_item;
	void (*draw)(void *, sfRenderWindow *);
	void (*del)(void *);
} draw_interface_t;

typedef struct {
	sfSprite *map;
} map_t;

typedef struct {
	direction_t direction;
	state_t state;
	sfSprite *sprite;
	sfIntRect rect;
} sprite_t;

//interface
draw_interface_t *init_draw_interface(void *draw_item, void (*set_method)(draw_interface_t *draw_interface));
void del_draw_interface(draw_interface_t *draw_interface);
//map
map_t *init_map(char const *path);
void draw_map(void *self, sfRenderWindow *window);
void del_map(void *self);
void set_method_sprite(draw_interface_t *draw_interface);
//sprite
sprite_t *init_sprite(char const *path);
void draw_sprite(void *self, sfRenderWindow *window);
void del_sprite(void *self);
void set_method_sprite(draw_interface_t *draw_interface);

#endif