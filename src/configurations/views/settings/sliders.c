/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** slider_s settings configuration
*/

# include "rpg.h"

static slider_t extra_config(rpg_t *rpg, slider_t conf)
{
	slider_t c = conf;
	sfVector2f ori = { conf.range.y + 43, conf.mid_axis - 25 };

	sfSprite_setPosition(c.btn->sprite, c.btn->pos);
	sfText_setPosition(c.text, ori);
	sfText_setFont(c.text, rpg->font);
	sfText_setCharacterSize(c.text, 40);
	sfText_setString(c.text, "0%");

	return (c);
}

void configure_settings_volume_slider(rpg_t *rpg)
{
	slider_t conf;
	sfVector2f pos = { 100, 100 };

	conf.name = "sld_volume_music";
	conf.mid_axis = pos.y = 732;
	conf.range.x = pos.x = 155;
	conf.range.y = 460;
	conf.state = gameOnSettings;
	conf.onSlide = cb_slider_volume_music;
	conf.btn = get_button(rpg, "btn_volume", gameOnSettings);
	conf.text = sfText_create();
	conf.btn->pos = pos;

	add_slider(rpg, extra_config(rpg, conf));
}
