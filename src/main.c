/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main function
*/

#include "rpg.h"

int main(int ac, char **av, char **env)
{
	sfRenderWindow *window = NULL;
	sfVideoMode mode = {800, 600, 32};
	sfEvent event;
	btn_t btn;

	(void)ac;
	(void)av;
	lua_close(NULL);
	if (env == NULL)
		return (84);
	window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed || (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape))
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	return (0);
}