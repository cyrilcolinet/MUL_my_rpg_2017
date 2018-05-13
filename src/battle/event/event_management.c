/*
** EPITECH PROJECT, 2018
** event_management
** File description:
** rpg
*/

#include "rpg.h"

static void mouse_coord(battle_t *battle, sfEvent *event)
{
	if (event->type == sfEvtMouseMoved) {
		battle->mouse.x = event->mouseMove.x;
		battle->mouse.y = event->mouseMove.y;
	}
}

static void battle_event_management2(rpg_t *rpg, battle_t *battle
				     , sfEvent *event)
{
	if (event->key.code == sfKeyX) {
		battle->hero->played = false;
		battle->hero->move = false;
		battle->hero->attack = false;
		if (battle->id < 2)
			battle->id++;
	}
	if (event->key.code == sfKeyW) {
		battle->hero->played = false;
		battle->hero->move = false;
		battle->hero->attack = false;
		if (battle->id > 0)
			battle->id--;
	}
	if (event->key.code == sfKeyA) {
		battle->run = false;
		sfSprite_setTextureRect(
			rpg->player->sprite, rpg->player->rect);
	}	
}

void battle_event_management(rpg_t *rpg, battle_t *battle, sfEvent *event)
{
	mouse_coord(battle, event);
	if (!battle->fight[battle->id]->enemy_turn)
		interaction(battle, event);
	if (event->type == sfEvtKeyReleased) {
		if (event->key.code == sfKeyN) {
			reset_map_state(battle);
			battle->hero->played = true;
		}
		battle_event_management2(rpg, battle, event);
	}
}
