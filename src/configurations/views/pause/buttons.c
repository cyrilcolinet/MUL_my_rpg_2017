/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** buttons configuration for pause menu
*/

# include "rpg.h"

void configure_pause_resume_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 265, 480, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_resume";
	conf.pos.x = 500;
	conf.pos.y = 650;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_return_action;
	conf.state = gamePause;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured play button!");
}

void configure_pause_settings_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 530, 0, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_save";
	conf.pos.x = 1195;
	conf.pos.y = 650;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_settings_view;
	conf.state = gamePause;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured save button!");
}

void configure_pause_credits_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 480, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_credits";
	conf.pos.x = 645;
	conf.pos.y = 795;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_credits_view;
	conf.state = gamePause;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured credits button!");
}

void configure_pause_quit_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 720, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_quit";
	conf.pos.x = 1055;
	conf.pos.y = 795;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_quit_action;
	conf.state = gamePause;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured quit button!");
}
