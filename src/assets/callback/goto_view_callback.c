/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** goto_view_callback functions
*/

# include "rpg.h"

// TODO: Make redirect_to view callback (continue)

void cb_goto_main_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	if (rpg->state == gamePause) {
		free_battle(rpg);
		sfSprite_destroy(rpg->player);
		configure_internal_struct(rpg);
		configure_battle_characters(rpg);
		init_icone_spell(rpg->battle);
		parse_player(rpg);
	}

	rpg->state = gameWait;
	rpg->last_st = gameUnknown;
	reset_to_normal_rect(rpg);
}

void cb_goto_credits_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	rpg->last_st = rpg->state;
	rpg->state = gameOnCredits;
	reset_to_normal_rect(rpg);
}

void cb_goto_play_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	if (my_strlen(rpg->player_name) <= 1 || rpg->sex == 0) {
		cb_void_action(rpg, btn);
		return;
	}
	rpg->state = gameRun;
	rpg->last_st = gameUnknown;
}

void cb_goto_settings_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	rpg->last_st = rpg->state;
	rpg->state = gameOnSettings;
}

void cb_goto_history_view(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	reset_to_normal_rect(rpg);
	rpg->last_st = rpg->state;
	rpg->state = gameHistory;
}

void *cb_redirect_to(rpg_t *rpg, state_e view)
{
	rpg->last_st = rpg->state;
	rpg->state = view;

	return (NULL);
}
