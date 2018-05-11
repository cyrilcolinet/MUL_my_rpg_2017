/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sounds_manager functions
*/

# include "rpg.h"

static void fill_values(sound_t *node, char *name, char *file, rpg_t *rpg)
{
	node->name = name;
	node->file = file;
	node->buffer = sfSoundBuffer_createFromFile(file);
	if (node->buffer == NULL)
		return;
	node->sound = sfSound_create();
	sfSound_setBuffer(node->sound, node->buffer);
	sfSound_setVolume(node->sound, rpg->options.music_vol);
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
		fill_values(node, name, file, rpg);
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
	fill_values(node->next, name, file, rpg);
	return (0);
}

void set_volume(rpg_t *rpg, float vol, bool music)
{
	sound_t *tmp = rpg->sounds;

	while (tmp != NULL) {
		if (my_strstartswith(tmp->name, "eff_") && !music) {
			sfSound_setVolume(tmp->sound, vol);
		} else {
			sfSound_setVolume(tmp->sound, vol);
		}
		tmp = tmp->next;
	}
}

int load_sounds(rpg_t *rpg)
{
	config_setting_t *set = parse_file("assets.cfg", "sounds");
	config_setting_t *sound = NULL;
	const char *name = NULL;
	const char *file = NULL;
	int count = 0;

	if (set == NULL)
		return (-1);

	count = config_setting_length(set);
	for (int key = 0; count > 0 && key < count; key++) {
		sound = config_setting_get_elem(set, key);
		if (sound != NULL) {
			config_setting_lookup_string(sound, "name", &name);
			config_setting_lookup_string(sound, "file", &file);
		}
		if (file != NULL && name != NULL)
			new_sound(rpg, ((char *)name), ((char *)file));
	}
	return (0);
}
