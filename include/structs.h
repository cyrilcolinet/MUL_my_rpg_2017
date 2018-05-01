/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** structs header file
*/

# ifndef STRUCT_COOK_H
# define STRUCT_COOK_H

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// Struct prototypes
struct 	texture_t;
struct 	button_t;
struct 	slider_t;
struct 	assets_t;
struct 	options_t;
struct 	cook_t;

// Debug global variable
bool 	debug;

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

typedef enum btnType_e {
		btnPlay,
		btnPause,
		btnCredits,
		btnQuit,
		btnSettings,
		btnReturn,
		btnMute,
		btnVolume,
		btnNull
} 		btnType_e;

typedef enum slideType_e {
		slideVolume,
		slideNull
}		slideType_e;

// Structs declarations
typedef struct texture_t {
		int 			id;
		char 			*file;
		sfTexture 		*texture;
		sfSprite 		*sp;
} 		texture_t;

typedef struct button_t {
		btnType_e 		type;
		sfVector2f		pos;
		void 			(*onClick)(struct cook_t *, struct button_t *);
		void 			(*onHover)(struct cook_t *, struct button_t *);
		void 			(*onStart)(struct cook_t *, struct button_t *);
		state_e 		state;
		sfSprite 		*sprite;
		sfIntRect 		rect;
		sfIntRect 		normal_rect;
		bool			pressed;
		struct button_t *next;
} 		button_t;

typedef struct slider_t {
		slideType_e		type;
		sfVector2f		range;
		sfText			*text;
		int 			mid_axis;
		void 			(*onSlide)(struct cook_t *, struct slider_t *);
		state_e 		state;
		button_t 		*btn;
		struct slider_t *next;
} 		slider_t;

typedef struct assets_t {
		int 			id;
		char 			*file;
		sfTexture 		*texture;
		sfSprite 		*sp;
		sfIntRect 		rec;
		struct assets_t *next;
} 		assets_t;

typedef struct options_t {
		int 			volume;
} 		options_t;

typedef struct cook_t {
		sfRenderWindow	*win;
		sfSound 		*sound;
		sfFont 			*font;
		state_e 		state;
		state_e 		last_st;
		options_t 		options;
		assets_t 		*assets;
		button_t 		*btn;
		slider_t 		*slides;
}		cook_t;

# endif
