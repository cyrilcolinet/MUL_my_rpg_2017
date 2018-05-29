/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parse_map_hitboxes functions
*/

# include "rpg.h"

void fill_int_array(int **layer, int fd)
{
	int i = -1;
	char *line = NULL;

	while ((line = get_next_line(fd)) != NULL) {
		layer[++i] = malloc(sizeof(int) * 240);
		if (layer[i] == NULL)
			return;

		for (int id = 0; id < 240; id++) {
			layer[i][id] = line[id] - '0';
		}
		free(line);
	}
}

int **parse_map_hitboxes(char *file)
{
	int fd = -1;
	int **layer = NULL;

	if (file == NULL)
		return NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return NULL;

	layer = malloc(sizeof(int *) * 137);
	if (layer == NULL)
		return NULL;

	fill_int_array(layer, fd);
	layer[136] = NULL;
	close(fd);

	return layer;
}
