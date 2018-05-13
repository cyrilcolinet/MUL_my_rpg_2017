/*
** EPITECH PROJECT, 2018
** display_enemy_dead_animation
** File description:
** rpg
*/

#include "rpg.h"

static void draw_anim(rpg_t *rpg, battle_t *battle, int i)
{
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->fight[battle->id]->enemy[i]->rec.left += 64;
	sfSprite_setTextureRect(battle->fight[battle->id]->
	enemy[i]->form, battle->fight[battle->id]->enemy[i]->rec);
	draw_all(rpg);
	display_enemy(rpg, battle);
	display_hero(rpg, battle);
	sfRenderWindow_display(rpg->win);
}

void display_enemy_dead_animation(rpg_t *rpg, battle_t *battle, int i)
{
	battle->fight[battle->id]->enemy[i]->alive = true;
	battle->fight[battle->id]->enemy[i]->rec.top = 8 * 64;
	battle->fight[battle->id]->enemy[i]->rec.left = 0;
	sfSprite_setTextureRect(battle->fight[battle->id]->
		enemy[i]->form, battle->fight[battle->id]->enemy[i]->rec);
	for (int a = 0; a < 5;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.12)))
			battle->time = sfClock_getElapsedTime(
				battle->clock);
		draw_anim(rpg, battle, i);
		a++;
	}
	battle->fight[battle->id]->enemy[i]->alive = false;
}
