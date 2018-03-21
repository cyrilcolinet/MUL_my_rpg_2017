/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lizz overlay structs header file
*/

# ifndef LIZZ_OVERLAY_STRUCTS_H
# define LIZZ_OVERLAY_STRUCTS_H

typedef struct button_t {
	struct button_t *next;
} 	button_t;

typedef struct lizz_t {
	bool 			debug;
	button_t 		*btn;
}	lizz_t;

# endif
