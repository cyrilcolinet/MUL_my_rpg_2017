/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** btn_general functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

void lizz_btn_destroy(btn_t *btn)
{
	sfTexture_destroy(btn->texture);
	lizz_info("Texture of \"");
	lizz_print(1, btn->name);
	lizz_print(1, "\" button has been destroyed!\n");
	sfSprite_destroy(btn->sprite);
	lizz_info("Sprite of \"");
	lizz_print(1, btn->name);
	lizz_print(1, "\" button has been destroyed!\n");
	if (btn->name)
		free(btn->name);
}
