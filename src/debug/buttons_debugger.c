/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** buttons_debugger functions
*/

# include "cook.h"
# include "debug.h"

void print_buttons_infos(button_t *btn, char *bt[], char *st[])
{
	info("Print button: ->");
	print_key_value_str("type", bt[btn->type]);
	print_key_value_int("pos.x", btn->pos.x);
	print_key_value_int("pos.y", btn->pos.y);
	print_key_value_str("state", st[btn->state]);
}

void print_buttons(cook_t *cook)
{
	button_t *tmp = cook->btn;
	char *bt[] = {
		"btnPlay", "btnPause", "btnCredits", "btnQuit", "btnSettings",
		"btnReturn", "btnMute", "btnVolume", "btnFullscreen", "btnNull"
	};
	char *st[] = {
		"gameUnknown", "gameWait", "gameRun", "gameEnd", "gamePause",
		"gameOnSettings", "gameOnCredits"
	};

	info("\n");
	info("----------------");
	while (debug && tmp->next != NULL) {
		print_buttons_infos(tmp->next, bt, st);
		tmp = tmp->next;
	}
}
