/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** assets_manager functions
*/

# include "debug.h"
# include "cook.h"

int new_asset(cook_t *cook, texture_t texture)
{
	assets_t *tmp = cook->assets;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = malloc(sizeof(assets_t));

	if (tmp == NULL)
		return (84);

	tmp->next->texture = texture.texture;
	tmp->next->file = texture.file;
	tmp->next->sp = texture.sp;
	tmp->next->id = texture.id;
	tmp->next->next = NULL;

	return (0);
}

void load_buttons(cook_t *cook)
{
	load_wait_buttons(cook);
	load_settings_buttons(cook);
	load_credits_buttons(cook);
}

void load_sliders(cook_t *cook)
{
	load_options_sliders(cook);
}

int create_texture(cook_t *cook, int id, char *file)
{
	texture_t texture;

	texture.id = id;
	texture.file = file;
	texture.texture = sfTexture_createFromFile(texture.file, NULL);

	if (texture.texture == NULL)
		return (84);

	texture.sp = sfSprite_create();
	sfSprite_setTexture(texture.sp, texture.texture, sfFalse);

	return (new_asset(cook, texture));
}

int load_assets(cook_t *cook)
{
	int status = 0;

	configure_audio(cook);
	cook->font = sfFont_createFromFile("assets/GROBOLD.ttf");
	create_texture(cook, aWaitBg, "assets/main_menu.png");
	create_texture(cook, aBtnSp, "assets/buttons.png");
	create_texture(cook, aPauseBg, "assets/pause_menu.png");
	create_texture(cook, aOptionsBg, "assets/options_menu.png");
	create_texture(cook, aCreditsBg, "assets/credits_menu.png");
	create_texture(cook, aHoomansSp, "assets/hoomans.png");
	load_buttons(cook);
	load_sliders(cook);
	print_assets(cook);
	print_buttons(cook);
	print_sliders(cook);

	return (status);
}
