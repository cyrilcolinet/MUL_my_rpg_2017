/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** clock_managers functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static clk_t *set_functions(clk_t *clk)
{
	clk->restart = &lizz_clock_restart;
	clk->destroy = &lizz_clock_destroy;

	lizz_info("Clock \"");
	lizz_print(1, clk->name);
	lizz_print(1, "\" created.\n");

	return (clk);
}

static void fill_node_values(clk_t *node, clk_t values)
{
	node->name = values.name;
	node->clock = sfClock_create();
	if (node->clock == NULL) {
		lizz_error("Error during creation of clock.\n");
	}

	node = set_functions(node);
	node->next = NULL;
}

static bool new_clk_node(lizz_t *st, clk_t values)
{
	clk_t **clks = &st->clock;
	clk_t *node = NULL;

	if (st->clock == NULL) {
		node = malloc(sizeof(clk_t));
		fill_node_values(node, values);
		node->next = *clks;
		*clks = node;
		return (true);
	}

	node = st->clock;
	while (node->next != NULL)
		node = node->next;

	node->next = malloc(sizeof(clk_t));
	if (node->next == NULL)
		return (false);
	fill_node_values(node->next, values);
	return (true);
}

/*
** Creation d'une nouvelle clock
** @param (char *name) - Nom/ID de la clock
** @return (int) - Retourne -1 s'il y a erreur, et 0 si non
*/
int lizz_clock_create(lizz_t *st, char *name)
{
	clk_t clk;

	if (!name || lizz_strlen(name) == 0) {
		lizz_error("name must be not empty.\n");
		return (-1);
	}

	clk.name = name;
	if (!new_clk_node(st, clk))
		return (-1);

	return (0);
}

/*
** Récupérere unen clock par son nom
** @param (char *name) - Nom de la clock
** @return (clk_t) - Retourne NULL si clock non trouvée, et retourne
** la clock trouvée autrement
*/
clk_t *lizz_get_clock(lizz_t *st, char *name)
{
	clk_t *tmp = st->clock;

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
