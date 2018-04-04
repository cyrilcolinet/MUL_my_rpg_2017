/*
** EPITECH PROJECT, 2018
** create_text
** File description:
** create text function
*/

sfText *create_text(sfFont *font, char *str, sfVector2f pos, sfColor color)
{
	sfText *text;

	text = sftext_create();
	sfText_setFront(text, font);
	sfText_setStyle(text, sfTextregular);
	sfText_setColor(text, color);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, 15);
	sfText_setString(text, str);
	return (text);
}
