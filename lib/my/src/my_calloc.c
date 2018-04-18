/*
** EPITECH PROJECT, 2018
** lib my
** File description:
** my calloc
*/

#include "my.h"

void *my_calloc(size_t size)
{
	void *ptr = NULL;
	u_int8_t *tmp = NULL;

	CHECK_DO(size == 0, return NULL;)
	ptr = malloc(size);
	tmp = ptr;
	CHECK_DO(ptr == NULL, return NULL;)
	for (unsigned int i = 0; i < size; i++)
		*(tmp + i) = 0;
	return ptr;
}