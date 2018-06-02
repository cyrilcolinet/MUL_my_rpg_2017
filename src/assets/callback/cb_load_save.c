/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** cb_load_save functions
*/

# include "rpg.h"

void cb_load_save(rpg_t *rpg, button_t *btn)
{
	bool parsed = false;

	parsed = player_parser(rpg, btn->name);
	if (!parsed) {
		write(2, "Unable to parse ", 16);
		write(2, btn->name, my_strlen(btn->name));
		write(2,  " file.\n", 7);
		return;
	}

	cb_goto_play_view(rpg, btn);
}
