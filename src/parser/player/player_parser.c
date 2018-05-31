/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player_parser functions
*/

# include "rpg.h"

void load_saved_datas(config_setting_t *set, rpg_t *rpg)
{
	const char *name = NULL, *texture = NULL;

	config_setting_lookup_string(set, "name", &name);
	config_setting_lookup_string(set, "texture", &texture);
	config_setting_lookup_int(set, "level", &rpg->player->level);
	config_setting_lookup_int(set, "skills", &rpg->player->skills);
	config_setting_lookup_int(set, "sexe", &rpg->player->sexe);

	rpg->player->name = my_strdup(((char *) name));
	rpg->player->texture = get_texture(rpg, ((char *) texture));
}

bool player_parser(rpg_t *rpg, char *save_name)
{
	conf_sett_t conf = parse_save_file(rpg, save_name, "save");

	if (conf.error || conf.set == NULL)
		return (false);

	rpg->player = malloc(sizeof(player_t));
	if (rpg->player == NULL)
		return (false);
	rpg->player->name = my_strconfigure(19);
	if (rpg->player->name == NULL)
		return (false);

	load_saved_datas(conf.set, rpg);
	config_destroy(&conf.cfg);
	return (true);
}
