/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** buttons_debugger functions
*/

# include "rpg.h"
# include "debug.h"

void print_buttons_infos(button_t *btn, char *st[])
{
	info("Print button: ->");
	print_key_value_str("name", btn->name);
	print_key_value_int("pos.x", btn->pos.x);
	print_key_value_int("pos.y", btn->pos.y);
	print_key_value_str("state", st[btn->state]);
}

void print_buttons(rpg_t *rpg)
{
	button_t *tmp = rpg->btn;
	char *st[] = {
		"gameUnknown", "gameWait", "gameRun", "gameEnd", "gamePause",
		"gameOnSettings", "gameOnCredits", "gameHistory",
		"gameBattle", "gameSelect", "gameQuitWSave"
	};

	info("\n");
	info("----------------");
	while (debug && tmp != NULL) {
		print_buttons_infos(tmp, st);
		tmp = tmp->next;
	}
}
