/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** btn_textures functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static void print_debug(char *btn, char *file)
{
	lizz_info("Texture of \"");
	lizz_print(1, btn);
	lizz_print(1, "\" button changed to \"");
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
** @param (btn_t *btn) - Bouton ou la texture doit être appliquée
** @param (char *file) - Fichier de texture (ne doit pas contenir le
** chemin en entier, juste le fichier)
** @param (sfIntRect *rect) - Rectangle area
** @return (void)
*/
void lizz_btn_set_texture(btn_t *btn, char *file, sfIntRect *rect)
{
	if (!btn) {
		lizz_error("Button can't be NULL.\n");
		return;
	}

	btn->texture = sfTexture_createFromFile(file, rect);
	if (!btn->texture)
		return;

	btn->rect = rect;
	btn->def_rect = set_default_rect(rect, btn->texture);
	btn->sprite = sfSprite_create();
	sfSprite_setTexture(btn->sprite, btn->texture, sfFalse);
	print_debug(btn->name, file);
}
