/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** destroy_manager functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static void destroy_all_btn(void)
{
	btn_t *tmp = NULL;

	while (lizz->btn != NULL) {
		tmp = lizz->btn;
		lizz->btn = lizz->btn->next;
		//tmp->destroy(tmp);
		sfTexture_destroy(tmp->texture);
		lizz_info("Texture of \"");
		lizz_print(1, tmp->name);
		lizz_print(1, "\" button has been destroyed!\n");
		sfSprite_destroy(tmp->sprite);
		lizz_info("Sprite of \"");
		lizz_print(1, tmp->name);
		lizz_print(1, "\" button has been destroyed!\n");
		free(tmp);
	}
}

void lizz_destroy_all(void)
{
	destroy_all_btn();
}
