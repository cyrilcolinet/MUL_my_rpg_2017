/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** btn_textures functions
*/

# include "lizz.h"

void lizz_btn_set_texture(btn_t *btn, char *path, sfIntRect *rect)
{
	if (!btn)
		return;

	btn->texture = sfTexture_createFromFile(path, rect);
	if (!btn->texture)
		return;

	btn->sprite = sfSprite_create();
	sfSprite_setTexture(btn->sprite, btn->texture, sfFalse);
}
