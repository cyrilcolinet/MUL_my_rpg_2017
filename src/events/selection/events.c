/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** selection events
*/

# include "rpg.h"

void ev_selection(rpg_t *rpg, sfEvent *event)
{
	int i = -1;
	bool reloop = false;
	bool (*evt[])(rpg_t *, sfEvent *) = {
		ev_selection_text, ev_selection_sexe, NULL 
	};

	while (evt[++i]) {
		reloop = evt[i](rpg, event);
		if (!reloop)
			return;
	}
}
