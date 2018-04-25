/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main_menu_config functions
*/

# include "rpg.h"

void configure_buttons(rpg_t *rpg)
{
	main_menu_btn_play(rpg);
	main_menu_btn_settings(rpg);
	main_menu_btn_credits(rpg);
	main_menu_btn_quit(rpg);
}

void configure_default_assets(rpg_t *rpg)
{
	assets_t *tmp = NULL;

	lizz_assets_create(rpg->lizz, "main_bg", stMain);
	tmp = lizz_get_assets(rpg->lizz, "main_bg", stMain);
	tmp->setTexture(tmp, "assets/background.jpg", NULL);

	lizz_assets_create(rpg->lizz, "main_logo", stMain);
	tmp = lizz_get_assets(rpg->lizz, "main_logo", stMain);
	tmp->setTexture(tmp, "assets/logo.png", NULL);
	tmp->setPosition(tmp, (1920 / 2) - (500 / 2), 100);
}

void main_menu_config(rpg_t *rpg)
{
	lizz_btn_create(rpg->lizz, "btn_play", stMain);
	lizz_btn_create(rpg->lizz, "btn_settings", stMain);
	lizz_btn_create(rpg->lizz, "btn_credits", stMain);
	lizz_btn_create(rpg->lizz, "btn_quit", stMain);
	lizz_thread_create(rpg->lizz, "th_bg", &bg_task, &rpg);

	configure_default_assets(rpg);
	configure_buttons(rpg);
}
