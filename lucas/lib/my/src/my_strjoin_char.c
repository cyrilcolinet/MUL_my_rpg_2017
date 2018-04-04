/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_strjoin_char function
*/

# include <stdlib.h>
# include "my.h"

char *my_strjoin_char(char *str, char delim)
{
	char *new;
	size_t i = 0;
	size_t str_len = 0;

	if (str == NULL || !delim)
		return (NULL);

	str_len = my_strlen(str);
	new = my_strconfigure(str_len + 1);

	if (new == NULL)
		return (NULL);

	while (i < str_len) {
		*(new + i) = *(str + i);
		i++;
	}
	*(new + i) = delim;
	return (new);
}