/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** save_loader functions
*/

# include "rpg.h"

void parse_save_infos(rpg_t *rpg, save_t **node, char *name)
{
	const char *pname = NULL;
	conf_sett_t conf = parse_save_file(rpg, name, "save");

	if (conf.error || conf.set == NULL)
		return;

	config_setting_lookup_int(conf.set, "level", &(*node)->level);
	config_setting_lookup_string(conf.set, "player_name", &pname);

	(*node)->player_name = my_strdup(((char *)pname));
}

void get_saves_infos(rpg_t *rpg, save_t **save, dir_t *dir)
{
	save_t *tmp = *save;

	while (tmp)
		tmp = tmp->next;
	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
		return;

	parse_save_infos(rpg, &tmp, dir->d_name);
	tmp->next = NULL;
}

bool save_loader(rpg_t *rpg, int start)
{
	DIR *o_dir = opendir("saves");
	dir_t *dir = NULL;
	save_t *save = NULL;
	int key = 0;

	if (o_dir == NULL)
		return (false);
	while ((dir = readdir(o_dir)) != NULL) {
		if (key < start)
			continue;
		get_saves_infos(rpg, &save, dir);
	}

	return (true);
}
