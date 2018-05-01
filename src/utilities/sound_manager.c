/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** sount_manager functions
*/

# include "cook.h"

void configure_audio(cook_t *cook)
{
	cook->sound = sfSound_create();

	if (cook->sound == NULL) {
		warning("Sound equals to (null) !");
		return;
	}

	info("Sound create and ready to use.");
}
