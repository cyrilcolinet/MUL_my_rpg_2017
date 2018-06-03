/*
** EPITECH PROJECT, 2018
** cast_spell
** File description:
** rpg
*/

#include "rpg.h"

static void select_simple_pos(battle_t *battle, int id)
{
	int x = battle->mouse.x;
	int y = battle->mouse.y;
	sfVector2f pos;
	sfVector2f size;

	for (int i = 0; i < 120; i++) {
		pos = sfRectangleShape_getPosition(
			battle->fight[battle->id]->map[i]);
		size = sfRectangleShape_getSize(
			battle->fight[battle->id]->map[i]);
		if (x > pos.x && x < pos.x + size.x
		&& y > pos.y && y < pos.y + size.y
		&& (abs(i % 12 - battle->hero->pos.x)
		+ abs(i / 12 - battle->hero->pos.y) <= 5)) {
			battle->hero->spell[id]->pos.x = i % 12;
			battle->hero->spell[id]->pos.y = i / 12;
			return;
		}
	}
	battle->hero->spell[id]->cast = false;
}

static void select_double_pos2(battle_t *battle, sfVector2f pos,
		sfVector2f hero, int y)
{
	int id = battle->hero->spell_id;

	if (y > pos.y + B_Y) {
		if (hero.y + 1 <= 9) {
			battle->hero->spell[id]->pos.x = hero.x;
			battle->hero->spell[id]->pos.y = hero.y + 1;
		}
	}
	if (y < pos.y) {
		if (hero.y - 1 >= 0) {
			battle->hero->spell[id]->pos.x = hero.x;
			battle->hero->spell[id]->pos.y = hero.y - 1;
		}
	}
}

static void select_double_pos(battle_t *battle, int id)
{
	sfVector2f pos = sfSprite_getPosition(battle->hero->form);
	sfVector2f hero;
	int x = battle->mouse.x;
	int y = battle->mouse.y;

	hero.x = battle->hero->pos.x;
	hero.y = battle->hero->pos.y;
	if (x < pos.x + B_X && x > pos.x)
		select_double_pos2(battle, pos, hero, y);
	if (x < pos.x) {
		if (hero.x - 1 >= 0) {
			battle->hero->spell[id]->pos.x = hero.x - 1;
			battle->hero->spell[id]->pos.y = hero.y;
		}
	} else if (x > pos.x + B_X) {
		if (hero.x + 1 <= 11) {
			battle->hero->spell[id]->pos.x = hero.x + 1;
			battle->hero->spell[id]->pos.y = hero.y;
		}
	}
}

void cast_spell_attack(battle_t *battle)
{
	int id = battle->hero->spell_id;

	if (id == 0 || id == 1) {
		battle->hero->spell[id]->cast = true;
		select_simple_pos(battle, id);
	} else if (id == 2 || id == 3) {
		battle->hero->spell[id]->cast = true;
		select_double_pos(battle, id);
	}
}
