/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** hover_player_sexe functions
*/

# include "rpg.h"

void perform_mouse_move(rpg_t *rpg, sfVector2f h_pos, sfVector2f f_pos,
	sfEvent *ev)
{
	sfMouseMoveEvent move = ev->mouseMove;

	if ((move.x >= h_pos.x && move.x <= (h_pos.x + 218))
	&& (move.y >= h_pos.y && move.y <= (h_pos.y + 208))) {
		sfRectangleShape_setPosition(rpg->shape, h_pos);
		rpg->select_hovered = true;
	} else if ((move.x >= f_pos.x && move.x <= (f_pos.x + 218))
	&& (move.y >= f_pos.y && move.y <= (f_pos.y + 208))) {
		sfRectangleShape_setPosition(rpg->shape, f_pos);
		rpg->select_hovered = true;
	} else {
		rpg->select_hovered = false;
	}
}

void perform_mouse_click(rpg_t *rpg, sfVector2f h_pos, sfVector2f f_pos,
	sfEvent *ev)
{
	sfMouseButtonEvent click = ev->mouseButton;

	if ((click.x >= h_pos.x && click.x <= (h_pos.x + 218))
	&& (click.y >= h_pos.y && click.y <= (h_pos.y + 208))) {
		sfRectangleShape_setPosition(rpg->shape, h_pos);
		sfRectangleShape_setOutlineColor(rpg->shape, sfBlack);
		sfRectangleShape_setOutlineThickness(rpg->shape, 6);
		rpg->player->sexe = 1;
	} else if ((click.x >= f_pos.x && click.x <= (f_pos.x + 218))
	&& (click.y >= f_pos.y && click.y <= (f_pos.y + 208))) {
		sfRectangleShape_setPosition(rpg->shape, f_pos);
		sfRectangleShape_setOutlineColor(rpg->shape, sfBlack);
		sfRectangleShape_setOutlineThickness(rpg->shape, 6);
		rpg->player->sexe = 2;
	}
}

bool ev_selection_sexe(rpg_t *rpg, sfEvent *event)
{
	sfVector2f h_pos = { 665, 383 };
	sfVector2f f_pos = { 1002, 383 };

	if (event->type == sfEvtMouseMoved && rpg->player->sexe == 0) {
		perform_mouse_move(rpg, h_pos, f_pos, event);
	} else if (event->type == sfEvtMouseButtonReleased) {
		perform_mouse_click(rpg, h_pos, f_pos, event);
	}

	return true;
}
