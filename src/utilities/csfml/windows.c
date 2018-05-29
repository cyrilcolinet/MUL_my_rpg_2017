/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** windows_utils functions
*/

# include "rpg.h"

void set_favicon(rpg_t *rpg)
{
	sfImage *icon = sfImage_createFromFile("assets/favicon.png");

	if (icon == NULL)
		return;

	info("Setting icon...");
	sfRenderWindow_setIcon(rpg->win, 256, 256, sfImage_getPixelsPtr(icon));
}
