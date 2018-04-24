/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** struct_utils rpg
*/

# include "rpg.h"

void free_all(rpg_t *rpg)
{
	free(rpg);
}

rpg_t *initialize_struct(void)
{
	rpg_t *rpg = malloc(sizeof(rpg_t));

	if (rpg == NULL)
		return (NULL);

	rpg->lizz = NULL;

	return (rpg);
}
