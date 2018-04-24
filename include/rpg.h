/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Rpg functions (header file)
*/

# ifndef RPG_H
# define RPG_H

# define STYLE 		(sfClose)

# include <SFML/Audio.h>
# include <SFML/Config.h>
# include <SFML/Graphics.h>
# include <SFML/Network.h>
# include <SFML/OpenGL.h>
# include <SFML/System.h>
# include <SFML/Window.h>
# include <SFML/System.h>

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <fcntl.h>

# include "lizz/lizz.h"
# include "my.h"
# include "structs.h"
# include "configuration.h"

// rpg.c
bool 	get_debugger(int, char **);
int 	game_loop(rpg_t *, sfEvent *);
int 	game(rpg_t *);
int 	rpg_main(int, char **);

/*
** Tasks
** List of threaded tasks for all menus
** (Only thread named and used for overlay works)
*/

// background_task.c
void 	bg_task(void *);

/*
** Events management
** Contains mousen keyboard, joystick, and others
** Exclude lizz_overlay events polling
*/

// init_events.c
void 	poll_events(rpg_t *, sfEvent *);

/*
** Utilities
** PArsing, list, management and graphic utils
*/

// struct_utils.c
void 	free_all(rpg_t *);
rpg_t	*initialize_struct(void);

# endif
