/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** debug functions (header file)
*/

# ifndef DEBUG_rpg_H
# define DEBUG_rpg_H

# include "structs.h"

// debug/logger.c
void 	info(char *);
void 	warning(char *);
void 	print_key_value_str(char *, char *);
void 	print_key_value_int(char *, int);

// debug/buttons_debugger.c
void 	print_buttons_infos(button_t *, char *[], char *[]);
void 	print_buttons(rpg_t *);

// debug/assets_debugger.c
void 	print_assets_infos(assets_t *, char *[]);
void 	print_assets(rpg_t *);

// debug/sliders_debugger.c
void 	print_sliders_infos(slider_t *, char *[], char *[]);
void 	print_sliders(rpg_t *);

# endif
