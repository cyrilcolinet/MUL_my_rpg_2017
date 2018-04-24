/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_events functions
*/

# include "rpg.h"

void poll_events(rpg_t *rpg, sfEvent *event)
{
	if (event->type == sfEvtClosed || (event->type == sfEvtKeyReleased \
	&& event->key.code == sfKeyEscape))
		sfRenderWindow_close(rpg->win);
}
