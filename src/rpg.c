/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg functions
*/

# include "rpg.h"

void init_icone_spell(battle_t *battle)
{
	sfVector2f size = {50, 50};

	battle->hero->spell[0]->img = sfTexture_createFromFile(
		"assets/icons/heal_icone.png", NULL);
	battle->hero->spell[1]->img = sfTexture_createFromFile(
		"assets/icons/fire_icone.png", NULL);
	battle->hero->spell[2]->img = sfTexture_createFromFile(
		"assets/icons/ice_icone.png", NULL);
	battle->hero->spell[3]->img = sfTexture_createFromFile(
		"assets/icons/storm_icone.png", NULL);
	for (int i = 0; i < 4; i++) {
		battle->hero->spell[i]->icone = sfRectangleShape_create();
		sfRectangleShape_setSize(battle->hero->spell[i]->icone, size);
		sfRectangleShape_setTexture(
		battle->hero->spell[i]->icone, battle->hero->spell[i]->img, sfTrue);
		sfRectangleShape_setOutlineThickness(
			battle->hero->spell[i]->icone, 5);
		sfRectangleShape_setOutlineColor(
			battle->hero->spell[i]->icone, sfTransparent);
	}
}

int rpg_game(rpg_t *rpg)
{
	sfEvent event;
	int status = load_assets(rpg);

	if (status != 0)
		return (status);
	sfSound_play(get_sound(rpg, "main")->sound);
	sfSound_setLoop(get_sound(rpg, "main")->sound, sfTrue);

	init_icone_spell(rpg->battle);

	while (sfRenderWindow_isOpen(rpg->win)) {
		poll_event(rpg, &event);
		sfRenderWindow_clear(rpg->win, sfBlack);
		display_view(rpg);
		draw_buttons(rpg);
		sfRenderWindow_display(rpg->win);
	}
	exit_game(rpg);
	return (status);
}

int rpg_main(int ac, char **av)
{
	int status = check_arguments(ac, av);
	rpg_t *rpg = NULL;

	if (status != -1)
		return (status);

	rpg = configure_struct();
	if (rpg == NULL)
		return (84);

	info("Main rpg_t struct correctly configured.");
	status = rpg_game(rpg);
	free(rpg);
	info("Project correctly exited. Bye!");

	return (status);
}
