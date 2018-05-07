/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sounds_manager functions
*/

# include "rpg.h"

static void fill_values(sound_t *node, char *name, char *file)
{
	node->name = name;
	node->file = file;
	node->buffer = sfSoundBuffer_createFromFile(file);
	if (node->buffer == NULL)
		return;
	node->sound = sfSound_create();
	sfSound_setBuffer(node->sound, node->buffer);
	node->next = NULL;
}

int new_sound(rpg_t *rpg, char *name, char *file)
{
	sound_t **sound = &rpg->sounds;
	sound_t *node = NULL;

	if (rpg->sounds == NULL) {
		node = malloc(sizeof(sound_t));
		if (node == NULL)
			return (-1);
		fill_values(node, name, file);
		node->next = *sound;
		*sound = node;
		return (0);
	}
	node = rpg->sounds;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(sound_t));
	if (node->next == NULL)
		return (-1);
	fill_values(node->next, name, file);
	return (0);
}

int load_sounds(rpg_t *rpg)
{
	new_sound(rpg, "hover1", "assets/sounds/hover1.ogg");
	return (0);
}
