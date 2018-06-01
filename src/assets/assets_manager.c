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

	texture.name = my_strdup(name);
	texture.file = my_strdup(file);
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
	conf_sett_t conf = parse_file(rpg, "assets.cfg", "textures");
	config_setting_t *asset = NULL;
	const char *name = NULL;
	const char *file = NULL;
	int count = 0;

	if (conf.error || conf.set == NULL)
		return (-1);
	count = config_setting_length(conf.set);
	for (int key = 0; count > 0 && key < count; key++) {
		asset = config_setting_get_elem(conf.set, key);
		if (asset != NULL) {
			config_setting_lookup_string(asset, "name", &name);
			config_setting_lookup_string(asset, "file", &file);
		}
		if (file != NULL && name != NULL)
			create_texture(rpg, ((char *)name), ((char *)file));
	}
	config_destroy(&conf.cfg);
	return (0);
}

int load_assets(rpg_t *rpg)
{
	if (configure_assets(rpg) != 0)
		return (84);

	start_loader(rpg);
	load_sounds(rpg);

	if (!configure_internal_struct(rpg) || parse_map(rpg) != 0)
		return (84);
	return (0);
}
