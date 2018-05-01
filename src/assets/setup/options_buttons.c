/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** Options button configuration
*/

# include "cook.h"

void setup_volume_settings_button(cook_t *cook)
{
	button_t conf;
	sfIntRect rec = { 590, 507, 80, 82 };
	sfVector2f origin = { (rec.width / 2), (rec.height / 2) };
	sfTexture *texture = get_texture(cook, aBtnSp);

	conf.type = btnVolume;
	conf.pos.x = 0;
	conf.pos.y = 0;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = nothing_callback;
	conf.state = gameOnSettings;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setOrigin(conf.sprite, origin);
	conf.rect = rec;
	conf.next = NULL;
	add_button(cook, conf);
	info("Configured volume button for settings view!");
}

void setup_return_settings_button(cook_t *cook)
{
	button_t conf;
	sfIntRect rec = { 295, 507, 290, 82 };
	sfTexture *texture = get_texture(cook, aBtnSp);

	conf.type = btnReturn;
	conf.pos.x = 160;
	conf.pos.y = 580;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = btn_return_released;
	conf.state = gameOnSettings;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;
	add_button(cook, conf);
	info("Configured return button for setting view!");
}
