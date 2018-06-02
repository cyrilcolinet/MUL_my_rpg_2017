/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** slider_s settings configuration
*/

# include "rpg.h"

static void extra_config(rpg_t *rpg, slider_t *conf)
{
	sfVector2f ori = { conf->range.y + 43, conf->mid_axis - 25 };
	char *vol = get_sound_in_str(rpg->options.music_vol);

	sfSprite_setPosition(conf->btn->sprite, conf->btn->pos);
	conf->text = sfText_create();
	sfText_setPosition(conf->text, ori);
	sfText_setCharacterSize(conf->text, 40);
	sfText_setString(conf->text, vol);
	free(vol);
}

void configure_settings_volume_slider(rpg_t *rpg)
{
	slider_t conf;
	sfVector2f pos = { 100, 100 };

	conf.name = "sld_volume_music";
	conf.mid_axis = pos.y = 670;
	conf.range.x = pos.x = 230;
	conf.range.y = 694;
	conf.state = gameOnSettings;
	conf.onSlide = cb_slider_volume_music;
	conf.btn = get_button(rpg, "btn_volume", conf.state);
	conf.btn->pos = pos;
	extra_config(rpg, &conf);
	add_slider(rpg, conf);
}
