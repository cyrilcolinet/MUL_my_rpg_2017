/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** play_sound or other callbacks
*/

# include "rpg.h"

void cb_play_sound1(rpg_t *rpg, button_t *btn)
{
	sound_t *sound = get_sound(rpg, "hover1");

	if (sound == NULL || btn->hovered)
		return;

	sfSound_setVolume(sound->sound, rpg->options.volume);
	sfSound_setLoop(sound->sound, sfFalse);
	sfSound_play(sound->sound);
	btn->hovered = true;
}
