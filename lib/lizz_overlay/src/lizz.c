/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lizz functions
*/

# include "debug.h"
# include "lizz.h"

lizz_t *lizz_configure(bool debug)
{
	lizz_t *conf = malloc(sizeof(lizz_t));

	if (!conf) {
		lizz_error("Unable to start lizz overlay. ");
		lizz_error("Reason: Out of memory.\n");
		return (NULL);
	}

	conf->debug = debug;
	conf->btn = malloc(sizeof(button_t));

	if (!conf->btn) {
		lizz_error("Unable to start lizz overlay. ");
		lizz_error("Reason: Out of memory.\n");
		return (NULL);
	}

	return (conf);
}

int lizz_start(bool debug)
{
	lizz = lizz_configure(debug);

	if (!lizz)
		return (-1);

	return (0);
}

void lizz_quit(void)
{
	free(lizz->btn);
	free(lizz);
}
