/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg functions
*/

# include "rpg.h"

void init_icone_spell(rpg_t *rpg)
{
	hero_t *hero = rpg->battle->hero;
	sfVector2f size = {50, 50};

	hero->spell[0]->img = get_texture(rpg, "heal_icon");
	hero->spell[1]->img = get_texture(rpg, "fire_icon");
	hero->spell[2]->img = get_texture(rpg, "ice_icon");
	hero->spell[3]->img = get_texture(rpg, "storm_icon");

	for (int i = 0; i < 4; i++) {
		hero->spell[i]->icone = sfRectangleShape_create();
		sfRectangleShape_setSize(hero->spell[i]->icone, size);
		sfRectangleShape_setTexture(hero->spell[i]->icone,
			hero->spell[i]->img, sfTrue);
		sfRectangleShape_setOutlineThickness(hero->spell[i]->icone, 5);
		sfRectangleShape_setOutlineColor(hero->spell[i]->icone,
			sfTransparent);
	}
}

int rpg_game(rpg_t *rpg)
{
	sfEvent event;
	int status = load_assets(rpg);

	if (status != 0)
		return (status);

	player_parser(rpg, "demo.save"); // tmp
	init_icone_spell(rpg); // tmp

	while (sfRenderWindow_isOpen(rpg->win)) {
		poll_event(rpg, &event);
		sfRenderWindow_clear(rpg->win, sfBlack);
		display_view(rpg);
		draw_buttons(rpg);
		sfRenderWindow_display(rpg->win);
	}

	return (status);
}

int rpg_main(int ac, char **av)
{
	int status = check_arguments(ac, av);
	rpg_t *rpg = NULL;

	if (status != -1)
		return (status);

	rpg = configure_struct();
	rpg->texture = sfTexture_create(1920, 1080);
	if (rpg == NULL)
		return (84);

	status = rpg_game(rpg);
	exit_game(rpg);
	free(rpg);

	return (status);
}
