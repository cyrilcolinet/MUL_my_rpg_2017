/*
** EPITECH PROJECT, 2018
** draw_text_type
** File description:
** draw text function
*/

#include "rpg.h"

void draw_text_type(sfText *text, param_t *param)
{
	char *str = my_strconfigure(param->struct->size);

	for (int i = 0; i < param->struct->size; i++)
		str[i] = param->message[i];
	if (param->struct->size < param->len_message) {
		sfText_setString(text, str);
		sfRenderWindow_drawText(param->window,
					param->struct->text, NULL);
		if (param->message[param->struct->size - 1] != '\0'
		&& param->message[param->struct->size - 1] == '\n')
			wait_second(1);
		else
			wait_second(0.05);
	} else {
		param->struct->size = 0;
		wait_second(1);
	}
	free(str);
}
