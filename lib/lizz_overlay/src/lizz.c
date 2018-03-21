/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lizz functions
*/

# include "debug.h"
# include "lizz.h"

lizz_t *lizz_configure(void)
{
	lizz_t *conf = malloc(sizeof(lizz_t));

	if (conf == NULL) {
		lizz_error("Unable to alloc lizz_t: Out of memory.\n");
		return (NULL);
	}

	conf->btn = malloc(sizeof(button_t));
	if (!conf->btn) {
		lizz_error("Unable to alloc button_t: Out of memory.\n");
		return (NULL);
	}

	return (conf);
}

int lizz_start(bool debug)
{
	_debug = debug;
	lizz = lizz_configure();

	if (!lizz)
		return (-1);

	lizz_info("Debug mode enabled.\n");
	return (0);
}

void lizz_stop(void)
{
	free(lizz->btn);
	free(lizz);
}
