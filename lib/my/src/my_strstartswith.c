/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_strstartswith
*/

# include <stdbool.h>
# include "my.h"

bool my_strstartswith(char *str1, char *str2)
{
	int i = 0;

	while (str2[i]) {
		if (str1[i] != str2[i])
			return (false);
		i++;
	}

	return (true);
}