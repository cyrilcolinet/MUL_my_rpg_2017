/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main_menu_config functions
*/

# include "rpg.h"

static void configure_buttons(rpg_t *rpg)
{
	btn_t *btn = NULL;

	btn = lizz_get_btn(rpg->lizz, "btn_play", stMain);
	btn->create_asset(btn, rpg->lizz);
	btn->asset->setTexture(btn->asset, "assets/buttons/buttons.png", NULL);
}

void main_menu_config(rpg_t *rpg)
{
	assets_t *tmp = NULL;

	lizz_assets_create(rpg->lizz, "main_bg", stMain);
	tmp = lizz_get_assets(rpg->lizz, "main_bg", stMain);
	tmp->setTexture(tmp, "assets/background.jpg", NULL);

	lizz_btn_create(rpg->lizz, "btn_play", stMain);
	lizz_btn_create(rpg->lizz, "btn_settings", stMain);
	lizz_btn_create(rpg->lizz, "btn_credits", stMain);
	lizz_btn_create(rpg->lizz, "btn_quit", stMain);
	lizz_thread_create(rpg->lizz, "th_bg", &bg_task, &rpg);
	configure_buttons(rpg);
}
