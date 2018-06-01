/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** destroy_utilities functions
*/

# include "rpg.h"

void destroy_buttons(rpg_t *rpg)
{
	button_t *tmp = NULL;

	while (rpg->btn != NULL) {
		tmp = rpg->btn;
		rpg->btn = tmp->next;
		if (tmp->sprite != NULL)
			sfSprite_destroy(tmp->sprite);
		free(tmp);
	}
}

void destroy_assets(rpg_t *rpg)
{
	assets_t *tmp = NULL;

	while (rpg->assets != NULL) {
		tmp = rpg->assets;
		rpg->assets = tmp->next;
		if (tmp->sp != NULL)
			sfSprite_destroy(tmp->sp);
		if (tmp->texture != NULL)
			sfTexture_destroy(tmp->texture);
		free(tmp->name);
		free(tmp->file);
		free(tmp);
	}
}

void destroy_slides(rpg_t *rpg)
{
	slider_t *tmp = NULL;

	while (rpg->slides != NULL) {
		tmp = rpg->slides;
		rpg->slides = tmp->next;
		if (tmp->text != NULL)
			sfText_destroy(tmp->text);
		free(tmp);
	}
}

void destroy_sounds(rpg_t *rpg)
{
	sound_t *tmp = NULL;

	while (rpg->sounds != NULL) {
		tmp = rpg->sounds;
		rpg->sounds = tmp->next;
		if (tmp->sound != NULL)
			sfSound_destroy(tmp->sound);
		if (tmp->buffer)
			sfSoundBuffer_destroy(tmp->buffer);
		free(tmp->name);
		free(tmp->file);
		free(tmp);
	}
}
