/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_strendswith function
*/

# include <stdbool.h>
# include "my.h"

bool my_strendswith(char *str1, char *str2)
{
	int i = 0;

	while (str1[i]) {
		if (str1[i] == *str2)
			if (my_strcmp(str1 + i, str2) == 0)
				return (true);
		i++;
	}

	return (false);
}