/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** settings_buttons functions
*/

# include "rpg.h"

void setup_return_credits_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 295, 507, 290, 82 };
	sfTexture *texture = get_texture(rpg, aBtnSp);

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

	add_button(rpg, conf);
	info("Configured return button for credits view!");
}
