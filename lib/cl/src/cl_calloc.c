/*
** EPITECH PROJECT, 2018
** lib cl
** File description:
** calloc
*/

#include "cl.h"

void *cl_calloc(size_t size)
{
	void *ptr = NULL;
	uint8_t *tmp = NULL;

	CHECK_DO(size == 0, return NULL;)
	ptr = malloc(size);
	tmp = ptr;
	CHECK_DO(ptr == NULL, return NULL;)
	for (unsigned int i = 0; i < size; i++)
		*(tmp + i) = 0;
	return ptr;
}