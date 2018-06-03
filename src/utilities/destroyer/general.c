/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** general destroyer
*/

# include "rpg.h"

void destroy_saves(rpg_t *rpg)
{
	save_t *tmp = NULL;

	while (rpg->saves != NULL) {
		tmp = rpg->saves;
		rpg->saves = tmp->next;
		free(tmp->player_name);
		sfText_destroy(tmp->name_text);
		sfText_destroy(tmp->pname_text);
		sfText_destroy(tmp->lvl_text);
		sfClock_destroy(tmp->clock);
		sfSprite_destroy(tmp->sprite);
		free(tmp);
	}
}

void exit_game(rpg_t *rpg)
{
	void (*tab[])(rpg_t *) = { destroy_saves, destroy_battle, destroy_map,
		destroy_assets, destroy_buttons, destroy_slides, destroy_sounds,
		destroy_player, NULL
	};

	sfSound_stop(get_sound(rpg, "main")->sound);
	if (rpg->capture != NULL)
		sfSprite_destroy(rpg->capture);
	sfText_destroy(rpg->text);
	sfClock_destroy(rpg->clock);
	sfFont_destroy(rpg->font);
	sfTexture_destroy(rpg->texture);
	sfRenderWindow_destroy(rpg->win);

	for (int i = 0; tab[i]; i++)
		tab[i](rpg);
}
