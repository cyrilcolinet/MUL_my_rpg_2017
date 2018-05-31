/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parser functions
*/

# include "rpg.h"

conf_sett_t parse_file(rpg_t *rpg, char *file, char *cat)
{
	conf_sett_t conf;
	char *path = my_strjoin("config/", file);

	config_init(&conf.cfg);
	conf.error = false;
	if (!path || !config_read_file(&conf.cfg, path)) {
		write(2, "Unable to parse configuration.\n", 31);
		config_destroy(&conf.cfg);
		free(path);
		conf.error = true;
		return conf;
	}
	free(path);
	conf.set = config_lookup(&conf.cfg, cat);
	if (conf.set == NULL) {
		config_destroy(&conf.cfg);
		conf.error = true;
		return conf;
	}
	return (conf);
}

conf_sett_t parse_save_file(rpg_t *rpg, char *file, char *cat)
{
	conf_sett_t conf;
	char *path = my_strjoin("saves/", file);

	config_init(&conf.cfg);
	conf.error = false;
	if (!path || !config_read_file(&conf.cfg, path)) {
		write(2, "Unable to parse save file.\n", 31);
		config_destroy(&conf.cfg);
		free(path);
		conf.error = true;
		return conf;
	}
	free(path);
	conf.set = config_lookup(&conf.cfg, cat);
	if (conf.set == NULL) {
		config_destroy(&conf.cfg);
		conf.error = true;
		return conf;
	}
	return (conf);
}
