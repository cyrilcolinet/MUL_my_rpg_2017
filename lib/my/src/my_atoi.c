/*
** EPITECH PROJECT, 2017
** my_atoi
** File description:
** Convert string into number (int)
*/

# include "my.h"

int my_atoi(char *str)
{
	unsigned int i = 0;
	int number = 0;
	int neg = 0;

	if (!(str))
		return (0);
	if (str[0] == '-') {
		i = 1;
		neg = 1;
	} else if (str[0] == '+') {
		i = 1;
	}
	while (str[i] >= 48 && str[i] <= 57) {
		number *= 10;
		number += ((int)str[i] - 48);
		i++;
	}
	if (neg == 1)
		number = -number;
	return (number);
}
