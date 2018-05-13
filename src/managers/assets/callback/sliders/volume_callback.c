/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** volume_callback functions
*/

# include "rpg.h"

void cb_slider_volume_music(rpg_t *rpg, slider_t *slider)
{
	sfVector2i tmp = sfMouse_getPositionRenderWindow(rpg->win);
	float rec = slider->btn->rect.width / 2;
	sfVector2f p = { tmp.x - rec, slider->mid_axis };
	char *vol = NULL;

	rpg->options.music_vol = ((p.x - slider->range.x) * 100);
	rpg->options.music_vol /= (slider->range.y - slider->range.x);

	if (rpg->options.music_vol >= 0 && rpg->options.music_vol <= 100) {
		slider->btn->pos = p;
		vol = get_sound_in_str(rpg->options.music_vol);
		set_volume(rpg, rpg->options.music_vol, true);
		sfSprite_setPosition(slider->btn->sprite, slider->btn->pos);
		sfText_setString(slider->text, vol);
		printf("%s\n", vol);
		free(vol);
	}
}
