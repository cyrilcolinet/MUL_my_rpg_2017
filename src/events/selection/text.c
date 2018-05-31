/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text selection events
*/

# include "rpg.h"

void perform_text_entered(rpg_t *rpg, sfTextEvent type)
{
	int i = 0;
	sfVector2f pos = { 610, 732 };
	sfColor color = sfBlack;

	if ((type.unicode > 47 && type.unicode < 128)) {
		while (rpg->player_name[i])
			i++;
		if (i < 18) {
			color = sfColor_fromRGB(16, 17, 16);
			rpg->player_name[i] = ((char)type.unicode);
			sfText_setFont(rpg->text, rpg->font);
			sfText_setCharacterSize(rpg->text, 60);
			sfText_setColor(rpg->text, color);
			sfText_setPosition(rpg->text, pos);
			sfText_setString(rpg->text, rpg->player_name);
		}
	}
}

void perform_backspace(rpg_t *rpg, sfTextEvent type)
{
	int i = 18;

	if (type.unicode == 8) {
		while (!rpg->player_name[i])
			i--;
		rpg->player_name[i] = 0;
		sfText_setString(rpg->text, rpg->player_name);
	}
}

bool ev_selection_text(rpg_t *rpg, sfEvent *event)
{
	sfTextEvent type;

	if (event->type == sfEvtTextEntered) {
		type = event->text;
		perform_text_entered(rpg, type);
		perform_backspace(rpg, type);
	}

	return (true);
}
