/*
** EPITECH PROJECT, 2018
** hero_deplacement
** File description:
** rpg
*/

#include "rpg.h"

static void draw_anim(rpg_t *rpg, battle_t *battle)
{
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->hero->rec.left += 64;
	sfSprite_setTextureRect(
		battle->hero->form, battle->hero->rec);
	draw_all(rpg);
	display_enemy(rpg, battle);
	sfRenderWindow_drawSprite
		(rpg->win, battle->hero->form, NULL);
	sfRenderWindow_display(rpg->win);
}

static void anim(rpg_t *rpg, battle_t *battle, int a, int b)
{
	sfVector2f pos = sfSprite_getPosition(battle->hero->form);

	battle->hero->rec.left = 0;
	for (int i = 0; i < 9;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.08)))
			battle->time = sfClock_getElapsedTime(
				battle->clock);
		pos.x += a * (B_X / 8);
		pos.y += b * (B_Y / 8);
		sfSprite_setPosition(battle->hero->form, pos);
		draw_anim(rpg, battle);
		i++;
	}
}

static bool go_side(rpg_t *rpg, battle_t *battle)
{
	int x = battle->hero->pos.x;
	int y = battle->hero->pos.y;

	if (x < battle->hero->new.x) {
		if (battle->map[y][x + 1] == 2)
			return (false);
		battle->hero->pos.x += 1;
		battle->hero->rec.top = 192;
		anim(rpg, battle, 1, 0);
		return (true);
	} else if (x > battle->hero->new.x) {
		if (battle->map[y][x - 1] == 2)
			return (false);
		battle->hero->pos.x -= 1;
		battle->hero->rec.top = 64;
		anim(rpg, battle, -1, 0);
		return (true);
	} else
		return (false);
}

static bool go_up_down(rpg_t *rpg, battle_t *battle)
{
	int x = battle->hero->pos.x;
	int y = battle->hero->pos.y;

	if (y < battle->hero->new.y) {
		if (battle->map[y + 1][x] == 2)
			return (false);
		battle->hero->pos.y += 1;
		battle->hero->rec.top = 128;
		anim(rpg, battle, 0, 1);
		return (true);
	} else if (y > battle->hero->new.y) {
		if (battle->map[y - 1][x] == 2)
			return (false);
		battle->hero->pos.y -= 1;
		battle->hero->rec.top = 0;
		anim(rpg, battle, 0, -1);
		return (true);
	} else
		return (false);
}

void hero_deplacement(rpg_t *rpg, battle_t *battle)
{
	int a = abs(battle->hero->new.x - battle->hero->pos.x);
	int b = abs(battle->hero->new.y - battle->hero->pos.y);

	while (battle->hero->pos.x != battle->hero->new.x ||
	battle->hero->pos.y != battle->hero->new.y) {
		if ((a >= b && (go_side(rpg, battle) || go_up_down(rpg, battle)))
		|| (a < b && (go_up_down(rpg, battle) || go_side(rpg, battle)))) {
			battle->hero->rec.left = 0;
			sfSprite_setTextureRect(
			battle->hero->form, battle->hero->rec);
			draw_all(rpg);
			display_enemy(rpg, battle);
			display_hero(rpg, battle);
			sfRenderWindow_display(rpg->win);
		}
	}
	reset_map_state(battle);
}
