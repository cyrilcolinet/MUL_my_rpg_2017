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
	sfIntRect rec = { 0, 0, 195, 183 };

	conf.name = "btn_history";
	conf.pos.x = 875;
	conf.pos.y = 720;
	conf.onClick = cb_void_action;
	conf.onHover = cb_void_action;
	conf.onStart = cb_void_action;
	conf.state = gameWait;
	conf.sprite = NULL;
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured history button!");
}
