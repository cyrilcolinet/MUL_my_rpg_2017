/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parser functions
*/

# include "rpg.h"

config_t *parse_file(char *file)
{
	config_t cfg;
	config_t *cf = NULL;
	char *path = my_strjoin("config/", file);

	config_init(&cfg);
	if (!path || !config_read_file(&cfg, path)) {
		write(2, "Unable to parse configuration.\n", 31);
		config_destroy(&cfg);
		return (NULL);
	}

	cf = &cfg;
	return (cf);
}

cf_assets_t **get_assets_creation(config_t *cf, config_setting_t *setting)
{
	int count = config_setting_length(setting);
	config_setting_t *asset = NULL;
	cf_assets_t **loader = malloc(sizeof(*loader) * (count + 1));
	const char *name = NULL;
	const char *path = NULL;

	if (loader == NULL)
		return (NULL);

	for (int i = 0; i < count; i++) {
		asset = config_setting_get_elem(setting, i);
		loader[i] = malloc(sizeof(cf_assets_t));
		config_setting_lookup_string(asset, "name", &name);
		loader[i]->name = ((char *)name);
		config_setting_lookup_string(asset, "file", &path);
		loader[i]->path = ((char *)path);
	}
	config_destroy(cf);
	return (loader);
}

cf_assets_t **parse_assets(void)
{
	config_t *cf = parse_file("assets.cfg");
	config_setting_t *setting = NULL;
	cf_assets_t **loader = NULL;

	if (cf == NULL)
		return (NULL);

	setting = config_lookup(cf, "textures");
	if (setting == NULL) {
		config_destroy(cf);
		return (NULL);
	}

	loader = get_assets_creation(cf, setting);
	if (loader == NULL) {
		config_destroy(cf);
		return (NULL);
	}

	return (loader);
}
