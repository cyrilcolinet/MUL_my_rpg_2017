/*
** EPITECH PROJECT, 2018
** create_text
** File description:
** create text function
*/

#include "rpg.h"

sfText *create_text(sfFont *font, char *str, sfVector2f pos, sfColor color)
{
	sfText *text;

	text = sfText_create();
	sfText_setFont(text, font);
	sfText_setStyle(text, sfTextRegular);
	sfText_setColor(text, color);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, 14);
	sfText_setString(text, str);
	return (text);
}
