/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** clock_managers functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static clk_t *new_clk_node(void)
{
	clk_t **tmp = &lizz->clock;

	while (*tmp != NULL)
		*tmp = (*tmp)->next;

	*tmp = malloc(sizeof(clk_t));

	if (*tmp == NULL) {
		lizz_error("Unable to alloc clk_t: Out of memory.\n");
		return (NULL);
	}

	return (*tmp);
}

/*
** Creation d'une nouvelle clock
** @param (char *name) - Nom/ID de la clock
** @return (int) - Retourne -1 s'il y a erreur, et 0 si non
*/
int lizz_clock_create(char *name)
{
	clk_t *clk = NULL;

	if (!name || lizz_strlen(name) == 0) {
		lizz_error("name must be not empty.\n");
		return (-1);
	}
	clk = new_clk_node();
	if (!clk)
		return (-1);

	clk->name = name;
	clk->clock = sfClock_create();
	if (!clk->clock) {
		lizz_error("Error durint creation of clock");
		return (-1);
	}
	clk->destroy = &lizz_clock_destroy;
	clk->restart = &lizz_clock_restart;
	clk->next = NULL;

	return (0);
}

/*
** Récupérere unen clock par son nom
** @param (char *name) - Nom de la clock
** @return (clk_t) - Retourne NULL si clock non trouvée, et retourne
** la clock trouvée autrement
*/
clk_t *lizz_get_clock(char *name)
{
	clk_t *tmp = lizz->clock;

	while (tmp != NULL) {
		if (strcmp(tmp->name, name) == 0) { // TODO: Forbidden function
			return (tmp);
		}
		tmp = tmp->next;
	}

	lizz_error("Unable to found a clock named \"");
	lizz_print(2, name);
	lizz_print(2, "\"\n");
	return (NULL);
}
