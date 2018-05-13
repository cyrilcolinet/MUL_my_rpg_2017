/*
** EPITECH PROJECT, 2018
** enemy_attack_anim.c
** File description:
** rpg
*/

#include "rpg.h"

static void draw_anim(rpg_t *rpg, battle_t *battle, int a)
{
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->fight[battle->id]->enemy[a]->rec.left += 128;
	sfSprite_setTextureRect(
		battle->fight[battle->id]->enemy[a]->form,
		battle->fight[battle->id]->enemy[a]->rec);
	draw_all(rpg);
	display_hero(rpg, battle);
	display_other_enemy(rpg, battle, a);
	sfRenderWindow_drawSprite(rpg->win,
		battle->fight[battle->id]->enemy[a]->form, NULL);
	display_enemy_damage(rpg, battle, a);
	sfRenderWindow_display(rpg->win);
}

static void reset_texture_position(battle_t *battle, int a)
{
	battle->fight[battle->id]->enemy[a]->rec.top = ((battle->fight
		[battle->id]->enemy[a]->rec.top - (9 * 64)) / 128) * 64;
	battle->fight[battle->id]->enemy[a]->rec.left = 0;
	battle->fight[battle->id]->enemy[a]->rec.width = 64;
	battle->fight[battle->id]->enemy[a]->rec.height = 64;
	sfSprite_setTextureRect(battle->fight[battle->id]->enemy[a]->form,
		battle->fight[battle->id]->enemy[a]->rec);
}

void enemy_attack_anim(rpg_t *rpg, battle_t *battle,
		sfVector2f pos, int a)
{
	battle->fight[battle->id]->enemy[a]->rec.width = 128;
	battle->fight[battle->id]->enemy[a]->rec.height = 128;
	for (int i = 0; i < 10;) {
		battle->time = sfTime_Zero;
		sfClock_restart(battle->clock);
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.1)))
			battle->time = sfClock_getElapsedTime(battle->clock);
		draw_anim(rpg, battle, a);
		i++;
		if (i == 5)
			battle->fight[battle->id]->enemy[a]->rec.left = 0;
	}
	pos.x += 32;
	pos.y += 32;
	sfSprite_setPosition(battle->fight[battle->id]->enemy[a]->form, pos);
	reset_texture_position(battle, a);
}
