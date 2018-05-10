/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** lib
*/

#include "rpg.h"

char *my_itoa(int nb)
{
	int len = 0;
	int tmp = nb;
	char *str = NULL;

	if (tmp == 0)
		len++;
	while (tmp > 0) {
		tmp /= 10;
		len++;
	}
	str = my_strconfigure(len);
	while (len--) {
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
