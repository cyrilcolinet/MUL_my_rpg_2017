/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** windows_utils functions
*/

# include "cook.h"

void set_favicon(cook_t *cook)
{
	sfImage *icon = sfImage_createFromFile("assets/favicon.png");

	if (icon == NULL)
		return;

	info("Setting icon...");
	sfRenderWindow_setIcon(cook->win, 256, 256, sfImage_getPixelsPtr(icon));
}