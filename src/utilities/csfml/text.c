/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text_utils functions
*/

# include "rpg.h"

sfText *create_text(sfFont *font, char *str, sfVector2f pos, sfColor color)
{
	sfText *text;

	text = sfText_create();
	sfText_setFont(text, font);
	sfText_setStyle(text, sfTextRegular);
	sfText_setColor(text, color);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, 45);
	sfText_setString(text, str);
	return (text);
}

void extra_text_config(sfText *text, sfFont *font, int size)
{
	sfColor color = sfColor_fromRGB(16, 17, 16);

	sfText_setCharacterSize(text, size);
	sfText_setColor(text, color);
	sfText_setFont(text, font);
}

void display_icon_content()
{
	
}
