/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** history button configuration
*/

# include "rpg.h"

void configure_main_history_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 0, 0, 265, 80 };
	sfTexture *texture = get_texture(rpg, "btn_history");

	conf.name = "btn_history";
	conf.pos.x = 547;
	conf.pos.y = 717;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_goto_play_view;
	conf.state = gameWait;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured history button!");
}
