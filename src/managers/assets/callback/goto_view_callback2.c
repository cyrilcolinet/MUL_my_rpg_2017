/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** goto_view_callback2 functions
*/

# include "rpg.h"

void cb_goto_pause_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	if (rpg->img != NULL)
		sfImage_destroy(rpg->img);
	rpg->img = sfRenderWindow_capture(rpg->win);
	if (rpg->img == NULL)
		return;
	rpg->last_st = gameRun;
	rpg->state = gamePause;
	info("Openning pause menu...");
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | En pause");
}
