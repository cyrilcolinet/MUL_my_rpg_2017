/*
** EPITECH PROJECT, 2018
** lib cl
** File description:
** strchr
*/

#include "cl.h"

uint64_t cl_strchr(char c, char const *str, uint64_t which)
{
	uint64_t offset = 0;

	CHECK_DO(!cl_is_in_str(c, str), return 0;)
	if (which > cl_get_occurrence(c, str))
		which = cl_get_occurrence(c, str);
	for (unsigned int i = 0; i < cl_strlen(str); i++) {
		if (str[i] == c)
			offset++;
		if (offset == which)
			return i;
	}
	return 0;
}