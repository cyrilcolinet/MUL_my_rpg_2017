/*
** EPITECH PROJECT, 2018
** run_loop
** File description:
** loop of the game
*/

# include "cook.h"

void run_loop(cook_t *cook)
{
	sfRenderWindow_drawSprite(cook->win, get_sprite(cook, aMap1), NULL);
}
