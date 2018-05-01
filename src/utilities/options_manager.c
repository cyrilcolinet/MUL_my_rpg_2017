/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** options_manager functions
*/

# include "cook.h"

char *my_itoa(int nb)
{
	int len = 0;
	int tmp = nb;
	char *str = NULL;

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

char *get_sound_in_str(int nb)
{
	char *number = NULL;
	char *ret = NULL;
	char *ptr = NULL;
	int len = 0;

	if (nb <= 0)
		return "0%";

	number = my_itoa(nb);
	len = my_strlen(number);
	ret = my_strconfigure(len + 1);
	my_strcpy(ret, number);
	ret[len] = '%';
	ret[len + 1] = 0;
	ptr = my_strdup(ret);
	free(number);
	free(ret);

	return (ptr);
}
