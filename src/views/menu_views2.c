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

void display_slot(rpg_t *rpg, save_t *save, sfVector2f pos)
{
	sfVector2f name_pos = { pos.x + 0, pos.y + 0 };
	sfVector2f pname_pos = { pos.x + 120, pos.y + 0 };
	sfVector2f lvl_pos = { pos.x + 0, pos.y + 0 };

	sfText_setPosition(save->pname_text, pname_pos);
	sfText_setString(save->pname_text, save->player_name);
	sfRenderWindow_drawText(rpg->win, save->pname_text, NULL);
}

void display_saves_slots(rpg_t *rpg)
{
	int free_slot = 0;
	int unavailable = 0;
	sfVector2f pos = { 583, 332 };
	save_t *tmp = rpg->saves;

	while (tmp) {
		pos.y = get_slot_position(unavailable);
		display_slot(rpg, tmp, pos);
		tmp = tmp->next;
		unavailable++;
	}

	free_slot = (4 - unavailable);
	if (free_slot != 0) {
		while (free_slot > 0) {
			//printf("slot %d: disponible\n", free_slot);
			free_slot--;
		}
	}
}

void game_load_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_load");

	save_loader(rpg, 0);
	if (sprite == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Jouer");
	display_saves_slots(rpg);
}
