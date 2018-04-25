/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** configuration (header file)
*/

# ifndef RPG_CONFIGURATION_H
# define RPG_CONFIGURATION_H

# include "rpg.h"

// init_config.c
void 	init_menus_configuration(rpg_t *);
int 	init_config(rpg_t *);

/*
** Main menu
** Contains assets, button configurations
** @type (menu_e) stMain
*/

// menus/main_menu_buttons.c
void 	main_menu_btn_play(rpg_t *);
void 	main_menu_btn_credits(rpg_t *);
void 	main_menu_btn_settings(rpg_t *);
void 	main_menu_btn_quit(rpg_t *);

// menus/main_menu_config.c
void 	configure_buttons(rpg_t *);
void 	main_menu_config(rpg_t *);

# endif
