/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** main tests
*/

# include "lizz.h"

int main(void)
{
	sfVideoMode video = { 1600, 800, 32 };
	sfRenderWindow *win = NULL;
	sfEvent event;

	if (lizz_start(true) < 0) // Start lizz overlay
		return (84);

	win = sfRenderWindow_create(video, "Lizz Overlay", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(win, 60);

	while (sfRenderWindow_isOpen(win)) {
		while (sfRenderWindow_pollEvent(win, &event))
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				sfRenderWindow_close(win);

		sfRenderWindow_display(win);
	}

	sfRenderWindow_destroy(win);
	lizz_stop(); // Stop lizz overlay
	return (0);
}
