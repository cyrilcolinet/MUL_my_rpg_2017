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

	win = sfRenderWindow_create(video, "Lizz Overlay", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(win, 60);
	lizz_start(true); // Start lizz overlay

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
