/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** rpg
*/

#include "rpg.h"

void display_hero(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos;

	pos.x = MAP_X + battle->hero->pos.x * B_X + 15;
	pos.y = MAP_Y + battle->hero->pos.y * B_Y - 5;
	sfSprite_setPosition(battle->hero->form, pos);
	sfRenderWindow_drawSprite
		(rpg->win, battle->hero->form, NULL);
}

void display_enemy(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos;
	int id = battle->id;

	for (int i = 0; i < battle->fight[id]->number_enemy; i++) {
		if (battle->fight[id]->enemy[i]->alive) {
			pos.x = MAP_X + battle->fight[id]->enemy[i]->
				pos.x * B_X + 15;
			pos.y = MAP_Y + battle->fight[id]->enemy[i]->
				pos.y * B_Y - 5;
			sfSprite_setPosition
				(battle->fight[id]->enemy[i]->form, pos);
			sfRenderWindow_drawSprite(rpg->win,
				battle->fight[id]->enemy[i]->form, NULL);
		}
	}
}

static void display_turn(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos = {700, 60};

	sfText_setPosition(battle->text, pos);
	sfText_setCharacterSize(battle->text, 48);
	sfText_setColor(battle->text, sfColor_fromRGB(167, 167, 167));
	if (battle->fight[battle->id]->enemy_turn)
		sfText_setString(battle->text, "Enemy turn");
	else
		 sfText_setString(battle->text, "Player turn");
	sfRenderWindow_drawText(rpg->win, battle->text, NULL);
	sfText_setCharacterSize(battle->text, 14);
	sfText_setColor(battle->text, sfWhite);
}

void display_map(rpg_t *rpg, battle_t *battle, int id)
{
	sfVector2f pos =  {200, 950};

	for (int i = 0; i < 120; i++) {
		sfRenderWindow_drawRectangleShape
			(rpg->win, battle->fight[id]->map[i], NULL);
	}
	for (int i = 0; i < 4; i++) {
		sfRectangleShape_setPosition(
			battle->hero->spell[i]->icone, pos);
		pos.x += 80;
		sfRectangleShape_setOutlineColor(
			battle->hero->spell[i]->icone, sfTransparent);
		if (battle->hero->spell_id == i)
			sfRectangleShape_setOutlineColor(
				battle->hero->spell[i]->icone, sfRed);
		sfRenderWindow_drawRectangleShape(
			rpg->win, battle->hero->spell[i]->icone, NULL);
	}
	display_turn(rpg, battle);
}
