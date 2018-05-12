/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** struct_utils functions
*/

# include "rpg.h"

bool configure_internal_battle(rpg_t *rpg)
{
	for (int i = 0; i < 10; i++) {
		rpg->battle->map[i] = malloc(sizeof(int) * 12);
		if (rpg->battle->map[i] == NULL)
			return (false);
		for (int j = 0; j < 12; j++)
			rpg->battle->map[i][j] = 0;
	}

	if (configure_battle_fights(rpg) != 0)
		return (false);

	return (true);
}

bool configure_internal_struct(rpg_t *rpg)
{
	rpg->assets = NULL;
	rpg->btn = NULL;
	rpg->slides = NULL;
	rpg->sounds = NULL;
	rpg->battle = malloc(sizeof(battle_t));
	if (rpg->battle == NULL)
		return (false);

	rpg->battle->fight = NULL;
	rpg->battle->text = NULL;
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
	if (!configure_internal_struct(rpg))
		return (NULL);
	rpg->clock = sfClock_create();
	rpg->options.music_vol = rpg->options.sound_vol = 67;
	return (rpg);
}
