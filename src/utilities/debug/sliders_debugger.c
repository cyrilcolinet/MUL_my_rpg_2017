/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sliders_debugger functions
*/

# include "rpg.h"
# include "debug.h"

void print_sliders_infos(slider_t *slide, char *st[])
{
	info("Print slider: ->");
	print_key_value_str("name", slide->name);
	print_key_value_int("midaxis", slide->mid_axis);
	print_key_value_int("range.x", slide->range.x);
	print_key_value_int("range.y", slide->range.y);
	print_key_value_str("state", st[slide->state]);
	my_putstr("\tPrint button: ->\n");
	my_putstr("\t");
	print_key_value_int("pos.x", slide->btn->pos.x);
	my_putstr("\t");
	print_key_value_int("pos.y", slide->btn->pos.y);
}

void print_sliders(rpg_t *rpg)
{
	slider_t *tmp = rpg->slides;
	char *st[] = {
		"gameUnknown", "gameWait", "gameRun", "gameEnd", "gamePause",
		"gameOnSettings", "gameOnCredits", "gameHistory",
		"gameBattle", "gameSelect"
	};

	info("\n");
	info("----------------");
	while (debug && tmp != NULL) {
		print_sliders_infos(tmp, st);
		tmp = tmp->next;
	}
}
