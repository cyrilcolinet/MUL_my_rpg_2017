/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** clock_general functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

/*
** Detruire une clock
** @param (clk_t *clk) - Clock à détruire
** @return (void)
*/
void lizz_clock_destroy(clk_t *clk)
{
	if (!clk)
		return;

	sfClock_destroy(clk->clock);
	lizz_info("Clock named \"");
	lizz_print(1, clk->name);
	lizz_print(1, "\" has been destroyed!\n");
}

/*
** Redémarrer une clock
** @param (clk_t *cl) - Clock à redémarrer
** @return (void)
*/
void lizz_clock_restart(clk_t *clk)
{
	if (!clk)
		return;

	sfClock_restart(clk->clock);
	lizz_info("Clock named \"");
	lizz_print(1, clk->name);
	lizz_print(1, "\" restarted!\n");
}
