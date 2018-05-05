/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** credits_btn_callback functions
*/

# include "rpg.h"

void btn_credits_released(rpg_t *rpg, button_t *btn)
{
	(void)btn;

	info("Openning credits menu...");
	rpg->last_st = rpg->state;
	rpg->state = gameOnCredits;
	reset_to_normal_rect(rpg);
}
