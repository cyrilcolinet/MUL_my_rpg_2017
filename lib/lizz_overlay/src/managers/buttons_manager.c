/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** buttons_manager functions
*/

# include "debug.h"
# include "lizz.h"

static btn_t *new_btn_node(void)
{
	btn_t *tmp = lizz->btn;

	while (tmp->next != NULL)
		tmp = tmp->next;

	free(tmp->next);
	tmp->next = malloc(sizeof(btn_t));

	if (tmp->next == NULL) {
		lizz_error("Unable to alloc button_t: Out of memory.\n");
		return (NULL);
	}

	return (tmp->next);
}

static btn_t *set_functions(btn_t *btn)
{
	btn->setTexture = &lizz_btn_set_texture;
	btn->setPosition = &lizz_btn_set_position;

	return (btn);
}

int lizz_btn_create(char *name, menu_e belongsTo)
{
	btn_t *btn = NULL;

	if (!name) {
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

	while (tmp->next != NULL) {
		if (strcmp(tmp->next->name, name) == 0) { // TODO: Forbidden function
			if (tmp->next->belongsTo == belongsTo) {
				return (tmp->next);
			}
		}
		tmp = tmp->next;
	}

	return (NULL);
}
