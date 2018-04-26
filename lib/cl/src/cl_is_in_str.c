/*
** EPITECH PROJECT, 2018
** lib cl
** File description:
** is in str
*/

#include "cl.h"

bool cl_is_in_str(char c, char const *str)
{
	CHECK_DO(str == NULL, return false;)
	for (uint64_t i = 0; i < cl_strlen(str); i++)
		if (str[i] == c)
			return true;
	return false;
}