/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_streq function
*/

# include <stdbool.h>
# include "my.h"

bool my_strequ(char *str1, char *str2)
{
	bool ret = false;

	if (str1 == NULL || str2 == NULL)
		return (false);

	if (my_strcmp(str1, str2) == 0)
		ret = true;

	return (ret);
}