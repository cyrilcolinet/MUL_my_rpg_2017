/*
** EPITECH PROJECT, 2018
** cast_heal
** File description:
** rpg
*/

#include "rpg.h"

static void display_heal(rpg_t *rpg, battle_t *battle, int i, int heal)
{
	sfVector2f pos = sfRectangleShape_getPosition(
		battle->fight[battle->id]->map[i]);
	char *str = my_itoa(heal);

	if (battle->map[i / 12][i % 12] == 1
	|| battle->map[i / 12][i % 12] == 2) {
		sfText_setColor(battle->text, sfColor_fromRGB(0, 200, 0));
		pos.x += 8;
		pos.y += 2;
		sfText_setPosition(battle->text, pos);
		sfText_setString(battle->text, str);
		sfRenderWindow_drawText(rpg->win, battle->text, NULL);
	}
	free(str);
	sfText_setColor(battle->text, sfWhite);
}

static void heal_the_target(battle_t *battle, int i, int val)
{
	int x = i % 12;
	int y = i / 12;
	int a = 0;
	int b = 0;

	if (battle->map[y][x] == 1) {
		if (battle->hero->hp + val >= battle->hero->hp_max)
			battle->hero->hp = battle->hero->hp_max;
		else
			battle->hero->hp += val;
	}
	for (int j = 0 ;j < battle->fight[
	battle->id]->number_enemy; j++) {
		a = battle->fight[battle->id]->enemy[j]->pos.x;
		b = battle->fight[battle->id]->enemy[j]->pos.y;
		if (battle->map[y][x] == 2 && x == a && y == b
		&& battle->hero->hp + val >= battle->hero->hp_max)
			battle->fight[battle->id]->enemy[j]->hp =
			battle->fight[battle->id]->enemy[j]->hp_max;
		else if (battle->map[y][x] == 2 && x == a && y == b)
			battle->fight[battle->id]->enemy[j]->hp += val;
	}
}

static void draw_anim(rpg_t *rpg, battle_t *battle, int i)
{
	sfVector2f pos = battle->hero->spell[0]->pos;

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
	display_heal(rpg, battle, pos.y * 12 + pos.x,
		battle->hero->spell[0]->val);
	sfRenderWindow_display(rpg->win);
}

static void reset_spell(battle_t *battle)
{
	sfVector2f pos = battle->hero->spell[1]->pos;

	battle->hero->rec.top -= 4 * 64;
	battle->hero->rec.left = 0;
	sfSprite_setTextureRect(battle->hero->form,
			battle->hero->rec);
	battle->hero->spell[0]->rec.left = 0;
	battle->hero->spell[0]->rec.top = 0;
	sfSprite_setTextureRect(battle->hero->spell[0]->form,
			battle->hero->spell[0]->rec);
	battle->hero->attack = true;
	heal_the_target(battle, pos.y * 12 + pos.x,
			battle->hero->spell[0]->val);
}

void cast_heal(rpg_t *rpg, battle_t *battle)
{
	sfVector2f pos;

	pos.x = battle->hero->spell[0]->pos.x * B_X + MAP_X - 8;
	pos.y = battle->hero->spell[0]->pos.y * B_Y + MAP_Y - 32;
	sfSprite_setPosition(battle->hero->spell[0]->form, pos);
	reset_map_state(battle);
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
