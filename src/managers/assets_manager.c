/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** assets manager
*/

# include "debug.h"
# include "rpg.h"

static void fill_values(assets_t *node, texture_t texture)
{
	node->name = texture.name;
	node->texture = texture.texture;
	node->file = texture.file;
	node->sp = texture.sp;
	node->next = NULL;
}

int new_asset(rpg_t *rpg, texture_t texture)
{
	assets_t **assets = &rpg->assets;
	assets_t *node = NULL;

	if (rpg->assets == NULL) {
		node = malloc(sizeof(assets_t));
		if (node == NULL)
			return (-1);
		fill_values(node, texture);
		node->next = *assets;
		*assets = node;
		return (0);
	}
	node = rpg->assets;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(assets_t));
	if (node->next == NULL)
		return (-1);
	fill_values(node->next, texture);
	return (0);
}

int create_texture(rpg_t *rpg, char *name, char *file)
{
	texture_t texture;
	int res = 84;

	texture.name = name;
	texture.file = file;
	texture.texture = sfTexture_createFromFile(texture.file, NULL);
	if (texture.texture == NULL)
		return (84);

	texture.sp = sfSprite_create();
	sfSprite_setTexture(texture.sp, texture.texture, sfFalse);

	res = new_asset(rpg, texture);
	return (res);
}

void configure_assets(rpg_t *rpg)
{
	create_texture(rpg, "bg_main", "assets/menus/main.png");
	create_texture(rpg, "bg_pause", "assets/menus/pause.png");
	create_texture(rpg, "buttons", "assets/spritesheets/buttons.png");
	create_texture(rpg, "bg_pause", "assets/menus/pause.png");
	create_texture(rpg, "bg_settings", "assets/menus/options.png");
	create_texture(rpg, "bg_settings1", "assets/menus/options2.png");
	create_texture(rpg, "bg_select", "assets/menus/select.png");
	create_texture(rpg, "bg_history", "assets/menus/history.png");
	create_texture(rpg, "bg_credits", "assets/menus/credits.png");
	create_texture(rpg, "map1", "assets/map/map_1.png");
	create_texture(rpg, "map1", "assets/map/map_2.png");
	create_texture(rpg, "fight1", "assets/map/fight_1.png");
	create_texture(rpg, "fight2", "assets/map/fight_2.png");
	create_texture(rpg, "fight3", "assets/map/fight_3.png");
	create_texture(rpg, "booksheet", "assets/spritesheets/book.png");
	create_texture(rpg, "slash", "assets/spell/anim_attack.png");
	create_texture(rpg, "fire", "assets/spell/fire_spell.png");
	create_texture(rpg, "storm", "assets/spell/lightning_spell.png");
	create_texture(rpg, "heal", "assets/spell/heal_spell.png");	
	create_texture(rpg, "ice", "assets/spell/ice_spell.png");
	create_texture(rpg, "brigand1", "assets/champion/brigand_knife.png");
	create_texture(rpg, "brigand2", "assets/champion/brigand_knife2.png");
	create_texture(rpg, "orc1", "assets/champion/orc_knife.png");
	create_texture(rpg, "orc2", "assets/champion/orc_masse.png");
	create_texture(rpg, "orc3", "assets/champion/orc_spear.png");
	create_texture(rpg, "squelette1", "assets/champion/squelette_knife.png");
	create_texture(rpg, "squelette2", "assets/champion/squelette_spear.png");
	create_texture(rpg, "squelette3", "assets/champion/squelette_sword.png");
	create_texture(rpg, "paysan", "assets/champion/paysan.png");
	create_texture(rpg, "soldat1", "assets/champion/soldat_masse.png");
	create_texture(rpg, "soldat2", "assets/champion/soldat_sword.png");
	create_texture(rpg, "man_nu_no", "assets/champion/man_nu_no.png");
	create_texture(rpg, "man_nu_knife", "assets/champion/man_nu_knife.png");
	create_texture(rpg, "man_nu_sword", "assets/champion/man_nu_sword.png");
	create_texture(rpg, "man_cuir_no", "assets/champion/man_cuir_no.png");
	create_texture(rpg, "man_cuir_knife", "assets/champion/man_cuir_knife.png");
	create_texture(rpg, "man_cuir_sword", "assets/champion/man_cuir_sword.png");
	create_texture(rpg, "man_fer_no", "assets/champion/man_fer_no.png");
	create_texture(rpg, "man_fer_knife", "assets/champion/man_fer_knife.png");
	create_texture(rpg, "man_fer_sword", "assets/champion/man_fer_sword.png");
	create_texture(rpg, "women_nu_no", "assets/champion/women_nu_no.png");
	create_texture(rpg, "women_nu_knife", "assets/champion/women_nu_knife.png");
	create_texture(rpg, "women_nu_sword", "assets/champion/women_nu_sword.png");
	create_texture(rpg, "women_cuir_no", "assets/champion/women_cuir_no.png");
	create_texture(rpg, "women_cuir_knife", "assets/champion/women_cuir_knife.png");
	create_texture(rpg, "women_cuir_sword", "assets/champion/women_cuir_sword.png");
	create_texture(rpg, "women_fer_no", "assets/champion/women_fer_no.png");
	create_texture(rpg, "women_fer_knife", "assets/champion/women_fer_knife.png");
	create_texture(rpg, "women_fer_sword", "assets/champion/women_fer_sword.png");
	create_texture(rpg, "armor", "assets/icone/armor.png");
	create_texture(rpg, "hp", "assets/icone/hp.png");
	create_texture(rpg, "dmg", "assets/icone/dmg.png");
}

int load_assets(rpg_t *rpg)
{
	configure_assets(rpg);
	start_loader(rpg);
	print_assets(rpg);
	print_buttons(rpg);
	print_sliders(rpg);
	load_sounds(rpg);

	return (0);
}
