/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text selection events
*/

# include "rpg.h"

void perform_text_entered(rpg_t *rpg, sfEvent *event, sfTextEvent type)
{
	
}

bool ev_selection_text(rpg_t *rpg, sfEvent *event)
{
	sfTextEvent type;

	if (event->type == sfEvtTextEntered) {
		type = event->text;
		perform_text_entered(rpg, event, type);
	}

	return (true);
}
