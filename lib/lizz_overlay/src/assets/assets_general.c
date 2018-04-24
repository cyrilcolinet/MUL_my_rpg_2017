/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** assets_functions
*/

# include "debug.h"
# include "utils.h"
# include "lizz.h"

void lizz_assets_destroy(assets_t *asset)
{
	if (!asset)
		return;

	sfTexture_destroy(asset->texture);
	lizz_info("Texture of \"");
	lizz_print(1, asset->name);
	lizz_print(1, "\" asset has been destroyed!\n");
	sfSprite_destroy(asset->sprite);
	lizz_info("Sprite of \"");
	lizz_print(1, asset->name);
	lizz_print(1, "\" asset has been destroyed!\n");
}
