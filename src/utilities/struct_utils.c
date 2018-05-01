/*
** EPITECH PROJECT, 2018
** cook
** File description:
** struct_utils functions
*/

# include "cook.h"

void destroy_buttons(cook_t *cook)
{
	button_t **cpy = NULL;
	button_t *tmp = cook->btn;

	while (tmp->next != NULL) {
		sfSprite_destroy(tmp->next->sprite);
		cpy = &tmp;
		tmp = tmp->next;
		free(*cpy);
	}

	free(cook->btn);
	cook->btn = NULL;
	info("All buttons destroyed!");
}

void destroy_assets(cook_t *cook)
{
	assets_t **cpy = NULL;
	assets_t *tmp = cook->assets;

	while (tmp->next != NULL) {
		sfSprite_destroy(tmp->next->sp);
		sfTexture_destroy(tmp->next->texture);
		cpy = &tmp;
		tmp = tmp->next;
		free(*cpy);
	}

	free(cook->assets);
	cook->assets = NULL;
	info("All assets destroyed!");
}

void destroy_slides(cook_t *cook)
{
	slider_t **cpy = NULL;
	slider_t *tmp = cook->slides;

	while (tmp->next != NULL) {
		sfText_destroy(tmp->next->text);
		cpy = &tmp;
		tmp = tmp->next;
		free(*cpy);
	}

	free(cook->slides);
	cook->slides = NULL;
	info("All sliders destroyed!");
}

cook_t *configure_struct(void)
{
	cook_t *cook = malloc(sizeof(cook_t));
	sfVideoMode mode = { 1200, 700, 32 };
	char *title = "My Cook | Menu Principal";

	if (cook == NULL)
		return (NULL);
	cook->state = gameWait;
	cook->last_st = gameUnknown;
	cook->win = sfRenderWindow_create(mode, title, sfClose, NULL);
	cook->assets = malloc(sizeof(assets_t));
	cook->btn = malloc(sizeof(button_t));
	cook->slides = malloc(sizeof(slider_t));
	if (!cook->assets || !cook->btn || !cook->win || !cook->slides)
		return (NULL);
	sfRenderWindow_setFramerateLimit(cook->win, 60);
	set_favicon(cook);
	cook->assets->next = NULL;
	cook->btn->next = NULL;
	cook->slides->next = NULL;
	return (cook);
}
