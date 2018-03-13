/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** Get the length of a string
*/

# include "my.h"

int my_strlen(char *str)
{
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return (length);
}
