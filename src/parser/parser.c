/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parser functions
*/

# include "rpg.h"

config_setting_t *parse_file(rpg_t *rpg, char *file, char *cat)
{
	config_t cfg;
	config_setting_t *set = NULL;
	char *path = my_strjoin("config/", file);
	(void)rpg
;
	config_init(&cfg);
	if (!path || !config_read_file(&cfg, path)) {
		write(2, "Unable to parse configuration.\n", 31);
		config_destroy(&cfg);
		return (NULL);
	}

	set = config_lookup(&cfg, cat);
	if (set == NULL) {
		write(2, "Unable to lookup configuration.\n", 32);
		config_destroy(&cfg);
		return (NULL);
	}

	return (set);
}
