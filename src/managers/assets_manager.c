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

// TODO: Temporary creation of assets
c_assets_t **configure_assets(rpg_t *rpg)
{
	create_texture(rpg, "bg_main", "assets/main_menu.png");
	create_texture(rpg, "buttons", "assets/buttons.png");
	create_texture(rpg, "bg_pause", "assets/pause_menu.png");
	create_texture(rpg, "bg_settings", "assets/options_menu.png");
	create_texture(rpg, "bg_credits", "assets/credits_menu.png");
	create_texture(rpg, "map1", "assets/map/1.png");
	create_texture(rpg, "booksheet", "assets/booksheet.png");
	return (NULL);
}

int load_assets(rpg_t *rpg)
{
	c_assets_t **assets = configure_assets(rpg);
	char *name = NULL;
	char *filename = NULL;

	for (int i = 0; assets && assets[i] != NULL; i++) {
		if (!assets[i]->name && !assets[i]->filename)
			return (-1);

		name = assets[i]->name;
		filename = assets[i]->filename;
		create_texture(rpg, name, filename);
	}

	configure_audio(rpg);
	start_loader(rpg);
	print_assets(rpg);
	print_buttons(rpg);
	print_sliders(rpg);

	return (0);
}
