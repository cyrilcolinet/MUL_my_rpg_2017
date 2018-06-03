/*
** EPITECH PROJECT, 2018
** draw_obj_stat
** File description:
** rpg
*/

#include "rpg.h"

static void display_stat_hero(rpg_t *rpg, sfVector2f pos,
	int id, equipement_t *obj)
{
	char *str = NULL;

	sfText_setPosition(rpg->battle->text, pos);
	if (id == 0)
		str = check_stat_hp_value(
			rpg->player->inventory, rpg->battle, obj);
	if (id == 1)
		str = check_stat_dmg_value(
			rpg->player->inventory, rpg->battle, obj);
	if (id == 2)
		str = check_stat_armor_value(
			rpg->player->inventory, rpg->battle, obj);
	sfText_setString(rpg->battle->text, str);
	free(str);
	sfRenderWindow_drawText(rpg->win, rpg->battle->text, NULL);
}

static void display_obj_stat_2(rpg_t *rpg, battle_t *battle,
	equipement_t *obj)
{
	sfVector2f pos = {450, 560};
	char *str = NULL;

	for (int i = 0; i < 4; i++) {
		sfText_setPosition(battle->text, pos);
		str = check_stat_magic_value(
			rpg->player->inventory, battle, obj, i);
		sfText_setString(battle->text, str);
		free(str);
		sfRenderWindow_drawText(
			rpg->win, battle->text, NULL);
		pos.y += 70;
		sfText_setColor(battle->text, sfGreen);
	}
}

static void display_obj_stat(rpg_t *rpg, battle_t *battle,
	equipement_t *obj)
{
	sfVector2f pos = {450, 370};

	sfText_setColor(battle->text, sfGreen);
	sfText_setCharacterSize(battle->text, 30);
	for (int i = 0; i < 3; i++) {
		display_stat_hero(rpg, pos, i, obj);
		sfText_setColor(battle->text, sfGreen);
		pos.y += 50;
	}
	display_obj_stat_2(rpg, battle, obj);
}

static void check_obj_slot(rpg_t *rpg, inventory_t *inv, int i)
{
	for (int j = 0; j < 4; j++) {
		if (inv->obj[j]->unlock
		&& inv->obj[j]->pos.x + inv->obj[j]->pos.y * 4 == i)
			display_obj_stat(rpg, rpg->battle, inv->obj[j]);
	}
}

void draw_obj_stat(rpg_t *rpg, inventory_t *inv)
{
	sfVector2f pos;

	for (int i = 0; i < 12; i++) {
		pos = sfRectangleShape_getPosition(inv->slot[i]);
		if ((inv->mouse.x < pos.x + 100 && inv->mouse.x > pos.x)
		&& (inv->mouse.y < pos.y + 100 && inv->mouse.y > pos.y))
			check_obj_slot(rpg, inv, i);
	}
}
