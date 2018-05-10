/*
** EPITECH PROJECT, 2018
** battle_management
** File description:
** rpg
*/

#include "rpg.h"

void draw_all(rpg_t *rpg)
{
	sfRenderWindow_drawRectangleShape
		(rpg->win, rpg->battle->background, NULL);
	display_map(rpg, rpg->battle, rpg->battle->id);
	display_current_target(rpg->battle);
	display_interface(rpg, rpg->battle);
}


void battle_management(rpg_t *rpg, battle_t *battle)
{
	change_turn(battle);
	if (rpg->battle->fight[rpg->battle->id]->enemy_turn)
		enemy_turn(rpg, rpg->battle);
	else if (rpg->battle->hero->select) {
		if (!rpg->battle->hero->move)
			check_deplacement(rpg->battle);
		else if (rpg->battle->hero->move)
			hero_deplacement(rpg, rpg->battle);
		check_attack(rpg->battle);
		hero_attack(rpg, rpg->battle);
	}
	fill_map_state(rpg->battle, rpg->battle->id);
	draw_all(rpg);
	display_hero(rpg, rpg->battle);
	display_enemy(rpg, rpg->battle);
}
