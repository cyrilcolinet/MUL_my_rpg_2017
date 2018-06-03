/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player_parser functions
*/

# include "rpg.h"

bool player_parser(rpg_t *rpg, char *save_name)
{
	conf_sett_t conf = parse_save_file(rpg, save_name, "save");

	if (conf.error || conf.set == NULL)
		return (false);

	rpg->player = malloc(sizeof(player_t));
	rpg->battle->hero = malloc(sizeof(hero_t));
	if (!rpg->player || !rpg->battle->hero)
		return (false);
	rpg->player->name = my_strconfigure(19);
	if (rpg->player->name == NULL)
		return (false);

	load_player_datas(conf.set, rpg);
	load_hero_datas(conf.set, rpg);
	load_hero_spells_icons(rpg);
	load_player_inventory(rpg);
	load_player_equipment(rpg, rpg->player->inventory);
	config_destroy(&conf.cfg);
	return (true);
}
