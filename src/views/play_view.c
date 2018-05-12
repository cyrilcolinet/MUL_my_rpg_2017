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

	if (sp == NULL)
		return;

	if (rpg->battle->run)
		battle_management(rpg, rpg->battle);
	else if (!rpg->battle->run) {
		sfRenderWindow_drawSprite(rpg->win, sp, NULL);
		sfRenderWindow_drawSprite(rpg->win, (sfSprite *)*rpg->player->
			sprite, rpg->player->render_state);
		sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek");
	}
}
