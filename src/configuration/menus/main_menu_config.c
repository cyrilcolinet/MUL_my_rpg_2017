/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main_menu_config functions
*/

# include "rpg.h"

void main_menu_config(rpg_t *rpg)
{
	lizz_btn_create(rpg->lizz, "btn_play", stMain);
	lizz_btn_create(rpg->lizz, "btn_settings", stMain);
	lizz_btn_create(rpg->lizz, "btn_credits", stMain);
	lizz_btn_create(rpg->lizz, "btn_quit", stMain);
	lizz_thread_create(rpg->lizz, "th_bg", &bg_task, &rpg);
}
