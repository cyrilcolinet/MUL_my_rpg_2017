/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** goto_view_callback functions
*/

# include "rpg.h"

void cb_goto_main_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	rpg->state = gameRun;
	rpg->last_st = gameUnknown;
	reset_to_normal_rect(rpg);
	info("Openning main menu...");
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Menu Principal");
}

void cb_goto_credits_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	rpg->last_st = rpg->state;
	rpg->state = gameOnCredits;
	reset_to_normal_rect(rpg);
	info("Openning credits menu...");
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Credits");
}

void cb_goto_play_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	rpg->state = gameRun;
	rpg->last_st = gameUnknown;
	reset_to_normal_rect(rpg);
	info("Starting game");
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek");
}

void cb_goto_settings_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	rpg->last_st = rpg->state;
	rpg->state = gameOnSettings;
	info("Openning settings menu...");
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Options");
}

void cb_goto_settings_keymapping_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	rpg->img = sfRenderWindow_capture(rpg->win);
	if (rpg->img == NULL)
		return;
	rpg->last_st = rpg->state;
	rpg->state = gameOnKeymapping;
	info("Openning settings (keymapping) menu...");
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Controles");
}
