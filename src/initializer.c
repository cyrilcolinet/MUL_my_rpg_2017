/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** struct_utils functions
*/

# include "rpg.h"

void configure_textures2(battle_t *btl)
{
	sfVector2f pos = { 0, 0 };
	sfVector2f size = { 1920, 1080 };

	btl->background = sfRectangleShape_create();
	sfRectangleShape_setPosition(btl->background, pos);
	sfRectangleShape_setSize(btl->background, size);
	sfRectangleShape_setTexture(btl->background, btl->texture[4], sfTrue);
}

void configure_textures(rpg_t *rpg, battle_t *btl)
{
	sfVector2f pos = { 30, 10 };
	sfVector2f size = { 20, 20 };

	btl->icone = sfRectangleShape_create();
	sfRectangleShape_setPosition(btl->icone, pos);
	sfRectangleShape_setSize(btl->icone, size);

	btl->texture = malloc(sizeof(sfTexture *) * 8);
	if (btl->texture != NULL) {
		btl->texture[0] = get_texture(rpg, "hp");
		btl->texture[1] = get_texture(rpg, "dmg");
		btl->texture[2] = get_texture(rpg, "armor");
		btl->texture[3] = get_texture(rpg, "arrow");
		btl->texture[4] = get_texture(rpg, "fight1");
		btl->texture[5] = get_texture(rpg, "fight2");
		btl->texture[6] = get_texture(rpg, "fight3");
		btl->texture[7] = NULL;
	}

	configure_textures2(btl);
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

	rpg->battle->text = create_text(rpg->font, "Interface", pos, sfWhite);
	rpg->battle->run = false;

	if (configure_battle_fights(rpg) != 0)
		return (false);
	configure_textures(rpg, rpg->battle);

	return (true);
}

bool fill_struct_values(rpg_t *rpg)
{
	rpg->capture = NULL;
	rpg->font = sfFont_createFromFile("assets/fonts/Vecna.otf");
	rpg->text = sfText_create();
	sfText_setFont(rpg->text, rpg->font);
	rpg->saves = NULL;
	rpg->battle = malloc(sizeof(battle_t));
	if (rpg->battle == NULL)
		return (false);
	rpg->battle->fight = NULL;
	rpg->battle->clock = sfClock_create();
	rpg->battle->map = malloc(sizeof(int *) * 10);
	if (rpg->battle->map == NULL)
		return (false);
	rpg->battle->id = 0;
	rpg->battle->mouse.x = 0;
	rpg->battle->mouse.y = 0;
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
	sfRenderWindow_setFramerateLimit(rpg->win, 60);
	rpg->player = NULL;
	rpg->clock = sfClock_create();
	rpg->options.music_vol = 0;
	rpg->options.sound_vol = 0;
	rpg->assets = NULL;
	rpg->btn = NULL;
	rpg->slides = NULL;
	rpg->sounds = NULL;
	rpg->map_id = 0;
	return (rpg);
}
