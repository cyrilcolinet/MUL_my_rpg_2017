/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_strjoin_clear function
*/

# include <stdlib.h>
# include "my.h"

char *my_strjoin_clear(char *str1, char *str2, int free_both)
{
	char *new = my_strjoin(str1, str2);

	if (new == NULL)
		return (NULL);

	free(str1);
	str1 = NULL;

	if (free_both) {
		free(str2);
		str2 = NULL;
	}

	return (new);
}