/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** save_loader functions
*/

# include "rpg.h"

void configure_load_button(rpg_t *rpg, char *name)
{
	button_t conf;
	sfIntRect rec = { 660, 480, 130, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = name;
	conf.pos.x = 0;
	conf.pos.y = 0;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_load_save;
	conf.state = gameLoadSave;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
}

void configure_extra_infos(rpg_t *rpg, save_t *node)
{
	sfIntRect rec = { 0, 192, 64, 64 };

	node->rec = rec;
	node->clock = sfClock_create();
	node->sprite = sfSprite_create();
	sfSprite_setTexture(node->sprite, node->texture, true);
	sfSprite_setTextureRect(node->sprite, rec);
	configure_load_button(rpg, node->name);
	node->btn = get_button(rpg, node->name, gameLoadSave);
	if (node->btn == NULL)
		write(2, "Button is not configured.\n", 26);
	node->next = NULL;
}

void parse_save_infos(rpg_t *rpg, save_t *node, char *name)
{
	const char *pname = NULL;
	const char *texture = NULL;
	conf_sett_t conf = parse_save_file(rpg, name, "save");

	if (conf.error || conf.set == NULL)
		return;
	config_setting_lookup_int(conf.set, "level", &node->level);
	config_setting_lookup_string(conf.set, "name", &pname);
	config_setting_lookup_string(conf.set, "hero_texture", &texture);
	node->player_name = my_strdup(((char *)pname));
	node->texture = get_texture(rpg, ((char *)texture));
	node->lvl_text = sfText_create();
	node->pname_text = sfText_create();
	node->name_text = sfText_create();
	node->name = my_strdup(name);
	extra_text_config(node->lvl_text, rpg->font, 40);
	extra_text_config(node->pname_text, rpg->font, 40);
	extra_text_config(node->name_text, rpg->font, 25);
	configure_extra_infos(rpg, node);
	config_destroy(&conf.cfg);
}

bool new_slot(rpg_t *rpg, char *file)
{
	save_t **saves = &rpg->saves;
	save_t *node = NULL;

	if (rpg->saves == NULL) {
		node = malloc(sizeof(save_t));
		if (node == NULL)
			return (false);
		parse_save_infos(rpg, node, file);
		node->next = *saves;
		*saves = node;
		return (true);
	}
	node = rpg->saves;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(save_t));
	if (node->next == NULL)
		return (false);
	parse_save_infos(rpg, node->next, file);
	return (true);
}

bool save_loader(rpg_t *rpg, int start)
{
	DIR *o_dir = NULL;
	dir_t *dir = NULL;
	int key = 0;
	int max = 4;
	char *n = NULL;

	if (rpg->saves)
		return (false);
	if ((o_dir = opendir("./saves/")) == NULL)
		return (false);
	while (++key <= max && (dir = readdir(o_dir)) != NULL) {
		if (key < start)
			continue;
		n = dir->d_name;
		if (!my_strstartswith(n, ".") && my_strendswith(n, ".save"))
			new_slot(rpg, n);
	}
	closedir(o_dir);
	return (true);
}
