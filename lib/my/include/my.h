/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** My personnal library header
*/

# ifndef MY_H_
# define MY_H_

# ifndef READ_SIZE
# define READ_SIZE (128)
# endif

# undef CHECK_DO
# define CHECK_DO(to_check, to_do) if (to_check) {to_do}

# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

/**
** Check if number is negative or  positive
** @param (int) nb
** @return (int) - 1 if positive and 0 otherwise
**/
int my_isneg(int nb);

/**
** Converts string into number
** @param (char *) str
** @return (int) result
**/
int my_atoi(char *str);

/**
** Print number into console
** @param (int) nb
** @return (void) - Return 0
**/
void my_put_nbr(int nb);

/**
** Swap two numbers with pointers
** @param (int) *a
** @param (int) *b
** @return (int) - Return 0
**/
void my_swap(int *a, int *b);

/**
** Print string into console
** @param (char const) *str
** @return (void) - Return 0
**/
void my_putstr(char *str);

/**
** Get the length of a string
** @param (char const) *str
** @return (int) - Return the length of a string
**/
int my_strlen(char *str);

/**
** Get first number (negative or positive) into a string
** @param (char const) *str
** @return (int) - Return the number finded into the screen or 0
**/
int my_getnbr(char *str);

/**
** Calculate the power of a numbre
** @param (int) nb
** @param (int) power
** @return (int) - Result of calculation
**/
int my_compute_power_rec(int nb, int power);

/**
** Claculate the square root of a number
** @param (int) nb
** @return (int) - Result of calculation
**/
int my_compute_square_root(int nb);

/**
** Check if number is prime or not
** @param (int) nb
** @return (int) - Return 1 if the number is prime, and 0 otherwise
**/
int my_is_prime(int nb);

/**
** Find the closest prime number
** @param (int) nb
** @return (int) - Return nb if number is prime,
** nd otherwise, return the closest prime number
**/
int my_find_prime_sup(int nb);

/**
** Compare two strings
** @param (char const) *s1
** @param (char const) *s2
** @return (int) - Return 1 if the two strings equals, and 0 otherwise
**/
int my_strcmp(char *s1, char *s2);

/**
** Compare n characters of two strings
** @param (char const) *s1
** @param (char const) *s2
** @return (int) - Return 1 if the n characters of the two strings equals,
** and 0 otherwise
**/
int my_strncmp(char *s1, char *s2, int n);

/**
** Check if string is composed to ONLY alphanumerics characters
** @param (char const) *str
** @return (int) - Return 1 if the string contains only
** alphanumeric characters, and 0 otherwise
**/
int my_str_isalpha(char *str);

/**
** Count delimer parts
** @param (char *) str
** @param (char *) delim
** @return (int) - Return the count of parts delimter by a delimier
** specified in argument...
**/
int my_countwords(char *str, char delim);

/**
** Check if string contains ONLY numeric characters
** @param (char const) *str
** @param (bool) neg
** @return (int) - Return 1 if the string contains only
** numeric characters, and 0 otherwise
**/
bool my_str_isnum(char *str);

/**
** Check if the string contains only lowercase characters
** @param (char const) *str
** @return (int) - Return 1 if the string contains only
** lowercase characters, and 0 otherwise
**/
int my_str_islower(char *str);

/**
** Check if the string contains only uppercase characters
** @param (char const) *str
** @return (int) - Return 1 if the string contains only
** uppercase characters, and 0 otherwise
**/
int my_str_isupper(char *str);

/**
** Check if the string can be printable in the console
** @param (char const) *str
** @return (int) - Return 1 if the string is printable and 0 otherwise
**/
int my_str_isprintable(char *str);

/**
** Print string (hexa/char)
** @param (char const) *str
** @return (int) - Return 0. If the string contains non-printable
** characters, must be printed hexadecimally (in lowercase letters)
**/
void my_showstr(char *str);

/**
** Print memory dump
** @param (char const) *str
** @param (int) size
** @return (int) - Return 0
**/
void my_showmem(char *str, int size);

/**
** Copy string into another
** @param (char) *dest
** @param (char const) *src
** @return (char) - The copied string
**/
char *my_strcpy(char *dest, char *src);

