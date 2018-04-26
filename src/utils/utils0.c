/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** utils 0
*/

#include "rpg.h"

char *tricat(char const *str1, char const *str2, char const *str3)
{
	uint64_t len = 0;
	char *str = NULL;

	len = cl_strlen(str1) + cl_strlen(str2) + cl_strlen(str3);
	str = cl_calloc(sizeof(char) * (len + 1));
	for (uint64_t i = 0; i < cl_strlen(str1); i++)
		str[i] = str1[i];
	for (uint64_t i = 0; i < cl_strlen(str2); i++)
		str[i + cl_strlen(str1)] = str2[i];
	for (uint64_t i = 0; i < cl_strlen(str3); i++)
		str[i + cl_strlen(str1) + cl_strlen(str2)] = str3[i];
	return str;
}