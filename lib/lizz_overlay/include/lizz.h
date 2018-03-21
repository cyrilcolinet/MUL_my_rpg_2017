/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lizz library header file
*/

# ifndef LIZZ_OVERLAY_H
# define LIZZ_OVERLAY_H

# include "structs.h"

lizz_t 		*lizz;

lizz_t 		*lizz_configure(bool debug);
int 		lizz_start(bool debug);
void 		lizz_stop(void);

# endif
