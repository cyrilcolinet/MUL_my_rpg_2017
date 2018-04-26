/*
** EPITECH PROJECT, 2018
** lib cl
** File description:
** header
*/

#ifndef _CL_H
#define _CL_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif

#ifndef _STDDEF_H
#include <stddef.h>
#endif

#ifndef _STDINT_H
#include <stdint.h>
#endif

#ifndef _UNISTD_H
#include <unistd.h>
#endif

#ifndef _FCNTL_H
#include <fcntl.h>
#endif

#ifndef _LIMITS_H
#include <limits.h>
#endif

#ifndef _ERRNO_H
#include <errno.h>
#endif

#undef CL_ERROR_CODE
#define CL_ERROR_CODE 84
#undef CHECK_DO
#define CHECK_DO(to_check, to_do) if (to_check) {to_do}

void *cl_calloc(size_t size);
uint64_t cl_get_occurrence(char c, char const *str);
bool cl_is_in_str(char c, char const *str);
bool cl_str_cmp(char const *str1, char const *str2);
void cl_strcat(char **str1, char **str2);
uint64_t cl_strchr(char c, char const *str, uint64_t which);
char *cl_strdup(char const *str);
uint64_t cl_strlen(char const *str);

#endif