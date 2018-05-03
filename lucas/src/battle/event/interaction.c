/*
** EPITECH PROJECT, 2018
** interaction
** File description:
** rpg
*/

#include "battle.h"

static void right_click(battle_t *battle)
{
	deplacement(battle);
}

static void left_click(battle_t *battle)
{
	sfVector2f pos;

	for (int i = 0; i < 120; i++) {
		pos = sfRectangleShape_getPosition
			(battle->fight[battle->id]->map[i]);
		if ((battle->mouse.x > pos.x && battle->mouse.x < pos.x + B_X)
		&& (battle->mouse.y > pos.y && battle->mouse.y < pos.y + B_Y))
			select_or_unselect(battle, i);
	}
}

static void change_turn(battle_t *battle)
{
	int n = 0;

	if (!battle->fight[battle->id]->enemy_turn &&
	!battle->hero->played && battle->hero->move)
		battle->hero->played = true;

	if (battle->hero->played && !battle->fight[battle->id]->enemy_turn) {
		for (int i = 0; i < battle->fight[battle->id]->number_enemy; i++)
			battle->fight[battle->id]->enemy[i]->played = false;
		battle->hero->played = false;
		battle->hero->attack = false;
		battle->hero->move = false;
		battle->fight[battle->id]->enemy_turn = true;
	}

	if (battle->fight[battle->id]->enemy_turn) {
		for (int i = 0; i < battle->fight[battle->id]->number_enemy; i++) {
			if (battle->fight[battle->id]->enemy[i]->played)
				n++;
		}
		if (n == battle->fight[battle->id]->number_enemy) {
			battle->hero->move = false;
			battle->hero->played = false;
			battle->hero->attack = false;
			battle->fight[battle->id]->enemy_turn = false;
		}
	}
}

void interaction(battle_t *battle, sfEvent event)
{
	if (event.type == sfEvtKeyPressed) {
	}

	if (event.type == sfEvtMouseButtonPressed) {
		if (event.mouseButton.button == sfMouseLeft)
			left_click(battle);
		if (event.mouseButton.button == sfMouseRight)
			right_click(battle);
	}
	if (!battle->fight[battle->id]->enemy_turn) {
		check_deplacement(battle);
		attack(battle, event);
	}
	change_turn(battle);
}
