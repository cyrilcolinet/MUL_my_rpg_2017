/*
** EPITECH PROJECT, 2018
** battle_management
** File description:
** rpg
*/

#include "rpg.h"

static void display_message_skip(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos = {1400, 950};

	sfText_setPosition(battle->text, pos);
	sfText_setCharacterSize(battle->text, 40);
	sfText_setColor(battle->text, sfWhite);
	sfText_setString(battle->text, "Press 'N' pour passer le tour");
	sfRenderWindow_drawText(rpg->win, battle->text, NULL);
}

void draw_all(rpg_t *rpg)
{
	if (rpg->battle->id == 0)
		sfRectangleShape_setTexture(rpg->battle->background,
			rpg->battle->texture[4], sfTrue);
	else if (rpg->battle->id == 1)
		sfRectangleShape_setTexture(rpg->battle->background,
			rpg->battle->texture[5], sfTrue);
	else
		sfRectangleShape_setTexture(rpg->battle->background,
			rpg->battle->texture[6], sfTrue);
	sfRenderWindow_drawRectangleShape
		(rpg->win, rpg->battle->background, NULL);
	display_map(rpg, rpg->battle, rpg->battle->id);
	display_current_target(rpg, rpg->battle);
	display_interface(rpg, rpg->battle);
	draw_buttons(rpg);
}

static bool spell_select(rpg_t *rpg, battle_t *battle)
{
	if (battle->hero->spell_id != -1) {
		cast_spell(rpg, battle, battle->hero->spell_id);
		return (true);
	}
	return (false);
}

static void hero_selected(rpg_t *rpg, battle_t *battle)
{
	if (!spell_select(rpg, battle)) {
		if (!rpg->battle->hero->move)
			check_deplacement(rpg->battle);
		else if (rpg->battle->hero->move)
			hero_deplacement(rpg, rpg->battle);
		check_attack(rpg->battle);
		hero_attack(rpg, rpg->battle);
	}
}

void battle_management(rpg_t *rpg, battle_t *battle)
{
	reset_map_state(battle);
	if (end_battle(rpg, battle))
		return;
	change_turn(battle);
	if (rpg->battle->fight[rpg->battle->id]->enemy_turn)
		enemy_turn(rpg, rpg->battle);
	else if (rpg->battle->hero->select)
		hero_selected(rpg, battle);
	fill_map_state(rpg->battle, rpg->battle->id);
	draw_all(rpg);
	display_hero(rpg, rpg->battle);
	display_enemy(rpg, rpg->battle);
	if (!rpg->battle->fight[battle->id]->enemy_turn)
		display_message_skip(rpg, rpg->battle);
}
