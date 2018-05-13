/*
** EPITECH PROJECT, 2018
** interaction
** File description:
** rpg
*/

#include "rpg.h"

static void right_click(battle_t *battle)
{
	if (!battle->fight[battle->id]->enemy_turn && battle->hero->select) {
		if (battle->hero->spell_id != -1)
			cast_spell_attack(battle);
		else {
			deplacement(battle);
			attack(battle);
		}
	}
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
	for (int i = 0; i < 4; i++) {
		pos = sfRectangleShape_getPosition
			(battle->hero->spell[i]->icone);
		if ((battle->mouse.x > pos.x && battle->mouse.x < pos.x + 50)
		&& (battle->mouse.y > pos.y && battle->mouse.y < pos.y + 50)) {
			battle->hero->spell_id = i;
			battle->hero->select = true;
		}
	}
}

void interaction(battle_t *battle, sfEvent *event)
{
	if (event->type == sfEvtMouseButtonPressed) {
		if (event->mouseButton.button == sfMouseLeft)
			left_click(battle);
		if (event->mouseButton.button == sfMouseRight)
			right_click(battle);
	}
}
