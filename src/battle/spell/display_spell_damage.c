/*
** EPITECH PROJECT, 2018
** display_spell_damage.c
** File description:
** rpg
*/

#include "rpg.h"

void display_spell_damage(rpg_t *rpg, battle_t *battle, int i, int dmg)
{
	sfVector2f pos = sfRectangleShape_getPosition(
		battle->fight[battle->id]->map[i]);
	char *str = my_itoa(dmg);

	if (battle->map[i / 12][i % 12] == 1
	|| battle->map[i / 12][i % 12] == 2) {
		sfText_setColor(battle->text, sfColor_fromRGB(200, 0, 0));
		pos.x += 8;
		pos.y += 2;
		sfText_setPosition(battle->text, pos);
		sfText_setString(battle->text, str);
		sfRenderWindow_drawText(rpg->win, battle->text, NULL);
	}
	free(str);
	sfText_setColor(battle->text, sfWhite);
}

void display_ice_damage(rpg_t *rpg, battle_t *battle)
{
	int x = battle->hero->spell[2]->pos.x;
	int y = battle->hero->spell[2]->pos.y;

	if (x > battle->hero->pos.x) {
		display_spell_damage(rpg, battle, y * 12 + x,
			battle->hero->spell[2]->val);
	}
	if (x < battle->hero->pos.x) {
		display_spell_damage(rpg, battle, y * 12 + x,
			battle->hero->spell[2]->val);
	}
	if (y > battle->hero->pos.x) {
		display_spell_damage(rpg, battle, y * 12 + x,
			battle->hero->spell[2]->val);
	}
	if (y < battle->hero->pos.x) {
		display_spell_damage(rpg, battle, y * 12 + x,
			battle->hero->spell[2]->val);
	}
}

void display_strom_damage(rpg_t *rpg, battle_t *battle)
{
	int x = battle->hero->spell[3]->pos.x;
	int y = battle->hero->spell[3]->pos.y;

	if (x > battle->hero->pos.x) {
		display_spell_damage(rpg, battle, y * 12 + x,
			battle->hero->spell[3]->val);
	}
	if (x < battle->hero->pos.x) {
		display_spell_damage(rpg, battle, y * 12 + x,
			battle->hero->spell[3]->val);
	}
	if (y > battle->hero->pos.x) {
		display_spell_damage(rpg, battle, y * 12 + x,
			battle->hero->spell[3]->val);
	}
	if (y < battle->hero->pos.x) {
		display_spell_damage(rpg, battle, y * 12 + x,
			battle->hero->spell[3]->val);
	}

}
