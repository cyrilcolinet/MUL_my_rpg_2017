/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** wait_buttons setup functions
*/

# include "rpg.h"

void setup_wait_play_btn(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 0, 265, 80 };
	sfTexture *texture = get_texture(rpg, aBtnSp);

	conf.type = btnPlay;
	conf.pos.x = 547;
	conf.pos.y = 717;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = btn_play_released;
	conf.state = gameWait;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured play button!");
}

void setup_wait_settings_btn(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 240, 265, 80 };
	sfTexture *texture = get_texture(rpg, aBtnSp);

	conf.type = btnSettings;
	conf.pos.x = 1179;
	conf.pos.y = 717;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = btn_settings_released;
	conf.state = gameWait;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured options button!");
}

void setup_wait_credits_btn(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 480, 265, 80 };
	sfTexture *texture = get_texture(rpg, aBtnSp);

	conf.type = btnCredits;
	conf.pos.x = 642;
	conf.pos.y = 873;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = btn_credits_released;
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

void setup_wait_quit_btn(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 720, 265, 80 };
	sfTexture *texture = get_texture(rpg, aBtnSp);

	conf.type = btnQuit;
	conf.pos.x = 1069;
	conf.pos.y = 873;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = btn_quit_released;
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
