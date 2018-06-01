/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** load_player_datas functions
*/

# include "rpg.h"

sfVector2f load_saved_positions(config_setting_t *set, rpg_t *rpg, sfVector2f pos)
{
	config_setting_t *pos_conf = config_setting_lookup(set, "pos");
	double posx = pos.x;
	double posy = pos.y;
	sfVector2f ret_pos;

	if (pos_conf == NULL)
		return (pos);

	config_setting_lookup_int(pos_conf, "map", &rpg->map_id);
	config_setting_lookup_float(pos_conf, "pos_x", &posx);
	config_setting_lookup_float(pos_conf, "pos_y", &posy);
	ret_pos.x = posx;
	ret_pos.y = posy;

	return (ret_pos);
}

void load_player_datas(config_setting_t *set, rpg_t *rpg)
{
	const char *name = NULL;
	const char *texture = NULL;
	sfVector2f pos = { 48, 672 };
	sfIntRect rec = { 192, 0, 64, 64 };

	config_setting_lookup_string(set, "name", &name);
	config_setting_lookup_string(set, "texture", &texture);
	config_setting_lookup_int(set, "level", &rpg->player->level);
	config_setting_lookup_int(set, "skills", &rpg->player->skills);
	config_setting_lookup_int(set, "sexe", &rpg->player->sexe);
	pos = load_saved_positions(set, rpg, pos);

	rpg->player->clock = sfClock_create();
	rpg->player->name = my_strdup(((char *) name));
	rpg->player->texture = get_texture(rpg, ((char *) texture));
	rpg->player->rec = rec;
	rpg->player->sprite = sfSprite_create();
	sfSprite_setPosition(rpg->player->sprite, pos);
	sfSprite_setTexture(rpg->player->sprite, rpg->player->texture, true);
	sfSprite_setTextureRect(rpg->player->sprite, rec);
}
