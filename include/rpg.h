/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Rpg functions (header file)
*/

# ifndef RPG_H
# define RPG_H

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

typedef struct rpg_t {
	lizz_t		*lizz;
}	rpg_t;

int 	rpg_main(int, char **);

// utils/struct_utils.c
void 	free_all(rpg_t *);
rpg_t	*initialize_struct(void);

# endif
