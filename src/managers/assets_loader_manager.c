/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** assets_loader manager functions
*/

# include "rpg.h"

void load_buttons(rpg_t *rpg)
{
	load_wait_buttons(rpg);
	load_settings_buttons(rpg);
	load_credits_buttons(rpg);
}

void load_sliders(rpg_t *rpg)
{
	load_options_sliders(rpg);
}

void start_loader(rpg_t *rpg)
{
	rpg->font = sfFont_createFromFile("assets/GROBOLD.ttf");

	load_buttons(rpg);
	load_sliders(rpg);
}
