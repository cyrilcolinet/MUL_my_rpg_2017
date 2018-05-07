/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** assets_loader manager functions
*/

# include "rpg.h"

void start_loader(rpg_t *rpg)
{
	rpg->font = sfFont_createFromFile("assets/fonts/Cyberspace.otf");

	configure_main_view(rpg);
	configure_settings_view(rpg);
	configure_credits_view(rpg);
	configure_pause_view(rpg);
}
