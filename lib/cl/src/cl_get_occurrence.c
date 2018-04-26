/*
** EPITECH PROJECT, 2018
** lib cl
** File description:
** get occurrence
*/

#include "cl.h"

uint64_t cl_get_occurrence(char c, char const *str)
{
	uint64_t occurrence = 0;

	CHECK_DO(str == NULL, return 0;)
	for (uint64_t i = 0; i < cl_strlen(str); i++)
		if (str[i] == c)
			occurrence++;
	return occurrence;
}