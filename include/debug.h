/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** debug functions (header file)
*/

# ifndef DEBUG_COOK_H
# define DEBUG_COOK_H

# include "structs.h"

// debug/logger.c
void 	info(char *msg);
void 	warning(char *msg);
void 	print_key_value_str(char *key, char *value);
void 	print_key_value_int(char *key, int value);

// debug/buttons_debugger.c
void 	print_buttons_infos(button_t *btn, char *bt[], char *st[]);
void 	print_buttons(cook_t *cook);

// debug/assets_debugger.c
void 	print_assets_infos(assets_t *asset, char *id[]);
void 	print_assets(cook_t *cook);

// debug/sliders_debugger.c
void 	print_sliders_infos(slider_t *slide, char *sd[], char *st[]);
void 	print_sliders(cook_t *cook);

# endif
