/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map_parser functions
*/

# include "rpg.h"

int parse_arena_rectangle_values(config_setting_t *arena, interact_t **it)
{
	config_setting_t *rec = config_setting_lookup(arena, "rec");
	sfIntRect rect = { 0, 0, 0, 0 };

	if (rec == NULL)
		return (-1);

	config_setting_lookup_int(rec, "top", &rect.top);
	config_setting_lookup_int(rec, "left", &rect.left);
	config_setting_lookup_int(rec, "width", &rect.width);
	config_setting_lookup_int(rec, "height", &rect.height);
	(*it)->rec.top = rect.top;
	(*it)->rec.left = rect.left;
	(*it)->rec.width = rect.width;
	(*it)->rec.height = rect.height;

	return (0);
}

int parse_arenas_interactions(interact_t **it, config_setting_t *set)
{
	char *msg = NULL;

	config_setting_lookup_string(set, "message", \
	((const char **)&msg));
	if (parse_arena_rectangle_values(set, it) != 0)
		return (-1);
	(*it)->msg = my_strdup(msg);
	(*it)->in_zone = false;
	(*it)->active = false;
	return (0);
}

int parse_arenas_values(map_t **map, config_setting_t *set)
{
	config_setting_t *arenas = config_setting_lookup(set, "arenas");
	config_setting_t *arena = NULL;
	int count = 0;

	if (arenas == NULL)
		return (-1);
	count = config_setting_length(arenas);
	if (((*map)->it = malloc(sizeof(interact_t *) * (count + 1))) == NULL)
		return (-1);
	for (int i = 0; count > 0 && i < count; i++) {
		arena = config_setting_get_elem(arenas, i);
		if (arena == NULL)
			return (-1);
		if (((*map)->it[i] = malloc(sizeof(interact_t))) == NULL)
			return (-1);
		if (parse_arenas_interactions(&(*map)->it[i], arena) != 0)
			return (-1);
	}
	(*map)->it[count] = NULL;
	return (0);
}

int parse_map_values(rpg_t *rpg, config_setting_t *set, int key)
{
	char *hit = NULL, *texture = NULL;

	if (rpg->map == NULL)
		return (-1);
	rpg->map[key] = malloc(sizeof(map_t));
	if (rpg->map[key] == NULL)
		return (-1);

	config_setting_lookup_string(set, "hitboxes", ((const char **)&hit));
	config_setting_lookup_string(set, "texture", \
	((const char **)&texture));
	rpg->map[key]->layer = parse_map_hitboxes(my_strdup(hit));
	if (rpg->map[key]->layer == NULL)
		return (-1);
	if (parse_arenas_values(&rpg->map[key], set) != 0)
		return (-1);
	rpg->map[key]->texture = my_strdup(texture);
	return (0);
}

int parse_map(rpg_t *rpg)
{
	conf_sett_t conf = parse_file(rpg, "maps/maps.cfg", "maps");
	config_setting_t *mapset = NULL;
	int count = 0;

	if (conf.error || conf.set == NULL)
		return (-1);
	count = config_setting_length(conf.set);
	rpg->map = malloc(sizeof(map_t *) * (count + 1));
	for (int i = 0; count > 0 && i < count; i++) {
		mapset = config_setting_get_elem(conf.set, i);
		if (mapset == NULL || parse_map_values(rpg, mapset, i))
			return (-1);

	}

	rpg->map[count] = NULL;
	config_destroy(&conf.cfg);
	return (0);
}
