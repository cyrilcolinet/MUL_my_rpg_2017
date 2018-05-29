/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** animations utilities
*/

# include "rpg.h"

void wait_second(float wait)
{
	sfTime t;
	sfClock *clk;

	clk = sfClock_create();
	t = sfTime_Zero;
	sfClock_restart(clk);
	while (sfTime_asSeconds(t) < sfTime_asSeconds(sfSeconds(wait)))
		t = sfClock_getElapsedTime(clk);
	sfClock_destroy(clk);
}
