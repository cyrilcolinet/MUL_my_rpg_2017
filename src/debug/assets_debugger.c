/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** assets_debugger functions
*/

# include "cook.h"
# include "debug.h"

void print_assets_infos(assets_t *asset, char *id[])
{
	sfTexture *texture = NULL;

	print_key_value_str("id", id[asset->id]);
	print_key_value_str("file", asset->file);
	texture = asset->texture;
	print_key_value_str("texture", ((texture == NULL) ? "(null)" : "OK"));
}

void print_assets(cook_t *cook)
{
	char *id[] = {
		"aWaitBg", "aBtnSp", "aPauseBg", "aOptionsBg", "aCreditsBg",
		"aHoomansSp", "aMap1"
	};
	assets_t *tmp = cook->assets;

	info("\n");
	info("----------------");
	while (debug && tmp->next != NULL) {
		info("Print assets: ->");
		print_assets_infos(tmp->next, id);
		tmp = tmp->next;
	}
}
