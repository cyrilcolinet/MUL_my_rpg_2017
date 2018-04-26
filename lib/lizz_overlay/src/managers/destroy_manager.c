/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** destroy_manager functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static void destroy_all_btn(lizz_t *lizz)
{
	btn_t *tmp = NULL;

	while (lizz->btn != NULL) {
		tmp = lizz->btn;
		lizz->btn = lizz->btn->next;
		tmp->destroy(tmp);
		free(tmp);
	}
}

static void destroy_all_threads(lizz_t *lizz)
{
	thread_t *tmp = NULL;

	while (lizz->thread != NULL) {
		tmp = lizz->thread;
		lizz->thread = lizz->thread->next;
		tmp->destroy(tmp);
		free(tmp);
	}
}

static void destroy_all_clocks(lizz_t *lizz)
{
	clk_t *tmp = NULL;

	while (lizz->clock != NULL) {
		tmp = lizz->clock;
		lizz->clock = lizz->clock->next;
		tmp->destroy(tmp);
		free(tmp);
	}
}

void lizz_destroy_all(lizz_t *lizz)
{
	destroy_all_btn(lizz);
	destroy_all_threads(lizz);
	destroy_all_clocks(lizz);
}
