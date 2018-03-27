/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** buttons_manager functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static btn_t *new_btn_node(void)
{
	btn_t **tmp = &lizz->btn;

	while (*tmp != NULL)
		printf("%s\n", "salut"), *tmp = (*tmp)->next;

	*tmp = malloc(sizeof(btn_t));

	if (*tmp == NULL) {
		lizz_error("Unable to alloc button_t: Out of memory.\n");
		return (NULL);
	}

	return (*tmp);
}

static btn_t *set_functions(btn_t *btn)
{
	btn->setTexture = &lizz_btn_set_texture;
	btn->setPosition = &lizz_btn_set_position;
	btn->setTextureRect = &lizz_btn_set_texture_rect;
	btn->destroy = &lizz_btn_destroy;

	return (btn);
}

int lizz_btn_create(char *name, menu_e belongsTo)
{
	btn_t *btn = NULL;

	if (!name || lizz_strlen(name) == 0) {
		lizz_error("name must be not empty.\n");
		return (-1);
	}
	btn = new_btn_node();
	if (!btn)
		return (-1);

	btn->name = name;
	btn->belongsTo = belongsTo;
	btn->texture = NULL;
	btn->sprite = NULL;
	btn = set_functions(btn);
	btn->next = NULL;

	return (0);
}

btn_t *lizz_get_btn(char *name, menu_e belongsTo)
{
	btn_t *tmp = lizz->btn;

	while (tmp != NULL) {
		if (strcmp(tmp->name, name) == 0) { // TODO: Forbidden function
			if (tmp->belongsTo == belongsTo) {
				return (tmp);
			}
		}
		tmp = tmp->next;
	}

	return (NULL);
}
