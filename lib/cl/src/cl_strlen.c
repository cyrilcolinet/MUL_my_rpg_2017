/*
** EPITECH PROJECT, 2018
** lib cl
** File description:
** strlen
*/

#include "cl.h"

uint64_t cl_strlen(char const *str)
{
	uint64_t len = 0;

	CHECK_DO(str == NULL, return 0;)
	while (str[len] != '\0' && len < UINT_MAX)
		len++;
	return len;
}