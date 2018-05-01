/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** settings_buttons functions
*/

# include "cook.h"

void setup_return_credits_button(cook_t *cook)
{
	button_t conf;
	sfIntRect rec = { 295, 507, 290, 82 };
	sfTexture *texture = get_texture(cook, aBtnSp);

	conf.type = btnReturn;
	conf.pos.x = 47;
	conf.pos.y = 580;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = btn_return_released;
	conf.state = gameOnCredits;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(cook, conf);
	info("Configured return button for credits view!");
}
