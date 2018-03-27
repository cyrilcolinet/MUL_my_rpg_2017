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
	btn->rect = rect;
	if (!btn->texture)
		return;

	btn->sprite = sfSprite_create();
	sfSprite_setTexture(btn->sprite, btn->texture, sfFalse);
	print_debug(btn->name, file);
}


void lizz_btn_set_texture_rect(btn_t *btn)
{
	
}
