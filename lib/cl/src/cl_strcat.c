/*
** EPITECH PROJECT, 2018
** lib cl
** File description:
** strcat
*/

#include "cl.h"

void cl_strcat(char **str1, char **str2)
{
	char *concat = NULL;
	uint64_t len = 0;

	CHECK_DO(str1 == NULL || str2 == NULL, return;)
	len += cl_strlen(*str1) + cl_strlen(*str2);
	concat = cl_calloc(sizeof(char) * (len + 1));
	CHECK_DO(concat == NULL, return;)
	for (uint64_t i = 0; i < cl_strlen(*str1); i++)
		concat[i] = *(*str1 + i);
	for (uint64_t i = cl_strlen(*str1); i < len; i++)
		concat[i] = *(*str2 + (i - cl_strlen(*str1)));
	free(*str1);
	if (*str1 != *str2)
		free(*str2);
	*str2 = NULL;
	*str1 = concat;
}