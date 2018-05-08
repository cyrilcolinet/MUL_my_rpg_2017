/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** history buttons functions
*/

# include "rpg.h"

void configure_history_return_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 265, 0, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_return";
	conf.pos.x = 80;
	conf.pos.y = 905;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_main_view;
	conf.state = gameHistory;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;
	add_button(rpg, conf);
	info("Configured return button for history view!");
}
