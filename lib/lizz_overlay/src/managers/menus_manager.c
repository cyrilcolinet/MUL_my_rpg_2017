/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** menus_manager functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static menu_t *new_node_menu()
{
	menu_t **tmp = &lizz->menus;

	while (*tmp != NULL)
		*tmp = (*tmp)->next;

	*tmp = malloc(sizeof(btn_t));

	if (*tmp == NULL) {
		lizz_error("Unable to alloc menu_t: Out of memory.\n");
		return (NULL);
	}

	return (*tmp);
}

int lizz_menu_create(char *name, menu_e menu)
{
	menu_t *men = NULL;

	if (!name || lizz_strlen(name) == 0) {
		lizz_error("name must be not empty.\n");
		return (-1);
	}

	men = new_node_menu();
	if (!men)
		return (-1);

	men->name = name;
	men->menu = menu;
	men->btn = NULL;
	men->next = NULL;

	return (0);
}
