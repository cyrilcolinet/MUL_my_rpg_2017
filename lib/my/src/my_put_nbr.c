/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** Display number into the console
*/

# include "my.h"

int my_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int my_digit_count(int n)
{
	int result = 0;
	int begin = 1;

	while (begin == 1 || n != 0) {
		begin = 0;
		n = n / 10;
		result = result + 1;
	}
	return (result);
}

int my_power10(int n)
{
	int power = 1;
	power = 1;
	while (n > 1) {
		power = power * 10;
		n = n - 1;
	}
	return (power);
}

void my_put_nbr(int n)
{
	int is_neg = 0;
	int mod;
	int digit_count;
	int tmp;
	if (n < 0) {
		is_neg = 1;
		my_putchar('-');
	}
	if (n < -2147483647)
		digit_count = my_digit_count(my_abs(n + 1));
	else
		digit_count = my_digit_count(my_abs(n));
	while (digit_count > 0) {
		tmp = n / my_power10(digit_count);
		mod = tmp % 10;
		if (is_neg)
			mod = -mod;
		my_putchar('0' + mod);
		digit_count = digit_count - 1;
	}
}
