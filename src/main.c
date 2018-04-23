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

	if (*env == NULL)
		return (res);

	res = rpg_main(ac, av);
	return (res);
}
