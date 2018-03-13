/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_strjoin function
*/

# include <stdlib.h>
# include "my.h"

char *my_strjoin(char *str1, char *str2)
{
	char  *str;

	if (!str1 || !str2)
		return (NULL);

	str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
	if (str == NULL)
		return (NULL);
	my_strcpy(str, str1);
	my_strcat(str, str2);
	return (str);
}
