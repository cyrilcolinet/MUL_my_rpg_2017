/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** struct_utils functions
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

rpg_t *configure_struct(void)
{
	rpg_t *rpg = malloc(sizeof(rpg_t));
	sfVideoMode mode = { 1920, 1080, 32 };
	char *title = "Legacy Of The Kek | Menu Principal";

	if (rpg == NULL)
		return (NULL);
	rpg->state = gameWait;
	rpg->last_st = gameUnknown;
	rpg->win = sfRenderWindow_create(mode, title, sfClose, NULL);
	if (rpg->win == NULL)
		return (NULL);
	sfRenderWindow_setFramerateLimit(rpg->win, 60);
	rpg->assets = NULL;
	rpg->btn = NULL;
	rpg->slides = NULL;
	rpg->sounds = NULL;
	rpg->capture = NULL;
	rpg->clock = sfClock_create();
	rpg->options.music_vol = rpg->options.sound_vol = 67;
	return (rpg);
}
