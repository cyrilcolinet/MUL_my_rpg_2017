/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** wait_buttons setup functions
*/

# include "cook.h"

void setup_wait_play_btn(cook_t *cook)
{
	button_t conf;
	sfIntRect rec = { 0, 0, 255, 68 };
	sfTexture *texture = get_texture(cook, aBtnSp);

	conf.type = btnPlay;
	conf.pos.x = 265;
	conf.pos.y = 375;
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

	add_button(cook, conf);
	info("Configured play button!");
}

void setup_wait_settings_btn(cook_t *cook)
{
	button_t conf;
	sfIntRect rec = { 0, 204, 255, 68 };
	sfTexture *texture = get_texture(cook, aBtnSp);

	conf.type = btnSettings;
	conf.pos.x = 625;
	conf.pos.y = 375;
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

	add_button(cook, conf);
	info("Configured options button!");
}

void setup_wait_credits_btn(cook_t *cook)
{
	button_t conf;
	sfIntRect rec = { 0, 408, 255, 68 };
	sfTexture *texture = get_texture(cook, aBtnSp);

	conf.type = btnCredits;
	conf.pos.x = 265;
	conf.pos.y = 500;
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

	add_button(cook, conf);
	info("Configured credits button!");
}

void setup_wait_quit_btn(cook_t *cook)
{
	button_t conf;
	sfIntRect rec = { 0, 612, 255, 68 };
	sfTexture *texture = get_texture(cook, aBtnSp);

	conf.type = btnQuit;
	conf.pos.x = 625;
	conf.pos.y = 500;
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

	add_button(cook, conf);
	info("Configured quit button!");
}
