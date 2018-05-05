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

# endif
