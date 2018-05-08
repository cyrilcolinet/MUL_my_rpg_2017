/*
** EPITECH PROJECT, 2018
** hero_deplacement
** File description:
** rpg
*/

#include "battle.h"

static void draw_anim(data_t *data, battle_t *battle)
{
	battle->hero->rec.left += 64;
	sfSprite_setTextureRect(
		battle->hero->form, battle->hero->rec);
	draw_all(data);
	display_enemy(data, battle);
	sfRenderWindow_drawSprite
		(data->window, battle->hero->form, NULL);
	sfRenderWindow_display(data->window);
}
static void anim(data_t *data, battle_t *battle, int a, int b)
{
	sfVector2f pos = sfSprite_getPosition(battle->hero->form);

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
		draw_anim(data, battle);
		i++;
	}
}

static bool go_side(data_t *data, battle_t *battle)
{
	int x = battle->hero->pos.x;
	int y = battle->hero->pos.y;

	if (x < battle->hero->new.x) {
		if (battle->map[y][x + 1] == 2)
			return (false);
		battle->hero->pos.x += 1;
		battle->hero->rec.top = 192;
		anim(data, battle, 1, 0);
		return (true);
	} else if (x > battle->hero->new.x) {
		if (battle->map[y][x - 1] == 2)
			return (false);
		battle->hero->pos.x -= 1;
		battle->hero->rec.top = 64;
		anim(data, battle, -1, 0);
		return (true);
	} else
		return (false);
}

static bool go_up_down(data_t *data, battle_t *battle)
{
	int x = battle->hero->pos.x;
	int y = battle->hero->pos.y;

	if (y < battle->hero->new.y) {
		if (battle->map[y + 1][x] == 2)
			return (false);
		battle->hero->pos.y += 1;
		battle->hero->rec.top = 128;
		anim(data, battle, 0, 1);
		return (true);
	} else if (y > battle->hero->new.y) {
		if (battle->map[y - 1][x] == 2)
			return (false);
		battle->hero->pos.y -= 1;
		battle->hero->rec.top = 0;
		anim(data, battle, 0, -1);
		return (true);
	} else
		return (false);
}

void hero_deplacement(data_t *data, battle_t *battle)
{
	while (battle->hero->pos.x != battle->hero->new.x ||
	battle->hero->pos.y != battle->hero->new.y) {
		if (go_side(data, battle) || go_up_down(data, battle)) {
			reset_map_state(battle);
			battle->hero->rec.left = 0;
			sfSprite_setTextureRect(
			battle->hero->form, battle->hero->rec);
			draw_all(data);
			display_enemy(data, battle);
			display_hero(data, battle);
			sfRenderWindow_display(data->window);
		}
	}
}
