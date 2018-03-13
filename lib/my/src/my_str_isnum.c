/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** Check if string contains only sumeric characters
*/

# include <stdbool.h>
# include "my.h"

bool my_str_isnum(char *str)
{
	if (str[0] == '-') {
		str++;
	}
	while (*str) {
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}
