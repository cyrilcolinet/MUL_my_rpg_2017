/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** assets_debugger functions
*/

# include "rpg.h"
# include "debug.h"

void print_assets_infos(assets_t *asset)
{
	sfTexture *texture = NULL;

	print_key_value_str("name", asset->id);
	print_key_value_str("file", asset->file);
	texture = asset->texture;
	print_key_value_str("texture", ((texture == NULL) ? "(null)" : "OK"));
}

void print_assets(rpg_t *rpg)
{
	assets_t *tmp = rpg->assets;

	info("\n");
	info("----------------");
	while (debug && tmp != NULL) {
		info("Print assets: ->");
		print_assets_infos(tmp);
		tmp = tmp->next;
	}
}
