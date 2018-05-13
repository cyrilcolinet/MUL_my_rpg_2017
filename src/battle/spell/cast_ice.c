/*
** EPITECH PROJECT, 2018
** cast_ice
** File description:
** rpg
*/

#include "rpg.h"

static void draw_anim(rpg_t *rpg, battle_t *battle, int i)
{
	if (i % 6 == 5)
		battle->hero->rec.left = 0;
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->hero->spell[2]->rec.left += 128;
	sfSprite_setTextureRect(battle->hero->spell[2]->form,
		battle->hero->spell[2]->rec);
	battle->hero->rec.left += 64;
	sfSprite_setTextureRect(battle->hero->form,
			battle->hero->rec);
	draw_all(rpg);
	display_hero(rpg, rpg->battle);
	display_enemy(rpg, rpg->battle);
	sfRenderWindow_drawSprite(rpg->win,
		battle->hero->spell[2]->form, NULL);
	display_ice_damage(rpg, battle);
	sfRenderWindow_display(rpg->win);
}

static void reset_spell(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos = battle->hero->spell[2]->pos;

	battle->hero->rec.top -= 4 * 64;
	battle->hero->rec.left = 0;
	sfSprite_setTextureRect(battle->hero->form,
			battle->hero->rec);
	battle->hero->spell[2]->rec.left = 0;
	battle->hero->spell[2]->rec.top = 0;
	sfSprite_setTextureRect(battle->hero->spell[2]->form,
		battle->hero->spell[2]->rec);
	battle->hero->attack = true;
	sfSprite_setRotation(battle->hero->spell[2]->form, 0);
	hit_the_target(rpg, battle, pos.y * 12 + pos.x,
		battle->hero->spell[2]->val);
}

static void set_angle_coord_sprite2(battle_t *battle, sfVector2f pos)
{
	if (battle->hero->spell[2]->pos.y > battle->hero->pos.y) {
		pos.x = battle->hero->spell[2]->pos.x * B_X + MAP_X + 144;
		pos.y = battle->hero->spell[2]->pos.y * B_Y + MAP_Y + 78;
		sfSprite_setPosition(battle->hero->spell[2]->form, pos);
		sfSprite_setRotation(battle->hero->spell[2]->form, 135);
		battle->hero->rec.top = 6 * 64;
	}
	if (battle->hero->spell[2]->pos.y < battle->hero->pos.y) {
		pos.x = battle->hero->spell[2]->pos.x * B_X + MAP_X - 35;
		pos.y = battle->hero->spell[2]->pos.y * B_Y + MAP_Y - 12;
		sfSprite_setPosition(battle->hero->spell[2]->form, pos);
		sfSprite_setRotation(battle->hero->spell[2]->form, -45);
		battle->hero->rec.top = 4 * 64;
	}
}

static void set_angle_coord_sprite(battle_t *battle, sfVector2f pos)
{
	if (battle->hero->spell[2]->pos.x > battle->hero->pos.x) {
		pos.x = battle->hero->spell[2]->pos.x * B_X + MAP_X + 128;
		pos.y = battle->hero->spell[2]->pos.y * B_Y + MAP_Y - 52;
		sfSprite_setPosition(battle->hero->spell[2]->form, pos);
		sfSprite_setRotation(battle->hero->spell[2]->form, 45);
		battle->hero->rec.top = 7 * 64;
	}
	if (battle->hero->spell[2]->pos.x < battle->hero->pos.x) {
		pos.x = battle->hero->spell[2]->pos.x * B_X + MAP_X - 40;
		pos.y = battle->hero->spell[2]->pos.y * B_Y + MAP_Y + 128;
		sfSprite_setPosition(battle->hero->spell[2]->form, pos);
		sfSprite_setRotation(battle->hero->spell[2]->form, -135);
		battle->hero->rec.top = 5 * 64;
	}
	set_angle_coord_sprite2(battle, pos);
}

void cast_ice(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos;

	set_angle_coord_sprite(battle, pos);
	for (int i = 0; i < 13;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.1)))
			battle->time = sfClock_getElapsedTime(
				battle->clock);
		draw_anim(rpg, battle, i);
		i++;
		if (i % 5 == 4) {
			battle->hero->spell[2]->rec.left = 0;
			battle->hero->spell[2]->rec.top += 128;
		}
	}
	reset_spell(rpg, battle);
}
