/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** assets manager
*/

# include "debug.h"
# include "rpg.h"

int new_asset(rpg_t *rpg, texture_t texture)
{
	assets_t *tmp = rpg->assets;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = malloc(sizeof(assets_t));

	if (tmp->next == NULL)
		return (84);

	tmp->next->texture = texture.texture;
	tmp->next->file = texture.file;
	tmp->next->sp = texture.sp;
	tmp->next->name = texture.name;
	tmp->next->next = NULL;

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

// TODO: Change assets_number (set in config)
c_assets_t **configure_assets(void)
{
	return (NULL);
}

int load_assets(rpg_t *rpg)
{
	c_assets_t **assets = configure_assets();
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
