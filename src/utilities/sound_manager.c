/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sount_manager functions
*/

# include "rpg.h"

void configure_audio(rpg_t *rpg)
{
	rpg->sound = sfSound_create();

	if (rpg->sound == NULL) {
		warning("Sound equals to (null) !");
		return;
	}

	info("Sound create and ready to use.");
}
