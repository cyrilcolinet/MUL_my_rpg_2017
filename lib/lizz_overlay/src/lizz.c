/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lizz functions
*/

# include "debug.h"
# include "lizz.h"

static bool configure(lizz_t **conf)
{
	*conf = malloc(sizeof(lizz_t));

	if (*conf == NULL) {
		lizz_error("Unable to alloc lizz_t: Out of memory.\n");
		return (NULL);
	}

	(*conf)->btn = NULL;
	(*conf)->thread = NULL;
	(*conf)->menus = NULL;
	(*conf)->clock = NULL;

	return (conf);
}

/*
** Start LiZz CSFML Overlay
** @prarm (bool debug) - Mettre cette valeur à "true" si vous
** voulez activer le debug mode.
** @return (int) - Retourne -1 s'il y a une erreur et 0 si non.
*/
int lizz_start(lizz_t **st, bool debug)
{
	_debug = debug;

	if (!configure(st))
		return (-1);

	lizz_info("Debug mode enabled.\n");
	return (0);
}

/*
** Stoppe et détruit tout les objets instanciés, et ferme l'Overlay
** @return (void)
*/
void lizz_stop(lizz_t *lizz)
{
	lizz_destroy_all(lizz);
	free(lizz->btn);
	free(lizz);
}
