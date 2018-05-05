/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** assets_manager functions
*/

# include "debug.h"
# include "rpg.h"

int new_asset(rpg_t *rpg, texture_t texture)
{
	assets_t *tmp = rpg->assets;

	while (tmp != NULL)
		tmp = tmp->next;

	tmp = malloc(sizeof(assets_t));
	if (tmp == NULL)
		return (84);

	tmp->name = texture.name;
	tmp->texture = texture.texture;
	tmp->file = texture.file;
	tmp->sp = texture.sp;
	tmp->next = NULL;

	return (0);
}

void load_buttons(rpg_t *rpg)
{
	load_wait_buttons(rpg);
	load_settings_buttons(rpg);
	load_credits_buttons(rpg);
}

void load_sliders(rpg_t *rpg)
{
	load_options_sliders(rpg);
}

int create_texture(rpg_t *rpg, char *name, char *file)
{
	texture_t texture;

	texture.name = name;
	texture.file = file;
	texture.texture = sfTexture_createFromFile(texture.file, NULL);
	if (texture.texture == NULL)
		return (84);

	texture.sp = sfSprite_create();
	sfSprite_setTexture(texture.sp, texture.texture, sfFalse);

	return (new_asset(rpg, texture));
}

int load_assets(rpg_t *rpg)
{
	int status = 0;

	configure_audio(rpg);
	rpg->font = sfFont_createFromFile("assets/GROBOLD.ttf");
	create_texture(rpg, aWaitBg, "assets/main_menu.png");
	create_texture(rpg, aBtnSp, "assets/buttons.png");
	create_texture(rpg, aPauseBg, "assets/pause_menu.png");
	create_texture(rpg, aOptionsBg, "assets/options_menu.png");
	create_texture(rpg, aCreditsBg, "assets/credits_menu.png");
	create_texture(rpg, aHoomansSp, "assets/hoomans.png");
	create_texture(rpg, aMap1, "assets/map/1.png");
	load_buttons(rpg);
	load_sliders(rpg);
	print_assets(rpg);
	print_buttons(rpg);
	print_sliders(rpg);

	return (status);
}
