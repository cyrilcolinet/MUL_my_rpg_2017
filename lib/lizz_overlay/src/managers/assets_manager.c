/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** assets_manager functions
*/

# include "debug.h"
# include "utils.h"
# include "lizz.h"

static assets_t *set_functions(assets_t *assets)
{
	assets->setTexture = &lizz_assets_set_texture;
	assets->setPosition = &lizz_assets_set_position;
	assets->setRotation = &lizz_assets_set_rotation;
	assets->setTextureRect = &lizz_assets_set_texture_rect;
	assets->destroy = &lizz_assets_destroy;

	lizz_info("Asset \"");
	lizz_print(1, assets->name);
	lizz_print(1, "\" created.\n");

	return (assets);
}

static void fill_node_values(assets_t *node, assets_t values)
{
	node->name = values.name;
	node->belongsTo = values.belongsTo;
	node->texture = NULL;
	node->sprite = NULL;
	node->pos.x = 0;
	node->pos.y = 0;
	node = set_functions(node);
	node->next = NULL;
}

static bool new_assets_node(lizz_t *st, assets_t values)
{
	assets_t **assetss = &st->assets;
	assets_t *node = NULL;

	if (st->assets == NULL) {
		node = malloc(sizeof(assets_t));
		fill_node_values(node, values);
		node->next = *assetss;
		*assetss = node;
		return (true);
	}

	node = st->assets;
	while (node->next != NULL)
		node = node->next;

	node->next = malloc(sizeof(assets_t));
	if (node->next == NULL)
		return (false);
	fill_node_values(node->next, values);
	return (true);
}

/*
** Récupérer un bouton grace à son nom et sa scene correspondante
** @param (char *name) - Nom/ID du bouton
** @return (assets_t) - Retourne NULL si aucun bouton n'est trouvé, et
** retourne le bouton si correspondant au nom et à la scene donnée
*/
assets_t *lizz_get_assets(lizz_t *st, char *name, menu_e belongsTo)
{
	assets_t *tmp = st->assets;

	while (tmp != NULL) {
		if (strcmp(tmp->name, name) == 0) { // TODO: Forbidden function
			if (tmp->belongsTo == belongsTo)
				return (tmp);
		}
		tmp = tmp->next;
	}

	lizz_error("Unable to found an asset named \"");
	lizz_print(2, name);
	lizz_print(2, "\"\n");
	return (NULL);
}

/*
** Creer un bouton
** @param (char *name) - Nom/ID du bouton
** @return (int) - Retourne -1 si il y a une erreur, et 0 autrement
*/
int lizz_assets_create(lizz_t *st, char *name, menu_e belongsTo)
{
	assets_t assets;

	if (!name || lizz_strlen(name) == 0) {
		lizz_error("name must be not empty.\n");
		return (-1);
	}

	assets.name = name;
	assets.belongsTo = belongsTo;
	if (!new_assets_node(st, assets))
		return (-1);

	return (0);
}
