/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** loader buttons configurations
*/

# include "rpg.h"

void configure_load_return_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 265, 0, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_return";
	conf.pos.x = 655;
	conf.pos.y = 910;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_main_view;
	conf.state = gameLoadSave;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;
	add_button(rpg, conf);
	info("Configured return button for load view!");
}

void configure_load_new_game_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 265, 720, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_new_game";
	conf.pos.x = 1010;
	conf.pos.y = 910;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_select_view;
	conf.state = gameLoadSave;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;
	add_button(rpg, conf);
	info("Configured new game button for load view!");
}
