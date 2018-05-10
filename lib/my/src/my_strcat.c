/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** Concatenate two strings
*/

# include "my.h"

char *my_strcat(char *dest, char *src)
{
	unsigned int i = 0;
	unsigned int len = my_strlen(dest);

	while (src[i]) {
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}
