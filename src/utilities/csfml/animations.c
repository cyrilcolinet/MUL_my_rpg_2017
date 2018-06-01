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

float get_slot_position(int slot_id)
{
	switch (slot_id) {
		case 1:
		return (464);

		case 2:
		return (588);

		case 3:
		return (729);
	}

	return (332);
}
