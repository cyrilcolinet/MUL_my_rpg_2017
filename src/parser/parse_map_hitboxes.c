/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parse_map_hitboxes functions
*/

# include "rpg.h"

void fill_int_array(map_t *map, int fd)
{
	int i = -1;
	char *line = NULL;

	while ((line = get_next_line(fd)) != NULL) {
		map->h_layer[++i] = malloc(sizeof(int) * 60);
		if (map->h_layer[i] == NULL)
			return;

		for (int id = 0; id < 60; id++) {
			map->h_layer[i][id] = line[id] - '0';
		}
		free(line);
	}
}

int parse_map_hitboxes(char *file, map_t *map)
{
	int fd = -1;

	if (file == NULL)
		return (-1);

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);

	map->h_layer = malloc(sizeof(int *) * 35);
	if (map->h_layer == NULL)
		return (-1);

	fill_int_array(map, fd);
	map->h_layer[34] = NULL;
	close(fd);

	return (0);
}
