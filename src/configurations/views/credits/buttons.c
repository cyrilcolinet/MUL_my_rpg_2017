/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** credits_buttons configuration
*/

# include "rpg.h"

void configure_credits_return_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 295, 507, 290, 82 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_return";
	conf.pos.x = 47;
	conf.pos.y = 580;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_return_action;
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
