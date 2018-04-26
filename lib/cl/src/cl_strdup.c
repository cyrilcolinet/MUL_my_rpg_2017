/*
** EPITECH PROJECT, 2018
** lib cl
** File description:
** cl strdup
*/

#include "cl.h"

char *cl_strdup(char const *str)
{
	char *dup = NULL;

	CHECK_DO(str == NULL, return NULL;)
	dup = cl_calloc(sizeof(char) * (cl_strlen(str) + 1));
	CHECK_DO(dup == NULL, return NULL;)
	for (uint64_t i = 0; i < cl_strlen(str); i++)
		dup[i] = str[i];
	return dup;
}