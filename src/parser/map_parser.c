/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map_parser functions
*/

# include "rpg.h"

int parse_map_hitboxes(char *file, rpg_t *rpg)
{
	int fd = -1;
	char *line = NULL;

	if (file == NULL)
		return (-1);

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);

	while ((line = get_next_line(fd)) != NULL) {
		printf("%s\n", line);
		free(line);
	}

	return (0);
}

int parse_arena_rectangle_values(config_setting_t *arena, interact_t **it)
{
	config_setting_t *rec = config_setting_lookup(arena, "rec");

	if (rec == NULL)
		return (-1);

	config_setting_lookup_int(rec, "top", &(*it)->rec.top);
	config_setting_lookup_int(rec, "left", &(*it)->rec.left);
	config_setting_lookup_int(rec, "width", &(*it)->rec.width);
	config_setting_lookup_int(rec, "height", &(*it)->rec.height);

	return (0);
}

int parse_arenas_values(rpg_t *rpg, interact_t **it, config_setting_t *set)
{
	config_setting_t *arenas = config_setting_lookup(set, "arenas");
	config_setting_t *arena = NULL;
	int count = 0;

	if (arenas == NULL)
		return (-1);

	count = config_setting_length(arenas);
	for (int i = 0; count > 0 && i < count; i++) {
		arena = config_setting_get_elem(arenas, i);
		if (arena == NULL)
			return (-1);
		config_setting_lookup_string(arena, "message", \
		((const char **)&(*it)->msg));
		if (parse_arena_rectangle_values(arena, it) != 0)
			return (-1);
	}

	return (0);
}

int parse_map_values(rpg_t *rpg, config_setting_t *set, int key)
{
	char *hit = NULL;

	if (rpg->map == NULL)
		return (-1);
	rpg->map[key] = malloc(sizeof(map_t));
	if (rpg->map[key] == NULL)
		return (-1);
	rpg->map[key]->interaction = malloc(sizeof(interact_t));
	if (rpg->map[key]->interaction == NULL)
		return (-1);

	config_setting_lookup_string(set, "hitboxes", ((const char **)&hit));
	config_setting_lookup_string(set, "map", \
	((const char **)&rpg->map[key]->texture));
	if (parse_map_hitboxes(hit, rpg) != 0)
		return (-1);
	if (parse_arenas_values(rpg, &rpg->map[key]->interaction, set) != 0)
		return (-1);

	return (0);
}

int parse_map(rpg_t *rpg)
{
	config_setting_t *set = NULL, *mapset = NULL;
	int count = 0;

	set = parse_file(rpg, "maps/maps.cfg", "maps");
	if (set == NULL)
		return (-1);

	count = config_setting_length(set);
	rpg->map = malloc(sizeof(map_t *) * (count + 1));
	for (int i = 0; count > 0 && i < count; i++) {
		mapset = config_setting_get_elem(set, i);
		if (mapset == NULL || parse_map_values(rpg, mapset, i))
			return (-1);

	}

	rpg->map[count] = NULL;
	return (0);
}
