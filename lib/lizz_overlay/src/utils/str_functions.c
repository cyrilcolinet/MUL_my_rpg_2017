/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** str_functions functions
*/

# include "debug.h"
# include "lizz.h"
# include "utils.h"

char *lizz_strconfigure(size_t size)
{
	char *ptr;
	size_t i = 0;

	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);

	while (i < size + 1)
		*(ptr + i++) = 0;

	return (ptr);
}

char *lizz_itoa(int num)
{
	int len = ((num == 0) ? 1 : 0);
	int tmp = num;
	char *ptr = NULL;

	while (tmp > 0) {
		tmp /= 10;
		len++;
	}

	ptr = lizz_strconfigure(len);
	if (!ptr)
		return (NULL);

	while (len--) {
		ptr[len] = num % 10 + '0';
		num /= 10;
	}

	return (ptr);
}

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
	if (_debug) {
		int len = 0;

		if (fd < 0)
			return;

		if (text) {
			len = lizz_strlen(text);
			write(fd, text, len);
		} else {
			write(fd, "(null)", 6);
		}
	}
}
