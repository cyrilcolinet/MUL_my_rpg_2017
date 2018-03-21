/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** str_functions functions
*/

# include "lizz.h"
# include "utils.h"

int lizz_strlen(char *str)
{
	int size = 0;

	if (!str)
		return (0);
	while (*str)
		str++, size++;
	return (size);
}

void lizz_print(int fd, char *text)
{
	int len = 0;

	if (fd < 0 || !text)
		return;
	len = lizz_strlen(text);
	write(fd, text, len);
}
