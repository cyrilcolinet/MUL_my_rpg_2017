/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** play_view functions
*/

# include "rpg.h"

void display_map_content(rpg_t *rpg)
{
	map_t *map = rpg->map[rpg->map_id];
	sfSprite *sprite = NULL;

	if (map && map->texture) {
		sprite = get_sprite(rpg, map->texture);
		if (sprite)
			sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	}
	player_interaction(rpg);
	sfRenderWindow_drawSprite(rpg->win, rpg->player->sprite, NULL);
}

void play_view(rpg_t *rpg)
{
	if (rpg->battle->run)
		battle_management(rpg, rpg->battle);
	else if (!rpg->battle->run) {
		player_deplacement(rpg);
		display_map_content(rpg);
		sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek");
	}
}
