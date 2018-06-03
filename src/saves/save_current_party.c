/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** save_current_party functions
*/

# include "rpg.h"

/*
static const char *output_file = "newconfig.cfg";
config_t cfg;
config_setting_t *root, *setting, *group, *array;
int i;

config_init(&cfg);
root = config_root_setting(&cfg);

group = config_setting_add(root, "address", CONFIG_TYPE_GROUP);

setting = config_setting_add(group, "street", CONFIG_TYPE_STRING);
config_setting_set_string(setting, "1 Woz Way");

setting = config_setting_add(group, "city", CONFIG_TYPE_STRING);
config_setting_set_string(setting, "San Jose");

setting = config_setting_add(group, "state", CONFIG_TYPE_STRING);
config_setting_set_string(setting, "CA");

setting = config_setting_add(group, "zip", CONFIG_TYPE_INT);
config_setting_set_int(setting, 95110);

array = config_setting_add(root, "numbers", CONFIG_TYPE_ARRAY);

for (i = 0; i < 10; ++i)
{
setting = config_setting_add(array, NULL, CONFIG_TYPE_INT);
config_setting_set_int(setting, 10 * i);
}

if (! config_write_file(&cfg, output_file))
{
fprintf(stderr, "Error while writing file.\n");
config_destroy(&cfg);
return (EXIT_FAILURE);
}

fprintf(stderr, "New configuration successfully written to: %s\n",
output_file);

config_destroy(&cfg);
return (EXIT_SUCCESS);
*/

void set_player_value(rpg_t *rpg, config_setting_t *save)
{
	config_setting_t *set = NULL;

	set = config_setting_add(save, "name", CONFIG_TYPE_STRING);
	config_setting_set_string(set, rpg->player->name);
	set = config_setting_add(save, "hero_texture", CONFIG_TYPE_STRING);
	config_setting_set_string(set, "man_no_nu");
	set = config_setting_add(save, "sexe", CONFIG_TYPE_INT);
	config_setting_set_int(set, rpg->player->sexe);
	set = config_setting_add(save, "level", CONFIG_TYPE_INT);
	config_setting_set_int(set, rpg->player->level);
	set = config_setting_add(save, "heal", CONFIG_TYPE_INT);
	config_setting_set_int(set, rpg->battle->hero->hp);
	set = config_setting_add(save, "damage", CONFIG_TYPE_INT);
	config_setting_set_int(set, rpg->battle->hero->dmg);
	set = config_setting_add(save, "armor", CONFIG_TYPE_INT);
	config_setting_set_int(set, rpg->battle->hero->armor);
	set = config_setting_add(save, "skills", CONFIG_TYPE_INT);
	config_setting_set_int(set, rpg->player->skills);
	set = config_setting_add(save, "sword", CONFIG_TYPE_BOOL);
	config_setting_set_bool(set, rpg->battle->hero->sword);
}

void save_current_party(rpg_t *rpg)
{
	config_t cfg;
	config_setting_t *root = NULL, *save = NULL, *set = NULL;

	config_init(&cfg);
	root = config_root_setting(&cfg);
	save = config_setting_add(root, "save", CONFIG_TYPE_GROUP);

	if (!config_write_file(&cfg, filename)) {
		config_destroy(&cfg);
		return;
	}

	config_destroy(&cfg);
}
