/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** menu_views funtions (bis)
*/

# include "rpg.h"

void display_animated_hero(rpg_t *rpg, save_t *save, sfVector2f pos)
{
	sfTime t = sfClock_getElapsedTime(save->clock);
	sfVector2f scale = { 1.7, 1.7 };

	if (sfTime_asSeconds(t) >= sfTime_asSeconds(sfSeconds(0.1))) {
		sfClock_restart(save->clock);
		save->rec.left += 64;
		if (save->rec.left >= (64 * 9))
			save->rec.left = 0;
		sfSprite_setTextureRect(save->sprite, save->rec);
	}

	pos.y -= 7;
	sfSprite_setPosition(save->sprite, pos);
	sfSprite_setScale(save->sprite, scale);
	sfRenderWindow_drawSprite(rpg->win, save->sprite, NULL);
}

void display_slot(rpg_t *rpg, save_t *save, sfVector2f pos)
{
	sfVector2f name_pos = { pos.x + 0, pos.y + 0 };
	sfVector2f pname_pos = { pos.x + 120, pos.y + 0 };
	sfVector2f lvl_pos = { pos.x + 0, pos.y + 0 };

	display_animated_hero(rpg, save, pos);
	display_icon(rpg, "hp", pos.x + 120, pos.y + 60);
	display_icon(rpg, "dmg", pos.x + 280, pos.y + 60);
	display_icon(rpg, "armor", pos.x + 460, pos.y + 60);
	sfText_setPosition(save->pname_text, pname_pos);
	sfText_setString(save->pname_text, save->player_name);
	sfRenderWindow_drawText(rpg->win, save->pname_text, NULL);
}

int display_saves_slots(rpg_t *rpg, int *occuped)
{
	sfVector2f pos = { 583, 332 };
	save_t *tmp = rpg->saves;

	while (tmp) {
		pos.y = get_slot_position((*occuped)++);
		display_slot(rpg, tmp, pos);
		tmp->btn->pos = pos;
		tmp->btn->pos.x += 640;
		tmp->btn->pos.y += 5;
		sfSprite_setPosition(tmp->btn->sprite, tmp->btn->pos);
		tmp = tmp->next;
	}

	return (4 - *occuped);
}

void game_load_view(rpg_t *rpg)
{
	int free_slots = 0;
	int occuped = 0;
	sfSprite *sprite = get_sprite(rpg, "bg_load");

	save_loader(rpg, 0);
	if (sprite == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Jouer");

	free_slots = display_saves_slots(rpg, &occuped);
	if (free_slots != 0) {
		while (free_slots > 0) {
			printf("slot %d: disponible\n", occuped + free_slots);
			free_slots--;
		}
	}
}
