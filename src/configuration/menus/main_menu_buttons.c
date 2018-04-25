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
	sfIntRect rec = { 0, 0, 255, 205 };

	btn = lizz_get_btn(rpg->lizz, "btn_play", stMain);
	btn->create_asset(btn, rpg->lizz);
	btn->asset->setTexture(btn->asset, "assets/buttons/buttons.png", &rec);
	rec.height /= 3;
	btn->asset->setTextureRect(btn->asset, &rec);
	btn->asset->setPosition(btn->asset, (1920 / 2) - (rec.width + 30), 34);
}

void main_menu_btn_settings(rpg_t *rpg)
{
	btn_t *btn = NULL;
	sfIntRect rec = { 205, 0, 255, 205 };

	btn = lizz_get_btn(rpg->lizz, "btn_settings", stMain);
	btn->create_asset(btn, rpg->lizz);
	btn->asset->setTexture(btn->asset, "assets/buttons/buttons.png", &rec);
	rec.height /= 3;
	btn->asset->setTextureRect(btn->asset, &rec);
	btn->asset->setPosition(btn->asset, (1920 / 2) + (rec.width + 30), 34);
}

void main_menu_btn_credits(rpg_t *rpg)
{
	btn_t *btn = NULL;
	sfIntRect rec = { 410, 0, 255, 205 };

	btn = lizz_get_btn(rpg->lizz, "btn_credits", stMain);
	btn->create_asset(btn, rpg->lizz);
	btn->asset->setTexture(btn->asset, "assets/buttons/buttons.png", &rec);
	rec.height /= 3;
	btn->asset->setTextureRect(btn->asset, &rec);
	btn->asset->setPosition(btn->asset, (1920 / 2) - (rec.width + 30), 100);
}

void main_menu_btn_quit(rpg_t *rpg)
{
	btn_t *btn = NULL;
	sfIntRect rec = { 615, 0, 255, 205 };

	btn = lizz_get_btn(rpg->lizz, "btn_quit", stMain);
	btn->create_asset(btn, rpg->lizz);
	btn->asset->setTexture(btn->asset, "assets/buttons/buttons.png", &rec);
	rec.height /= 3;
	btn->asset->setTextureRect(btn->asset, &rec);
	btn->asset->setPosition(btn->asset, (1920 / 2) + (rec.width + 30), 100);
}
