/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** assets manager
*/

# include "debug.h"
# include "rpg.h"

static void fill_values(assets_t *node, texture_t texture)
{
	node->name = texture.name;
	node->texture = texture.texture;
	node->file = texture.file;
	node->sp = texture.sp;
	node->next = NULL;
}

int new_asset(rpg_t *rpg, texture_t texture)
{
	assets_t **assets = &rpg->assets;
	assets_t *node = NULL;

	if (rpg->assets == NULL) {
		node = malloc(sizeof(assets_t));
		if (node == NULL)
			return (-1);
		fill_values(node, texture);
		node->next = *assets;
		*assets = node;
		return (0);
	}
	node = rpg->assets;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(assets_t));
	if (node->next == NULL)
		return (-1);
	fill_values(node->next, texture);
	return (0);
}

int create_texture(rpg_t *rpg, char *name, char *file)
{
	texture_t texture;
	int res = 84;

	texture.name = name;
	texture.file = file;
	texture.texture = sfTexture_createFromFile(texture.file, NULL);
	if (texture.texture == NULL)
		return (84);

	texture.sp = sfSprite_create();
	sfSprite_setTexture(texture.sp, texture.texture, sfFalse);

	res = new_asset(rpg, texture);
	return (res);
}

int configure_assets(rpg_t *rpg)
{
	cf_assets_t **ass = parse_assets();

	if (ass == NULL)
		return (-1);
	for (int i = 0; ass[i]; i++) {
		if (ass[i]->name && ass[i]->path) {
			info("Loading asset named ");
			if (debug) {
				my_putstr(ass[i]->name);
				my_putstr(" (");
				my_putstr(ass[i]->path);
				my_putstr(").\n");
			}
			create_texture(rpg, ass[i]->name, ass[i]->path);
		} else {
			warning("Unable to find a texture.\n");
		}
	}
	return (0);
}

int load_assets(rpg_t *rpg)
{
	if (configure_assets(rpg) != 0)
		return (84);

	start_loader(rpg);
	print_assets(rpg);
	print_buttons(rpg);
	print_sliders(rpg);
	load_sounds(rpg);

	return (0);
}
