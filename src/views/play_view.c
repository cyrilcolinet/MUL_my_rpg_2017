/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** play_view functions
*/

# include "rpg.h"

void play_view(rpg_t *rpg)
{
	sfSprite *sp = get_sprite(rpg, "map1");
	sfTransform transform = {{0.75, 0, 0, 0, 0.75, 0, 0, 0, 1}};
	sfRenderStates state = {sfBlendAlpha, transform, NULL, NULL};

	if (sp == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sp, NULL);
	sfRenderWindow_drawSprite(rpg->win, (sfSprite *)*rpg->player->sprite, &state);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek");

	if (rpg->battle->run)
		battle_management(rpg, rpg->battle);
}