/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** btn_general functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

/*
** Détruire tout les composants de la structure btn_t (sprite, texture)
** @param (btn_t *btn) - Bouton à destroy
** @return (void)
*/
void lizz_btn_destroy(btn_t *btn)
{
	if (!btn)
		return;

	sfTexture_destroy(btn->texture);
	lizz_info("Texture of \"");
	lizz_print(1, btn->name);
	lizz_print(1, "\" button has been destroyed!\n");
	sfSprite_destroy(btn->sprite);
	lizz_info("Sprite of \"");
	lizz_print(1, btn->name);
	lizz_print(1, "\" button has been destroyed!\n");
}
