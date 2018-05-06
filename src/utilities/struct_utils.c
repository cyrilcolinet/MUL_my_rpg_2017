/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** struct_utils functions
*/

# include "rpg.h"

void destroy_buttons(rpg_t *rpg)
{
	button_t **cpy = NULL;
	button_t *tmp = rpg->btn;

	while (tmp != NULL) {
		sfSprite_destroy(tmp->sprite);
		cpy = &tmp;
		tmp = tmp->next;
		free(*cpy);
	}

	free(rpg->btn);
	rpg->btn = NULL;
	info("All buttons destroyed!");
}

void destroy_assets(rpg_t *rpg)
{
	assets_t **cpy = NULL;
	assets_t *tmp = rpg->assets;

	while (tmp != NULL) {
		sfSprite_destroy(tmp->sp);
		sfTexture_destroy(tmp->texture);
		cpy = &tmp;
		tmp = tmp->next;
		free(*cpy);
	}

	free(rpg->assets);
	rpg->assets = NULL;
	info("All assets destroyed!");
}

void destroy_slides(rpg_t *rpg)
{
	slider_t **cpy = NULL;
	slider_t *tmp = rpg->slides;

	while (tmp != NULL) {
		sfText_destroy(tmp->text);
		cpy = &tmp;
		tmp = tmp->next;
		free(*cpy);
	}

	free(rpg->slides);
	rpg->slides = NULL;
	info("All sliders destroyed!");
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
	rpg->img = NULL;
	rpg->clock = sfClock_create();
	return (rpg);
}
