/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** Duplicate once
*/

# include "my.h"

char *my_strdup(char *str)
{
	int size = my_strlen(str) + 1;
	char *new_str = my_strconfigure(size);

	my_strcpy(new_str, str);
	return (new_str);
}
