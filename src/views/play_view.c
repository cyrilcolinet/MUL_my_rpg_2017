/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** play_view functions
*/

# include "rpg.h"

void display_pnj(rpg_t *rpg, quest_t *quest)
{
	for (int i = 0; i < 3; i++) {
		sfSprite_setTexture(
			quest->pnj[i]->sprite, quest->pnj[i]->texture, sfTrue);
		sfSprite_setTextureRect(
		quest->pnj[i]->sprite, quest->pnj[i]->rec);
	}
	if (rpg->map_id == 0) {
		sfRenderWindow_drawSprite(
		rpg->win, quest->pnj[0]->sprite, NULL);
	} else if (rpg->map_id == 1) {
		sfRenderWindow_drawSprite(
		rpg->win, quest->pnj[1]->sprite, NULL);
		sfRenderWindow_drawSprite(
		rpg->win, quest->pnj[2]->sprite, NULL);
	}
}

void display_map_content(rpg_t *rpg)
{
	map_t *map = rpg->map[rpg->map_id];
	sfSprite *sprite = NULL;

	if (map && map->texture) {
		sprite = get_sprite(rpg, map->texture);
		if (sprite)
			sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	}
	display_pnj(rpg, rpg->player->quest);
	sfRenderWindow_drawSprite(rpg->win, rpg->player->sprite, NULL);
	player_interaction(rpg);
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
