/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** structs header file
*/

# ifndef STRUCT_RPG_H
# define STRUCT_RPG_H

# include <SFML/Audio.h>
# include <SFML/Config.h>
# include <SFML/Graphics.h>
# include <SFML/Network.h>
# include <SFML/OpenGL.h>
# include <SFML/System.h>
# include <SFML/Window.h>
# include <SFML/System.h>

# include <time.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <dirent.h>

# include "libconfig.h"

// Struct prototypes
struct 	texture_t;
struct 	button_t;
struct 	slider_t;
struct 	assets_t;
struct	sound_t;
struct 	options_t;
struct	enemy_t;
struct	fight_t;
struct	spell_t;
struct 	hero_t;
struct 	battle_t;
struct	inventory_t;
struct	player_t;
struct 	interact_t;
struct	map_t;
struct 	rpg_t;
struct	conf_res_t;

// Enumerations declarations
typedef enum state_e {
	gameUnknown,
	gameWait,
	gameRun,
	gameEnd,
	gamePause,
	gameOnSettings,
	gameOnCredits,
	gameHistory,
	gameBattle,
	gameSelect,
	gameQuitWSave,
	gameLoadSave,
	gameTutorial,
	gameInventory,
	gameSkills,
	gameQuests
}	state_e;

// Configuration striucts
typedef struct conf_ress_t {
	char 		*name;
	char 		*path;
}	conf_ress_t;

typedef struct conf_sett_t {
	config_t 	cfg;
	config_setting_t *set;
	bool 		error;
}	conf_sett_t;

// Structs declarations
typedef struct texture_t {
	char 		*name;
	char 		*file;
	sfTexture 	*texture;
	sfSprite 	*sp;
} 	texture_t;

typedef struct button_t {
	char		*name;
	sfVector2f	pos;
	void 		(*onClick)(struct rpg_t *, struct button_t *);
	void 		(*onHover)(struct rpg_t *, struct button_t *);
	void 		(*onStart)(struct rpg_t *, struct button_t *);
	state_e 	state;
	sfSprite 	*sprite;
	sfIntRect 	rect;
	sfIntRect 	normal_rect;
	bool		pressed;
	bool		hovered;
	struct button_t *next;
} 	button_t;

typedef struct slider_t {
	char 		*name;
	sfVector2f	range;
	sfText		*text;
	int 		mid_axis;
	void 		(*onSlide)(struct rpg_t *, struct slider_t *);
	state_e 	state;
	button_t 	*btn;
	struct slider_t *next;
} 	slider_t;

typedef struct assets_t {
	char 		*name;
	char 		*file;
	sfTexture 	*texture;
	sfSprite 	*sp;
	sfIntRect 	rec;
	struct assets_t *next;
} 	assets_t;

typedef struct sound_t {
	char 		*name;
	char 		*file;
	sfSoundBuffer	*buffer;
	sfSound 	*sound;
	struct sound_t 	*next;
}	sound_t;

typedef struct options_t {
	float 		sound_vol;
	float 		music_vol;
} 	options_t;

// BEGIN BATTLE STRUCTS
typedef struct enemy_t {
	sfVector2f 	pos;
	sfIntRect 	rec;
	sfSprite 	*form;
	sfRectangleShape *frame;
	sfTexture 	*img;
	char		*stuff;
	bool 		alive;
	bool 		played;
	bool		sword;
	int 		hp;
	int 		hp_max;
	int 		dmg;
	int 		armor;
} enemy_t;

typedef struct fight_t {
	sfRectangleShape **map;
	sfVector2f 	pos;
	int 		number_enemy;
	bool 		enemy_turn;
	int		curent;
	enemy_t 	**enemy;
} fight_t;

typedef struct spell_t {
	sfSprite	*form;
	sfRectangleShape *icone;
	sfTexture	*texture;
	sfTexture	*img;
	sfIntRect	rec;
	sfVector2f	pos;
	bool		unlock;
	bool		cast;
	int		val;
	int 		level;
} spell_t;

typedef struct hero_t {
	spell_t		**spell;
	sfIntRect 	rec;
	sfSprite 	*form;
	sfVector2f 	pos;
	sfVector2f 	nw;
	bool 		alive;
	bool 		select;
	bool 		played;
	bool 		move;
	bool 		attack;
	bool		sword;
	int		spell_id;
	int 		target;
	int 		hp;
	int 		hp_max;
	int 		dmg;
	int 		armor;
} hero_t;

typedef struct battle_t {
	bool 		run;
	sfVector2f 	mouse;
	int 		id;
	int 		**map;
	int 		number_fight;
	hero_t 		*hero;
	fight_t 	**fight;
	sfRectangleShape *icone;
	sfRectangleShape *background;
	sfTexture 	**texture;
	sfText 		*text;
	sfTime 		time;
	sfClock 	*clock;
} battle_t;
// END BATTLE STRUCT

typedef struct equipement_t {
	char 		*name;
	sfTexture	*texture;
	bool		equiped;
	bool		unlock;
	int		type;
	int		dmg;
	int		armor;
	int		hp;
	int		magic;
	sfVector2f	pos;
} equipement_t;

typedef struct inventory_t {
	equipement_t	**obj;
	sfRectangleShape *win;
	sfRectangleShape *current;
	sfRectangleShape *armor;
	sfRectangleShape *weapon;
	sfRectangleShape **slot;
	sfVector2f	mouse;
} inventory_t;

typedef struct pnj_t  {
	sfSprite	*sprite;
	sfTexture	*texture;
	sfIntRect	rec;
	char		**dialogue;
} pnj_t;

typedef struct quest_t  {
	sfRectangleShape *win;
	pnj_t		**pnj;
	bool		*unlock;
	bool		*done;
	int		id;
} quest_t;

typedef struct interact_t {
	char 		**msg;
	sfIntRect	rec;
	bool		active;
	bool		in_zone;
}	interact_t;

typedef struct player_t {
	sfClock		*clock;
	sfTime 		timer;
	sfSprite	*sprite;
	sfTexture 	*texture;
	sfIntRect	rec;
	sfVector2f	pos;
	char 		*name;
	int 		sexe;
	int 		level;
	int 		skills;
	inventory_t	*inventory;
	quest_t		*quest;
}	player_t;

typedef struct map_t {
	char 		*texture;
	int		**layer;
	interact_t	**it;
}	map_t;

typedef struct save_t {
	char 		*name;
	sfIntRect	rec;
	sfClock 	*clock;
	sfSprite	*sprite;
	sfTexture	*texture;
	sfText		*name_text;
	sfText		*lvl_text;
	sfText		*pname_text;
	char 		*player_name;
	int 		heal;
	int 		damage;
	int 		armor;
	int 		level;
	button_t 	*btn;
	struct save_t 	*next;
}	save_t;

typedef struct rpg_t {
	sfRenderWindow	*win;
	sfFont		*font;
	sfTexture	*texture;
	state_e		state;
	sfSprite	*capture;
	state_e		last_st;
	sfText		*text;
	sfClock		*clock;
	int		map_id;
	map_t		**map;
	sound_t		*sounds;
	options_t	options;
	assets_t	*assets;
	button_t	*btn;
	player_t	*player;
	slider_t	*slides;
	battle_t	*battle;
	save_t 		*saves;
}	rpg_t;

# endif
