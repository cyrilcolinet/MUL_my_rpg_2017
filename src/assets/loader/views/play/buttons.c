/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** play_buttons functions configuration
*/

# include "rpg.h"

void configure_play_pause_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 530, 480, 130, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_pause";
	conf.pos.x = 1785;
	conf.pos.y = 25;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_pause_view;
	conf.state = gameRun;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;
	add_button(rpg, conf);
}
