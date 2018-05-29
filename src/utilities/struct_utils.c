/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** struct_utils functions
*/

# include "rpg.h"

static void configure_textures2(battle_t *btl, sfVector2f pos)
{
	btl->background = sfRectangleShape_create();
	pos.x = pos.y = 0;
	sfRectangleShape_setPosition(btl->background, pos);
	pos.x = 1920;
	pos.y = 1080;
	sfRectangleShape_setSize(btl->background, pos);
	sfRectangleShape_setTexture(btl->background, btl->texture[4], sfTrue);
}

void configure_textures(rpg_t *rpg, battle_t *btl)
{
	sfVector2f pos = { 30, 10 };

	btl->icone = sfRectangleShape_create();
	sfRectangleShape_setPosition(btl->icone, pos);
	pos.x = pos.y = 20;
	sfRectangleShape_setSize(btl->icone, pos);
	btl->texture = malloc(sizeof(sfTexture *) * 7);
	if (btl->texture != NULL) {
		btl->texture[0] = get_texture(rpg, "hp");
		btl->texture[1] = get_texture(rpg, "dmg");
		btl->texture[2] = get_texture(rpg, "armor");
		btl->texture[3] = get_texture(rpg, "arrow");
		btl->texture[4] = get_texture(rpg, "fight1");
		btl->texture[5] = get_texture(rpg, "fight2");
		btl->texture[6] = get_texture(rpg, "fight3");
	}
	configure_textures2(btl, pos);
}

bool configure_internal_battle(rpg_t *rpg)
{
	sfVector2f pos = { 1600, 50 };

	for (int i = 0; i < 10; i++) {
		rpg->battle->map[i] = malloc(sizeof(int) * 12);
		if (rpg->battle->map[i] == NULL)
			return (false);
		for (int j = 0; j < 12; j++)
			rpg->battle->map[i][j] = 0;
	}
	rpg->font = sfFont_createFromFile("assets/fonts/Cyberspace.otf");
	if (rpg->font == NULL)
		return (false);
	rpg->battle->text = create_text(rpg->font, "Interface", pos, sfWhite);
	rpg->battle->run = false;
	if (configure_battle_fights(rpg) != 0)
		return (false);
	configure_textures(rpg, rpg->battle);

	return (true);
}

bool configure_internal_struct(rpg_t *rpg)
{
	rpg->battle = malloc(sizeof(battle_t));
	if (rpg->battle == NULL)
		return (false);

	rpg->capture = NULL;
	rpg->battle->fight = NULL;
	rpg->battle->clock = sfClock_create();
	rpg->battle->map = malloc(sizeof(int *) * 10);
	if (rpg->battle->map == NULL)
		return (false);

	rpg->battle->id = rpg->battle->mouse.x = rpg->battle->mouse.y = 0;
	rpg->battle->run = false;

	return (configure_internal_battle(rpg));
}

rpg_t *configure_struct(void)
{
	rpg_t *rpg = malloc(sizeof(rpg_t));
	sfVideoMode mode = { 1920, 1080, 32 };
	char *title = "Legacy Of The Kek | Menu Principal";

	if (rpg == NULL)
		return (NULL);
	rpg->state = gameWait;
	rpg->last_st = gameUnknown;
	rpg->win = sfRenderWindow_create(mode, title, sfClose, NULL);
	if (rpg->win == NULL)
		return (NULL);
	sfRenderWindow_setFramerateLimit(rpg->win, 60);
	rpg->clock = sfClock_create();
	rpg->options.music_vol = rpg->options.sound_vol = 5;
	rpg->assets = NULL;
	rpg->btn = NULL;
	rpg->slides = NULL;
	rpg->sounds = NULL;
	rpg->map_id = 1;
	return (rpg);
}
