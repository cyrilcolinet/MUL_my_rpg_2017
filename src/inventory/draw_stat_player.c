/*
** EPITECH PROJECT, 2018
** draw_stat_player
** File description:
** rpg
*/

#include "rpg.h"

static void draw_icone(rpg_t *rpg, battle_t *battle, hero_t *hero)
{
	sfVector2f pos = {330, 380};

	for (int i = 0; i < 3; i++) {
		sfRectangleShape_setPosition(battle->icone, pos);
		sfRectangleShape_setTexture(
			battle->icone, battle->texture[i], sfTrue);
		sfRenderWindow_drawRectangleShape(
			rpg->win, battle->icone, NULL);
		pos.y += 50;
	}
	pos.x = 310;
	pos.y = 560;
	for (int i = 0; i < 4; i++) {
		sfRectangleShape_setPosition(hero->spell[i]->icone, pos);
		sfRectangleShape_setOutlineColor(
			hero->spell[i]->icone, sfTransparent);
		sfRenderWindow_drawRectangleShape(
			rpg->win, hero->spell[i]->icone, NULL);
		pos.y += 70;
	}
}

static void display_stat_hero(rpg_t *rpg, sfVector2f pos, int id)
{
	char *str = NULL;

	sfText_setPosition(rpg->battle->text, pos);
	if (id == 0)
		str = my_itoa(rpg->battle->hero->hp);
	else if (id == 1)
		str = my_itoa(rpg->battle->hero->dmg);
	if (id == 2)
		str = my_itoa(rpg->battle->hero->armor);
	sfText_setString(rpg->battle->text, str);
	free(str);
	sfRenderWindow_drawText(rpg->win, rpg->battle->text, NULL);
}

static void draw_stat_value(rpg_t *rpg, battle_t *battle, hero_t *hero)
{
	sfVector2f pos = {370, 370};
	char *str = NULL;

	sfText_setColor(battle->text, sfBlack);
	sfText_setCharacterSize(battle->text, 30);
	for (int i = 0; i < 3; i++) {
		display_stat_hero(rpg, pos, i);
		pos.y += 50;
	}
	pos.x = 380;
	pos.y = 560;
	for (int i = 0; i < 4; i++) {
		sfText_setPosition(battle->text, pos);
		str = my_itoa(hero->spell[i]->val);
		sfText_setString(battle->text, str);
		free(str);
		sfRenderWindow_drawText(
			rpg->win, battle->text, NULL);
		pos.y += 70;
	}
}

static void draw_hero(rpg_t *rpg, player_t *player)
{
	sfVector2f old_pos = sfSprite_getPosition(player->sprite);
	sfVector2f pos = {750, 340};
	sfVector2f scale = {5, 5};
	int top = player->rec.top;

	player->rec.top = 128;
	sfSprite_setPosition(player->sprite, pos);
	sfSprite_setScale(player->sprite, scale);
	sfSprite_setTextureRect(player->sprite, player->rec);
	sfRenderWindow_drawSprite(rpg->win, player->sprite, NULL);
	player->rec.top = top;
	scale.x = 1;
	scale.y = 1;
	sfSprite_setScale(player->sprite, scale);
	sfSprite_setPosition(player->sprite, old_pos);
	sfSprite_setTextureRect(player->sprite, player->rec);
}

void draw_stat_player(rpg_t *rpg, battle_t *battle, hero_t *hero)
{
	sfVector2f pos = {300, 260};
	
	draw_icone(rpg, battle, hero);
	draw_stat_value(rpg, battle, hero);
	draw_hero(rpg, rpg->player);
	sfText_setCharacterSize(battle->text, 40);
	sfText_setPosition(battle->text, pos);
	sfText_setString(battle->text, rpg->player->name);
	sfRenderWindow_drawText(
		rpg->win, battle->text, NULL);
}
