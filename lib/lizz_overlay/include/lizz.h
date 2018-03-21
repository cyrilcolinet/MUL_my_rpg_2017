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

// lizz.c
lizz_t 		*lizz_configure(void);
int 		lizz_start(bool debug);
void 		lizz_stop(void);

// buttons/btn_textures.c
void 		lizz_btn_set_texture(btn_t *btn, char *path, sfIntRect *rect);

// # # # # # # # # # # # # # # //
// #       MANAGERS          # //
// # # # # # # # # # # # # # # //

// Buttons
int 		lizz_btn_create(char *name, menu_e belongsTo);
btn_t	*lizz_get_btn(char *name, menu_e belongsTo);

# endif
