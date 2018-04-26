/*
** EPITECH PROJECT, 2018
** lib cl
** File description:
** str cmp
*/

#include "cl.h"

bool cl_str_cmp(char const *str1, char const *str2)
{
	CHECK_DO((cl_strlen(str1) - cl_strlen(str2)) != 0, return false;)
	for (uint64_t i = 0; i < cl_strlen(str1); i++)
		if (str1[i] != str2[i])
			return false;
	return true;
}