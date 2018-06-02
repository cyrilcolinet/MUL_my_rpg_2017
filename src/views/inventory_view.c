/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** inventory view displing
*/

# include "rpg.h"

static void draw_stat_player(rpg_t *rpg, battle_t *battle, hero_t *hero)
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

static void draw_inventory(rpg_t *rpg, inventory_t *inv)
{
	sfRenderWindow_drawRectangleShape(rpg->win, inv->win, NULL);
	sfRenderWindow_drawRectangleShape(rpg->win, inv->armor, NULL);
	sfRenderWindow_drawRectangleShape(rpg->win, inv->weapon, NULL);
	for (int i = 0; i < 12; i++)
		sfRenderWindow_drawRectangleShape(rpg->win, inv->slot[i], NULL);
	draw_stat_player(rpg, rpg->battle, rpg->battle->hero);
}

void inventory_view(rpg_t *rpg)
{
	if (rpg->capture == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, rpg->capture, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Iventory");
	draw_inventory(rpg, rpg->player->inventory);
}