/**
** Copy n characters of string into another
** @param (char) *dest
** @param (char const) *src
** @param (int) n
** @return (char) - Return the n characters copied string into another
**/
char *my_strncpy(char *dest, char *src, int n);

/**
** Reverse string
** @param (char) *str
** @return (char) - Return the reverted string
**/
char *my_revstr(char *str);

/**
** Find the first occurence ofthe substring  to_find in the string str.
** The terminated '\0'
** characters are not compared.
** @param (char const) *str
** @param (char const) *to_find
** @return (char) - Return pointer to the first occurence in str
** of ony of the entire sequence of characters specified id to_find,
** or a null pointer if teh sequence is not present in str.
**/
char *my_strstr(char *str, char *to_find);

/**
** Transform all lowercases letters into capital letters
** @param (char) *str
** @return (char) - Return string with only uppercase letters
**/
char *my_strupcase(char *str);

/**
** Tranform all uppercase letters into lowercase letters
** @param (char) *str
** @return (char) - Return string with only lowercase letters
**/
char *my_strlowcase(char *str);

/**
** Set the first letters of each words containing in a string
** @param (char) *str
** @return (char) - Return the string with all the first letters
** of each words in uppercase
**/
char *my_strcapitalize(char *str);

/**
** Concatenate string into only one string
** @param (char) *dest
** @param (char const) *src
** @return (char) - Return the concatenated string
**/
char *my_strcat(char *dest, char *src);

/**
** Concatenate n charactes of string into one string
** @param (char) *dest
** @param (char const) *src
** @param (int) n
** @return (char) - Return the concatenated string only the n characters)
**/
char *my_strncat(char *dest, char *src, int n);

/**
** Remove spaces present in a string
** TODO > Implements to library
** @param (char *) str
** @return (char) - Returns string without spaces
**/
char *my_trim(char *str);

/**
** Print only one character into console
** @param (char) c
** @return (void)
**/
void my_putchar(char c);

/**
** Sort integer array (in ascending order)
** @param (int) *array
** @param (int) size
** @return (void)
**/
void my_sort_int_array(int *array, int size);

/**
** Print error (on the stderr output)
** @param (char) *str
** @param (bool) close
** @return (void)
**/
void my_puterr(char *str, bool close);

/**
** Malloc own (exit wen malloc failed)
** @param (unsigned int) size
** @return (void) - Return malloced pointer
**/
void *my_malloc(unsigned int size);

/**
** Duplicate string
** @param (char) *str
** @return (char *)
**/
char *my_strdup(char *str);

/**
** Equivalent to split
** @param (char *) str
** @return (char **)
**/
char **my_str_to_word_array(char *str);

/**
** Cut string with delimiter given as parameter
** @param (char *) str
** @param (char) delim
** return (char **) - Return word array in double pointer char
**/
char **my_strtok(char *str, char delim);

/**
** Print number in defined base
** @param (int) nbr
** @param (char *) base
** @return (void)
**/
void my_put_nbr_base(int nbr, char *base);

/**
** Realloc char pointer
** @param (char *) ptr
** @param (unsigned int) size
** @return (char *) new_ptr
**/
char *my_realloc(void *ptr, size_t prev_size, size_t new_size);

/**
** Get the next line of file description
** @param (int) fdesc
** @return (char *) line
**/
char *my_getline(int fdesc);

/**
** Printf function recoded
** @param (char *) format
** @param (...) va_list <stdarg.h>
** @return (void)
**/
void my_printf(char *format, ...);

/**
** Free pointer
** @param (void) *ptr
**/
void my_free(void **ptr);

char *my_strconfigure(unsigned int size);

char *my_strjoin(char *str1, char *str2);

char *my_strjoin_clear(char *str1, char *str2, int free_both);

char *my_strjoin_char(char *str, char delim);

bool my_strstartswith(char *str1, char *str2);

bool my_strendswith(char *str1, char *str2);

char *my_strchr(char *str, char delim);

void my_freetab(char **arr);

bool my_strequ(char *str1, char *str2);

# endif
