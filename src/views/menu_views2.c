/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** menu_views funtions (bis)
*/

# include "rpg.h"

float get_slot_position(int slot_id)
{
	switch (slot_id) {
		case 1:
		return (464);

		case 2:
		return (588);

		case 3:
		return (729);
	}

	return (332);
}

//void display_free_slot()

void display_saves_slots(rpg_t *rpg)
{
	int free_slot = 0;
	int unavailable = 0;
	sfVector2f pos = { 583, 332 };
	save_t *tmp = rpg->saves;

	while (tmp) {
		pos.y = get_slot_position(unavailable);
		printf("x = %f, y = %f\n", pos.x, pos.y);
		tmp = tmp->next;
		unavailable++;
	}

	free_slot = (4 - unavailable);
	if (free_slot != 0) {
		while (free_slot++ < 4) {
			printf("okok\n");
		}
	}

}

void game_load_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_load");
	bool loaded = save_loader(rpg, 0);

	if (sprite == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Jouer");

	if (loaded)
		display_saves_slots(rpg);
}
