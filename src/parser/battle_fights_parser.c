/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** battle_fights parser functions
*/

# include "rpg.h"

bool configure_fight(fight_t **fight)
{
	(*fight)->pos.x = MAP_X - 1;
	(*fight)->pos.y = MAP_Y - 1;
	(*fight)->curent = 0;
	(*fight)->enemy_turn = false;
	(*fight)->map = create_battle_map(&(*fight)->pos);

	if ((*fight)->map == NULL)
		return (false);

	return (true);
}

void configure_enemy_texture(rpg_t *rpg, enemy_t **enemy, int fight, int id)
{
	sfVector2f size = { 60, 60 };
	sfVector2f scale = { 1.25, 1.25 };

	(*enemy)->rec.left = 0;
	(*enemy)->rec.width = (*enemy)->rec.height = 64;
	(*enemy)->img = get_texture(rpg, (*enemy)->stuff);
	if ((*enemy)->img == NULL)
		return;
	(*enemy)->form = sfSprite_create();
	sfSprite_setTexture((*enemy)->form, (*enemy)->img, sfFalse);
	sfSprite_setPosition((*enemy)->form, (*enemy)->pos);
	sfSprite_setTextureRect((*enemy)->form, (*enemy)->rec);
	sfSprite_setScale((*enemy)->form, scale);
	(*enemy)->frame = sfRectangleShape_create();
	sfRectangleShape_setSize((*enemy)->frame, size);
	sfRectangleShape_setFillColor((*enemy)->frame, sfRed);
	sfRectangleShape_setOutlineColor((*enemy)->frame, sfBlack);
	sfRectangleShape_setOutlineThickness((*enemy)->frame, 3);
	rpg->battle->fight[fight]->enemy[id] = *enemy;
}

void parse_enemy_values(rpg_t *rpg, config_setting_t *set, int id, int fight)
{
	enemy_t *enemy = malloc(sizeof(enemy_t));
	double posx = 0, posy = 0;;

	if (enemy == NULL)
		return;
	config_setting_lookup_string(set, "texture", \
	((const char **)&enemy->stuff));
	config_setting_lookup_int(set, "damage", &enemy->dmg);
	config_setting_lookup_int(set, "armor", &enemy->armor);
	config_setting_lookup_bool(set, "sword", ((int *)&enemy->sword));
	config_setting_lookup_int(set, "heal", &enemy->hp);
	config_setting_lookup_float(set, "pos_x", &posx);
	config_setting_lookup_float(set, "pos_y", &posy);
	config_setting_lookup_int(set, "rec_top", &enemy->rec.top);
	enemy->pos.x = posx;
	enemy->pos.y = posy;
	enemy->played = false;
	enemy->alive = true;
	printf("set alive to enenmy %d in fight %d\n", id, fight);
	configure_enemy_texture(rpg, &enemy, fight, id);
}

void parse_fight_values(rpg_t *rpg, config_setting_t *set, int key)
{
	config_setting_t *set_enemy = config_setting_lookup(set, "enemies");
	config_setting_t *enemy = NULL;
	int count = 0;

	if (set_enemy == NULL)
		return;
	rpg->battle->fight[key] = malloc(sizeof(fight_t));
	if (rpg->battle->fight[key] == NULL)
		return;
	if (!configure_fight(&rpg->battle->fight[key]))
		return;
	count = config_setting_length(set_enemy);
	rpg->battle->fight[key]->number_enemy = count;
	rpg->battle->fight[key]->enemy = malloc(sizeof(enemy_t *) * count);
	if (rpg->battle->fight[key]->enemy != NULL)
		for (int id = 0; count > 0 && id < count; id++) {
			enemy = config_setting_get_elem(set_enemy, id);
			if (enemy != NULL)
				parse_enemy_values(rpg, enemy, id, key);
		}
}

int configure_battle_fights(rpg_t *rpg)
{
	config_setting_t *set = parse_file("battle.cfg", "battle.fights");
	config_setting_t *fight = NULL;
	int count = 0;

	if (set == NULL)
		return (-1);

	count = config_setting_length(set);
	rpg->battle->number_fight = count;
	if (rpg->battle->fight == NULL) {
		rpg->battle->fight = malloc(sizeof(fight_t *) * count);
		if (rpg->battle->fight == NULL)
			return (-1);
	}
	for (int key = 0; count > 0 && key < count; key++) {
		fight = config_setting_get_elem(set, key);
		if (fight != NULL)
			parse_fight_values(rpg, fight, key);
	}
	return (0);
}
