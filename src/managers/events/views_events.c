/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** views_events functions
*/

# include "rpg.h"

void test(rpg_t *rpg, sfEvent *event)
{
	printf("%s\n", "salut a toi");
}

void views_events(rpg_t *rpg, sfEvent *event)
{
	void (*tab[])(rpg_t *, sfEvent *) = {
		NULL,
		test,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL
	};

	if ((*tab[rpg->state]) == NULL)
		return;

	info("Event state handled!");
	(*tab[rpg->state])(rpg, event);
}
