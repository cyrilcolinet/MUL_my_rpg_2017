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
	btn_t *btn = NULL;

	if (lizz_start(true) < 0) // Start lizz overlay
		return (84);

	win = sfRenderWindow_create(video, "Lizz Overlay", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(win, 60);
	lizz_btn_create("fraise", stMain);

	btn = lizz_get_btn("fraise", stMain);
	btn->setTexture(btn, "../../assets/buttons/buttons.png", NULL);
	btn->setPosition(btn, 20, 20);
	sfIntRect r = { 30, 45, 45, 65 };
	btn->setTextureRect(btn, &r);
	btn->setTextureRect(btn, NULL);

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
