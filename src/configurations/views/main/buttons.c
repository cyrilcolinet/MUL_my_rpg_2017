/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main_buttons configuration
*/

# include "rpg.h"

void configure_main_play_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 0, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_play";
	conf.pos.x = 365;
	conf.pos.y = 675;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_loader_view;
	conf.state = gameWait;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured resume button!");
}

void configure_main_settings_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 240, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_settings";
	conf.pos.x = 1285;
	conf.pos.y = 675;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_settings_view;
	conf.state = gameWait;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured settings button!");
}

void configure_main_credits_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 480, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_credits";
	conf.pos.x = 525;
	conf.pos.y = 840;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_credits_view;
	conf.state = gameWait;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured credits button!");
}

void configure_main_quit_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 720, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_quit";
	conf.pos.x = 1125;
	conf.pos.y = 840;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_quit_action;
	conf.state = gameWait;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured quit button!");
}
