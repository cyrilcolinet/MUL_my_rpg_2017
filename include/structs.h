/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** structs header file
*/

# ifndef STRUCT_RPG_H
# define STRUCT_RPG_H

# include "rpg.h"

// Struct prototypes
struct 	texture_t;
struct 	button_t;
struct 	slider_t;
struct 	assets_t;
struct 	options_t;
struct 	rpg_t;

// Enumerations declarations
typedef enum state_e {
		gameUnknown,
		gameWait,
		gameRun,
		gameEnd,
		gamePause,
		gameOnSettings,
		gameOnCredits
}		state_e;

// Structs declarations
typedef struct texture_t {
		char 			*name;
		char 			*file;
		sfTexture 		*texture;
		sfSprite 		*sp;
} 		texture_t;

typedef struct button_t {
		char			*name;
		sfVector2f		pos;
		void 			(*onClick)(struct rpg_t *, struct button_t *);
		void 			(*onHover)(struct rpg_t *, struct button_t *);
		void 			(*onStart)(struct rpg_t *, struct button_t *);
		state_e 		state;
		sfSprite 		*sprite;
		sfIntRect 		rect;
		sfIntRect 		normal_rect;
		bool			pressed;
		struct button_t *next;
} 		button_t;

typedef struct slider_t {
		char 			*name;
		sfVector2f		range;
		sfText			*text;
		int 			mid_axis;
		void 			(*onSlide)(struct rpg_t *, struct slider_t *);
		state_e 		state;
		button_t 		*btn;
		struct slider_t *next;
} 		slider_t;

typedef struct assets_t {
		char 			*name;
		char 			*file;
		sfTexture 		*texture;
		sfSprite 		*sp;
		sfIntRect 		rec;
		struct assets_t *next;
} 		assets_t;

typedef struct options_t {
		int 			volume;
} 		options_t;

typedef struct rpg_t {
		sfRenderWindow	*win;
		sfSound 		*sound;
		sfFont 			*font;
		state_e 		state;
		state_e 		last_st;
		options_t 		options;
		assets_t 		*assets;
		button_t 		*btn;
		slider_t 		*slides;
}		rpg_t;

# endif
