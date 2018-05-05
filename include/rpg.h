/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg functions (header file)
*/

# ifndef PG_H
# define PG_H

# include <SFML/Graphics.h>
# include <SFML/Audio.h>

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <dirent.h>

# include "my.h"
# include "structs.h"

// Debug global variable
bool 	debug;

typedef struct c_assets_t {
	char 	*name;
	char 	*filename;
}	c_assets_t;

// rpg.c
void 		exit_game(rpg_t *);
int 		rpg_game(rpg_t *);
int			rpg_main(int, char **);

/*
** Assets manager
** Manage buttons, sliders, views and menus
*/

// assets_manager.c
int 		new_asset(rpg_t *, texture_t);
int			create_texture(rpg_t *, char *, char *);
c_assets_t 	**configure_assets(void);
int 		load_assets(rpg_t *);

// assets_loader_manager.c
void 		load_buttons(rpg_t *);
void 		start_loader(rpg_t *);

/*
** Utilities
** Struct utils, pointers utils and more...
*/

// args_utils.c
int 		check_arguments(int, char **);

// debug_utils.c
void 		info(char *);
void 		warning(char *);
void 		print_key_value_str(char *, char *);
void 		print_key_value_int(char *, int);

// display_utils.c
void 		display_view(rpg_t *);

// rect_utils.c
void 		reset_to_normal_rect(rpg_t *);

// settings_utils.c
char 		*my_itoa(int);
char 		*get_sound_in_str(int);

// sound_utils.c
void 		configure_audio(rpg_t *);

// struct_utils.c
void 		destroy_buttons(rpg_t *);
void 		destroy_assets(rpg_t *);
void 		destroy_slides(rpg_t *);
rpg_t 		*configure_struct(void);

// windows_tils.c
void 		set_favicon(rpg_t *);

# endif
