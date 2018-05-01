/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** volume_callback functions
*/

# include "cook.h"

void slider_volume_callback(cook_t *cook, slider_t *slider)
{
	sfVector2i tmp = sfMouse_getPositionRenderWindow(cook->win);
	float rec = slider->btn->rect.width / 2;
	sfVector2f p = { tmp.x - rec, slider->mid_axis };
	float volume = sfSound_getVolume(cook->sound);
	char *vol = NULL;

	volume = ((p.x - slider->range.x) * 100);
	volume /= (slider->range.y - slider->range.x);

	if (volume >= 0 && volume <= 100) {
		slider->btn->pos = p;
		vol = get_sound_in_str(volume);
		sfSprite_setPosition(slider->btn->sprite, slider->btn->pos);
		sfText_setString(slider->text, vol);
		if (!my_strequ(vol, "0%"))
			free(vol);
	}
}
