/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** settings_button configuration
*/

# include "rpg.h"

void configure_settings_volume_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 660, 240, 130, 80 };
	sfVector2f origin = { (rec.width / 2), (rec.height / 2) };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_volume";
	conf.pos.x = 0;
	conf.pos.y = 0;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_void_action;
	conf.state = gameOnSettings;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setOrigin(conf.sprite, origin);
	conf.rect = rec;
	conf.next = NULL;
	add_button(rpg, conf);
	info("Configured volume button for settings view!");
}

void configure_settings_return_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 265, 0, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_return";
	conf.pos.x = 580;
	conf.pos.y = 845;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_return_action;
	conf.state = gameOnSettings;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;
	add_button(rpg, conf);
	info("Configured return button for setting view!");
}

void configure_settings_fullscreen_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 265, 240, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_fullscreen";
	conf.pos.x = 120;
	conf.pos.y = 845;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_void_action; // TODO: Start fullscreen
	conf.state = gameOnSettings;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured fullscreen button for setting view!");
}
