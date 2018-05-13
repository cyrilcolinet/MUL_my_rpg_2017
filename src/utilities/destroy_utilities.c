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

	info("All buttons destroyed.");
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
		free(tmp);
	}

	info("All assets destroyed.");
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

	info("All sliders destroyed.");
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
		free(tmp);
	}

	info("All sounds destroyed.");
}

void destroy_content(rpg_t *rpg)
{
	for (int i = 0; rpg->map[i]; i++) {
		sfSprite_destroy(rpg->map[i]->sprite);
		for (int j = 0; rpg->map[i]->h_layer[j]; j++)
			free(rpg->map[i]->h_layer[j]);
		free(rpg->map[i]->h_layer);
		free(rpg->map[i]->it);
		free(rpg->map[i]);
	}
	free(rpg->map);
}
