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
		if (event->key.code == sfKeyX) {
			battle->hero->played = false;
			battle->hero->move = false;
			battle->hero->attack = false;
			battle->id++;
		}
		if (event->key.code == sfKeyW) {
			battle->hero->played = false;
			battle->hero->move = false;
			battle->hero->attack = false;
			battle->id--;
		}
		if (event->key.code == sfKeyT) {
			battle->hero->spell[1]->cast = false;
			battle->hero->spell[1]->select = true;
			battle->hero->spell[1]->unlock = true;
			battle->hero->spell[2]->cast = false;
			battle->hero->spell[2]->select = false;
			battle->hero->spell[2]->unlock = false;
		}
		if (event->key.code == sfKeyY) {
			battle->hero->spell[1]->cast = false;
			battle->hero->spell[1]->select = false;
			battle->hero->spell[1]->unlock = false;
			battle->hero->spell[2]->cast = false;
			battle->hero->spell[2]->select = true;
			battle->hero->spell[2]->unlock = true;
		}
		if (event->key.code == sfKeyP) {
			sfSprite_setTexture(battle->hero->form, battle->fight[battle->id]->enemy[0]->img, false);
			battle->hero->sword = false;
		}
		if (event->key.code == sfKeyO) {
			sfSprite_setTexture(battle->hero->form, battle->hero->img, false);
			battle->hero->sword = true;
		}
		if (event->key.code == sfKeyA) {
			battle->run = false;
			sfSprite_setPosition(*rpg->player->sprite, rpg->player->pos);
			sfSprite_setTextureRect(*rpg->player->sprite, rpg->player->rect);
		}
	}
}
