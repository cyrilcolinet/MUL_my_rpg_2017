/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main function
*/

# include "rpg.h"

int main(int ac, char **av, char **env)
{
	int res = 84;
	(void)ac;
	(void)av;

	if (*env == NULL)
		return (res);

	res = main_rpg();
	return (res);
}
