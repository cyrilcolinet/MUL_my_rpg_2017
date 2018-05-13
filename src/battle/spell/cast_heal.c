/*
** EPITECH PROJECT, 2018
** cast_heal
** File description:
** rpg
*/

#include "rpg.h"

static void draw_anim(rpg_t *rpg, battle_t *battle, int i)
{
	if (i % 6 == 5)
		battle->hero->rec.left = 0;
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->hero->spell[0]->rec.left += 128;
	sfSprite_setTextureRect(battle->hero->spell[0]->form,
		battle->hero->spell[0]->rec);
	battle->hero->rec.left += 64;
	sfSprite_setTextureRect(battle->hero->form,
			battle->hero->rec);
	draw_all(rpg);
	display_hero(rpg, rpg->battle);
	display_enemy(rpg, rpg->battle);
	sfRenderWindow_drawSprite(rpg->win,
			battle->hero->spell[0]->form, NULL);
	sfRenderWindow_display(rpg->win);
}

static void reset_spell(battle_t *battle)
{
	battle->hero->rec.top -= 4 * 64;
	battle->hero->rec.left = 0;
	sfSprite_setTextureRect(battle->hero->form,
			battle->hero->rec);
	battle->hero->spell[0]->rec.left = 0;
	battle->hero->spell[0]->rec.top = 0;
	sfSprite_setTextureRect(battle->hero->spell[0]->form,
			battle->hero->spell[0]->rec);
	battle->hero->attack = true;
}

void cast_heal(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos;

	pos.x = battle->hero->spell[0]->pos.x * B_X + MAP_X - 8;
	pos.y = battle->hero->spell[0]->pos.y * B_Y + MAP_Y - 32;
	sfSprite_setPosition(battle->hero->spell[0]->form, pos);
	for (int i = 0; i < 18;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.1)))
			battle->time = sfClock_getElapsedTime(
				battle->clock);
		draw_anim(rpg, battle, i);
		i++;
		if (i % 5 == 4) {
			battle->hero->spell[0]->rec.left = 0;
			battle->hero->spell[0]->rec.top += 128;
		}
	}
	reset_spell(battle);
}
