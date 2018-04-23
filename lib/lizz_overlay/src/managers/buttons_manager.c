/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** buttons_manager functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static btn_t *set_functions(btn_t *btn)
{
	btn->setTexture = &lizz_btn_set_texture;
	btn->setPosition = &lizz_btn_set_position;
	btn->setRotation = &lizz_btn_set_rotation;
	btn->setTextureRect = &lizz_btn_set_texture_rect;
	btn->destroy = &lizz_btn_destroy;

	lizz_info("Button \"");
	lizz_print(1, btn->name);
	lizz_print(1, "\" created.\n");

	return (btn);
}

static void fill_node_values(btn_t *node, btn_t values)
{
	node->name = values.name;
	node->belongsTo = values.belongsTo;
	node->texture = NULL;
	node->sprite = NULL;
	node = set_functions(node);
	node->next = NULL;
}

static bool new_btn_node(lizz_t *st, btn_t values)
{
	btn_t **btns = &st->btn;
	btn_t *node = NULL;

	if (st->btn == NULL) {
		node = malloc(sizeof(btn_t));
		fill_node_values(node, values);
		node->next = *btns;
		*btns = node;
		return (true);
	}

	node = st->btn;
	while (node->next != NULL)
		node = node->next;

	node->next = malloc(sizeof(btn_t));
	if (node->next == NULL)
		return (false);
	fill_node_values(node->next, values);
	return (true);
}

/*
** Creer un bouton
** @param (char *name) - Nom/ID du bouton
** @param (menu_e belongsTo) - Scene a laquelle le bouton appartient
** @return (int) - Retourne -1 si il y a une erreur, et 0 autrement
*/
int lizz_btn_create(lizz_t *st, char *name, menu_e belongsTo)
{
	btn_t btn;

	if (!name || lizz_strlen(name) == 0) {
		lizz_error("name must be not empty.\n");
		return (-1);
	}

	btn.name = name;
	btn.belongsTo = belongsTo;
	if (!new_btn_node(st, btn))
		return (-1);

	return (0);
}

/*
** Récupérer un bouton grace à son nom et sa scene correspondante
** @param (char *name) - Nom/ID du bouton
** @param (menu_e belonsTo) - Scene à laquelle le bouton appartient
** @return (btn_t) - Retourne NULL si aucun bouton n'est trouvé, et
** retourne le bouton si correspondant au nom et à la scene donnée
*/
btn_t *lizz_get_btn(lizz_t *st, char *name, menu_e belongsTo)
{
	btn_t *tmp = st->btn;

	while (tmp != NULL) {
		if (strcmp(tmp->name, name) == 0) { // TODO: Forbidden function
			if (tmp->belongsTo == belongsTo) {
				return (tmp);
			}
		}
		tmp = tmp->next;
	}

	lizz_error("Unable to found a button named \"");
	lizz_print(2, name);
	lizz_print(2, "\"\n");
	return (NULL);
}
