/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main_menu_buttons functions
*/

# include "rpg.h"

void main_menu_btn_play(rpg_t *rpg)
{
	btn_t *btn = NULL;
	sfIntRect rec = { 0, 0, 295, 250 };

	btn = lizz_get_btn(rpg->lizz, "btn_play", stMain);
	btn->create_asset(btn, rpg->lizz);
	btn->asset->setTexture(btn->asset, "assets/buttons/buttons.png", &rec);
	rec.height /= 3;
	btn->asset->setTextureRect(btn->asset, &rec);
	btn->asset->setPosition(btn->asset, 34, 34);
}
