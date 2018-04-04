/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_str_configure function
*/

# include <stdlib.h>
# include "my.h"

char *my_strconfigure(unsigned int size)
{
	char *ptr;
	unsigned int i = 0;

	if (!size)
		return (NULL);

	ptr = malloc(sizeof(char) * (size + 1));

	if (ptr == NULL)
		return (NULL);

	while (i < size + 1)
		*(ptr + i++) = 0;

	return (ptr);
}