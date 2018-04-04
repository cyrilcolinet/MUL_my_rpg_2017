/*
** EPITECH PROJECT, 2018
** library
** File description:
** count_delimiter_parts function
*/

# include <stdbool.h>
# include "my.h"

int my_countwords(char *str, char delim)
{
	int count = 0;
	int i = 0;

	while (str[i]) {
		while (str[i] == delim)
			i++;
		if (str[i] != delim && str[i])
			count++;
		while (str[i] != delim && str[i])
			i++;
	}
	return (count);
}