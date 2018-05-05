/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** goto_view_callback functions
*/

# include "rpg.h"

void cb_goto_credits_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	info("Openning credits menu...");
	rpg->last_st = rpg->state;
	rpg->state = gameOnCredits;
	reset_to_normal_rect(rpg);
}

void cb_goto_play_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	rpg->state = gameRun;
	rpg->last_st = gameUnknown;
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Jouer");
	reset_to_normal_rect(rpg);
}

void cb_goto_settings_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	info("Openning settings menu...");
	reset_to_normal_rect(rpg);
	rpg->last_st = rpg->state;
	rpg->state = gameOnSettings;
}
