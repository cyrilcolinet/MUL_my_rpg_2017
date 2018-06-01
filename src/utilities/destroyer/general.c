/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** general destroyer
*/

# include "rpg.h"

void exit_game(rpg_t *rpg)
{
	destroy_map(rpg);
	free_battle(rpg);
	sfSound_stop(get_sound(rpg, "main")->sound);
	destroy_assets(rpg);
	destroy_buttons(rpg);
	destroy_slides(rpg);
	destroy_sounds(rpg);
	sfText_destroy(rpg->text);
	destroy_player(rpg);
	sfRenderWindow_destroy(rpg->win);
	sfClock_destroy(rpg->clock);
	sfFont_destroy(rpg->font);
	sfTexture_destroy(rpg->texture);
	if (rpg->capture != NULL)
		sfSprite_destroy(rpg->capture);
}
