/*
** EPITECH PROJECT, 2018
** hero_set_attack
** File description:
** rpg
*/

#include "battle.h"

static void set_attack_orientation3(battle_t *battle,
		sfVector2f pos, sfVector2f hero)
{
	if (battle->hero->pos.y > pos.y) {
		hero.x -= 44;
		hero.y -= 44;
		battle->hero->rec.top = 9 * 64;
		sfSprite_setPosition(battle->hero->form, hero);
	} else if (battle->hero->pos.y < pos.y) {
		hero.x -= 44;
		hero.y -= 44;
		battle->hero->rec.top = 13 * 64;
		sfSprite_setPosition(battle->hero->form, hero);
	}
}

static void set_attack_orientation2(battle_t *battle,
		sfVector2f pos, sfVector2f hero)
{
	if (battle->hero->pos.x < pos.x) {
		if (battle->hero->sword) {
			hero.x -= 12;
			hero.y -= 48;
		} else {
			hero.x -= 44;
			hero.y -= 44;
		}
		battle->hero->rec.top = 15 * 64;
		sfSprite_setPosition(battle->hero->form, hero);
	}
}

void set_attack_orientation(battle_t *battle, sfVector2f pos)
{
	sfVector2f hero = sfSprite_getPosition(battle->hero->form);

	if (battle->hero->pos.x > pos.x) {
		if (battle->hero->sword) {
			hero.x -= 64;
			hero.y -= 48;
		} else {
			hero.x -= 44;
			hero.y -= 44;
		}
		battle->hero->rec.top = 11 * 64;
		sfSprite_setPosition(battle->hero->form, hero);
	}
	set_attack_orientation2(battle, pos, hero);
	set_attack_orientation3(battle, pos, hero);
}
