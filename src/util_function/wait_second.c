/*
** EPITECH PROJECT, 2018
** wait_second
** File description:
** wait time function
*/

#include "rpg.h"

void wait_second(float wait)
{
	sfTime time;
	sfClock *clock;

	clock = sfClock_create();
	time = sfTime_Zero;
	sfClock_restart(clock);
	while (sfTime_asSeconds(time) < sfTime_asSeconds(sfSeconds(wait)))
		time = sfClock_getElapsedTime(clock);
	sfClock_destroy(clock);
}
