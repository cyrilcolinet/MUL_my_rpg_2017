/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** draw header
*/

# ifndef _DRAW_H
# define _DRAW_H

# undef SPRITE_HEIGHT
# define SPRITE_HEIGHT 32

# undef SPRITE_WIDTH
# define SPRITE_WIDTH 32

# undef SPRITESHEET_HEIGHT
# define SPRITESHEET_HEIGHT 4

# undef SPRITESHEET_WIDTH
# define SPRITESHEET_WIDTH 4

#undef TILE_SIDE
#define TILE_SIDE 32


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

typedef struct draw_interface_s {
	void *draw_item;
	void (*draw)(void *self, sfRenderWindow *window);
	void (*del)(void *self);
} draw_interface_t;

typedef struct map_s {
	u_int64_t height;
	u_int64_t width;
	uint64_t tileset;
	sfVertexArray *layers[3];
	uint8_t *hidden_layer;
} map_t;

typedef struct tile_s {
	sfVertex tile[4];
	uint8_t layer;
} tile_t;

typedef struct sprite_s {
	direction_t direction;
	state_t state;
	sfSprite *sprite;
	sfIntRect rect;
} sprite_t;

typedef struct anim_s {
	void *anim_item;
	uint8_t delay;
	uint8_t time_0;
	void (*anim)(void *self);
	void (*del)(void *self);
} anim_t;

//interface
draw_interface_t *init_draw_interface(void *, void (*)(draw_interface_t *));
void 	del_draw_interface(void *self);
//map
map_t *init_map(char const *path, lua_State *state);
void draw_map(void *self, tileset_t **tileset, sfRenderWindow *window);
void del_map(void *self);
void set_method_sprite(draw_interface_t *draw_interface);
//sprite
sprite_t *init_sprite(char const *path);
void draw_sprite(void *self, sfRenderWindow *window);
void del_sprite(void *self);
void set_method_sprite(draw_interface_t *draw_interface);
void sprite_walk(void *sprite);
void set_method_sprite_anim(anim_t *anim);
//anim
anim_t *init_anim(void *anim_item, u_int32_t delay,
	void (*set_method)(anim_t *anim));
//tile
tile_t init_tile(sfVector2f pos, sfVector2f tex);
void tile_append(tile_t tile, sfVertexArray *array);

#endif
