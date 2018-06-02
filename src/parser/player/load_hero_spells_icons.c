/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** load_spells incons functions
*/

# include "rpg.h"

void load_hero_spells_icons(rpg_t *rpg)
{
	hero_t *hero = rpg->battle->hero;
	sfVector2f size = {50, 50};

	hero->spell[0]->img = get_texture(rpg, "heal_icon");
	hero->spell[1]->img = get_texture(rpg, "fire_icon");
	hero->spell[2]->img = get_texture(rpg, "ice_icon");
	hero->spell[3]->img = get_texture(rpg, "storm_icon");

	for (int i = 0; i < 4; i++) {
		hero->spell[i]->icone = sfRectangleShape_create();
		sfRectangleShape_setSize(hero->spell[i]->icone, size);
		sfRectangleShape_setTexture(hero->spell[i]->icone,
			hero->spell[i]->img, sfTrue);
		sfRectangleShape_setOutlineThickness(hero->spell[i]->icone, 5);
		sfRectangleShape_setOutlineColor(hero->spell[i]->icone,
			sfTransparent);
	}
}
