/*
** EPITECH PROJECT, 2018
** call_interaction
** File description:
** rpg
*/

#include "rpg.h"

static void call_map_0_interaction(rpg_t *rpg, int id)
{
	void (*inter[7])(rpg_t *, int) = {
		go_to_spawn, start_fight_2, start_fight_3, start_fight_1,
		talk_to_paysan, go_to_city, talk_to_totem
	};
}

static void call_map_1_interaction(rpg_t *rpg, int id)
{
	void (*inter[6])(rpg_t *, int) = {
		go_to_campagne, go_in_city, go_out_city,
		go_to_castle, talk_to_trader, talk_to_soldier
	};
}

void call_interaction(rpg_t *rpg)
{
	if (rpg->map_id == 0)
		call_map_0_interaction(rpg, 0);
	if (rpg->map_id == 1)
		call_map_1_interaction(rpg, 1);
}
