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
		map->layer[++i] = malloc(sizeof(int) * 240);
		if (map->layer[i] == NULL)
			return;

		for (int id = 0; id < 240; id++) {
			map->layer[i][id] = line[id] - '0';
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

	map->layer = malloc(sizeof(int *) * 137);
	if (map->layer == NULL)
		return (-1);

	fill_int_array(map, fd);
	map->layer[136] = NULL;
	close(fd);

	return (0);
}
