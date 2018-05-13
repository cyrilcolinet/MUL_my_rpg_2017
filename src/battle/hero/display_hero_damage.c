/*
** EPITECH PROJECT, 2018
** display_damage.c
** File description:
** rpg
*/

#include "rpg.h"

void display_hero_damage(rpg_t *rpg, battle_t *battle, int i)
{
	sfVector2f pos = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[i]->form);
	char *str = my_itoa(battle->hero->dmg);

	sfText_setColor(battle->text, sfColor_fromRGB(200, 0, 0));
	pos.x -= 4;
	pos.y += 2;
	sfText_setPosition(battle->text, pos);
	sfText_setString(battle->text, str);
	free(str);
	sfRenderWindow_drawText(rpg->win, battle->text, NULL);
	sfText_setColor(battle->text, sfWhite);
}
