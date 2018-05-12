/*
** EPITECH PROJECT, 2018
** init_fight
** File description:
** rpg
*/

# include "rpg.h"

void create_map(fight_t *fight)
{
	sfVector2f size = {B_X, B_Y};
	int n = 0;

	fight->map = malloc(sizeof(sfRectangleShape *) * 120);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			fight->map[n] = sfRectangleShape_create();
			sfRectangleShape_setPosition(fight->map[n], fight->pos);
			sfRectangleShape_setSize(fight->map[n], size);
			sfRectangleShape_setFillColor
			(fight->map[n], sfTransparent);
			sfRectangleShape_setOutlineColor
			(fight->map[n], sfColor_fromRGBA(125, 125, 135, 90));
			sfRectangleShape_setOutlineThickness(fight->map[n], 1);
			fight->pos.x += B_X;
			n++;
		}
		fight->pos.x = MAP_X - 1;
		fight->pos.y += B_Y;
	}
}

sfRectangleShape **create_battle_map(sfVector2f *pos)
{
	sfRectangleShape **map = malloc(sizeof(*map) * 120);
	sfVector2f size = { B_X, B_Y };
	sfColor color = sfColor_fromRGBA(125, 125, 135, 90);
	int i = 0;

	if (map == NULL)
		return (NULL);
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 12; col++) {
			map[i] = sfRectangleShape_create();
			sfRectangleShape_setPosition(map[i], *pos);
			sfRectangleShape_setSize(map[i], size);
			sfRectangleShape_setFillColor(map[i], sfTransparent);
			sfRectangleShape_setOutlineColor(map[i], color);
			sfRectangleShape_setOutlineThickness(map[i++], 1);
			(*pos).x += B_X;
		}
		(*pos).x = MAP_X - 1;
		(*pos).y += B_Y;
	}
	return (map);
}

/*static void enemy_form(enemy_t *enemy)
{
	sfVector2f size = {60, 60};
	sfVector2f scale = {1.25, 1.25};

	enemy->form = sfSprite_create();
	enemy->rec.top = 64;
	enemy->rec.left = 0;
	enemy->rec.width = 64;
	enemy->rec.height = 64;
	sfSprite_setPosition(enemy->form, enemy->pos);
	enemy->img = sfTexture_createFromFile(
		"assets/champion/women_fer_knife.png", NULL);
	sfSprite_setTexture(enemy->form, enemy->img, true);
	sfSprite_setTextureRect(enemy->form, enemy->rec);
	sfSprite_setScale(enemy->form, scale);
	enemy->frame = sfRectangleShape_create();
	sfRectangleShape_setSize(enemy->frame, size);
	sfRectangleShape_setFillColor(enemy->frame, sfRed);
	sfRectangleShape_setOutlineColor(enemy->frame, sfBlack);
	sfRectangleShape_setOutlineThickness(enemy->frame, 3);
}

static fight_t *create_fight(void)
{
	fight_t *fight;

	fight = malloc(sizeof(fight_t));
	fight->pos.x = MAP_X - 1;
	fight->pos.y = MAP_Y - 1;
	create_map(fight);
	fight->number_enemy = 5;
	fight->curent = 0;
	fight->enemy_turn = false;
	return (fight);
}

static enemy_t *create_enemy(int nb, int n)
{
	enemy_t *enemy;

	enemy = malloc(sizeof(enemy_t));
	enemy->pos.x = 11 + n;
	enemy->pos.y = 0 + nb;
	enemy_form(enemy);
	enemy->played = false;
	enemy->alive = true;
	enemy->sword = false;
	enemy->hp = 20;
	enemy->dmg = 5;
	enemy->armor = 1;
	return (enemy);
}

void init_fight(battle_t *battle)
{
	battle->number_fight = 5;
	battle->fight = malloc (sizeof(fight_t *) * battle->number_fight);
	for (int i = 0; i < battle->number_fight; i++) {
		battle->fight[i] = create_fight();
		if (i == 1)
			battle->fight[i]->number_enemy = 2;
		if (i == 2)
			battle->fight[i]->number_enemy = 7;
		if (i == 3)
			battle->fight[i]->number_enemy = 10;
		if (i == 4)
			battle->fight[i]->number_enemy = 12;
		battle->fight[i]->enemy = malloc(sizeof(enemy_t *)
					* battle->fight[i]->number_enemy);
		for (int j = 0; j < battle->fight[i]->number_enemy; j++) {
			if (j > 9)
				battle->fight[i]->enemy[j] = create_enemy(j - 10, -1);
			else
				battle->fight[i]->enemy[j] = create_enemy(j, 0);
		}
	}
}*/

void configure_enemy_texture(rpg_t *rpg, enemy_t **enemy)
{
	sfVector2f size = { 60, 60 };
	sfVector2f scale = { 1.25, 1.25 };

	(*enemy)->rec.top = 64;
	(*enemy)->rec.left = 0;
	(*enemy)->rec.width = 64;
	(*enemy)->rec.height = 64;
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
}

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

void parse_enemy_values(rpg_t *rpg, config_setting_t *set, int id, int fight)
{
	enemy_t *enemy = malloc(sizeof(enemy_t));
	config_setting_t *set_pos = NULL;

	if (enemy == NULL)
		return;
	config_setting_lookup_string(set, "texture", \
	((const char **)&enemy->stuff));
	config_setting_lookup_int(set, "damage", &enemy->dmg);
	config_setting_lookup_int(set, "armor", &enemy->armor);
	config_setting_lookup_bool(set, "sword", ((int *)&enemy->sword));
	config_setting_lookup_int(set, "heal", &enemy->hp);
	enemy->played = false;
	enemy->alive = true;
	configure_enemy_texture(rpg, &rpg->battle->fight[fight]->enemy[id]);
	set_pos = config_setting_lookup(set, "pos");
	if (set_pos == NULL)
		return;
	config_setting_lookup_float(set, "x", ((double *)&enemy->pos.x));
	config_setting_lookup_float(set, "y", ((double *)&enemy->pos.x));
	config_setting_lookup_int(set, "top", &enemy->rec.top);
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

int configure_battle_values(rpg_t *rpg)
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
