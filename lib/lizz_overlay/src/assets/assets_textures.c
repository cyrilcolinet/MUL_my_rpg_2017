/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** assets_textures functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static void print_debug(char *assets, char *file)
{
	lizz_info("Texture of \"");
	lizz_print(1, assets);
	lizz_print(1, "\" asset changed to \"");
	lizz_print(1, file);
	lizz_print(1, "\"\n");
}

static sfIntRect set_default_rect(sfIntRect *rect, sfTexture *texture)
{
	sfVector2u size;
	sfIntRect ret;

	if (rect != NULL)
		return (*rect);

	size = sfTexture_getSize(texture);
	ret.top = 0;
	ret.left = 0;
	ret.height = ((int)size.y);
	ret.width = ((int)size.x);

	return (ret);
}

/*
** Appliquer une texture au bouton avec son rectangle
** @param (assets_t *assets) - Bouton ou la texture doit être appliquée
** @param (char *file) - Fichier de texture (ne doit pas contenir le
** chemin en entier, juste le fichier)
** @param (sfIntRect *rect) - Rectangle area
** @return (void)
*/
void lizz_assets_set_texture(assets_t *assets, char *file, sfIntRect *rect)
{
	if (!assets) {
		lizz_error("Asset can't be NULL.\n");
		return;
	}

	assets->texture = sfTexture_createFromFile(file, rect);
	if (!assets->texture)
		return;

	assets->rect = rect;
	assets->def_rect = set_default_rect(rect, assets->texture);
	assets->sprite = sfSprite_create();
	sfSprite_setTexture(assets->sprite, assets->texture, sfFalse);
	print_debug(assets->name, file);
}
