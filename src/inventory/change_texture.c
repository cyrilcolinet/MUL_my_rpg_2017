/*
** EPITECH PROJECT, 2018
** change_texture
** File description:
** rpg
*/

#include "rpg.h"

static char *check_armor(inventory_t *inv, char *str)
{
	int nb = -1;

	for (int i = 0; i < 4; i++) {
		if (inv->obj[i]->unlock
		&& inv->obj[i]->type == 0 && inv->obj[i]->equiped) {
			nb = i;
			break;
		}
	}
	if (nb > -1 && my_strcmp(inv->obj[nb]->name, "iron_armor") == 0)
		str = my_strcat(str, "fer_");
	else if (nb > -1
		&& my_strcmp(inv->obj[nb]->name, "leather_armor") == 0)
		str = my_strcat(str, "cuir_");
	else
		str = my_strcat(str, "nu_");
	return (str);
}

static char *check_weapon(inventory_t *inv, char *str, hero_t *hero)
{
	int nb = -1;

	for (int i = 0; i < 4; i++) {
		if (inv->obj[i]->unlock
		&& inv->obj[i]->type == 1 && inv->obj[i]->equiped) {
			nb = i;
			break;
		}
	}
	if (nb > -1 && my_strcmp(inv->obj[nb]->name, "sword") == 0) {
		str = my_strcat(str, "sword");
		hero->sword = true;
	} else if (nb > -1
		&& my_strcmp(inv->obj[nb]->name, "knife") == 0)
		str = my_strcat(str, "knife");
	else
		str = my_strcat(str, "no");
	return (str);
}

void change_texture(rpg_t *rpg, player_t *player,
	hero_t *hero, inventory_t *inv)
{
	char *str = NULL;

	hero->sword = false;
	if (player->sexe == 1)
		str = my_strdup("man_");
	if (player->sexe == 2)
		str = my_strdup("women_");
	str = check_armor(inv, str);
	str = check_weapon(inv, str, hero);
	player->texture = get_texture(rpg, str);
	sfSprite_setTexture(player->sprite, player->texture, sfTrue);
	sfSprite_setTexture(hero->form, player->texture, sfTrue);
	sfSprite_setTextureRect(player->sprite, player->rec);
	sfSprite_setTextureRect(hero->form, hero->rec);
	free(str);
}
