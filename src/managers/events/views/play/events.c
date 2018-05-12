/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** events for play menu
*/

# include "rpg.h"

void ev_run(rpg_t *rpg, sfEvent *event)
{
	sfVector2f movement[4] = {{-10, 0}, {10, 0}, {0, -10}, {0, 10}};
	sfVector2f multiplier = {1, 1};

	if (event->type == sfEvtKeyReleased && event->key.code == sfKeyEscape)
		cb_goto_pause_view(rpg, NULL);
	if (rpg->battle->run)
		battle_event_management(rpg, rpg->battle, event);
	else if (!rpg->battle->run) {
		if (event->type == sfEvtKeyReleased && event->key.code == sfKeyA)
			rpg->battle->run = true;
		if (!rpg->battle->run && event->type ==
		sfEvtKeyPressed && (event->key.code >= sfKeyLeft
		&& event->key.code <= sfKeyDown)) {
			update_direction(rpg->player, event->key.code - sfKeyLeft);
			if (sfTime_asMilliseconds(
			sfClock_getElapsedTime(rpg->clock)) -
			sfTime_asMilliseconds(rpg->player->time_0) > 50) {
				rpg->player->time_0 = sfClock_getElapsedTime(rpg->clock);
				next_state(rpg->player);
				sfSprite_move(*rpg->player->sprite, movement[rpg->player->direction]);
			}
		} else {
			state_reset(rpg->player);
			rpg->player->time_0 = sfSeconds(0);
		}
	}
}
