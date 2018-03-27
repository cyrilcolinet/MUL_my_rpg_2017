/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** btn_sprite functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static void print_debug(char *btn, int x, int y)
{
	lizz_info("Position of \"");
	lizz_print(1, btn);
	lizz_print(1, "\" button changed to: x = ");
	lizz_print(1, lizz_itoa(x));
	lizz_print(1, ", y = ");
	lizz_print(1, lizz_itoa(y));
	lizz_print(1, "\n");
}

/*
** Changer la position d'une sprite
** @param (btn_t *btn) - Bouton
** @param (int x) - Position en x
** @param (int y) - Position en y
** @return (void)
*/
void lizz_btn_set_position(btn_t *btn, int x, int y)
{
	sfVector2f pos;

	if (!btn) {
		lizz_error("Button can't be NULL.\n");
		return;
	}

	if (!btn->sprite || !btn->texture || !btn->name)
		return;

	pos.x = x;
	pos.y = y;
	sfSprite_setPosition(btn->sprite, pos);
	print_debug(btn->name, x, y);
}
