/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lizz library header file
*/

# ifndef LIZZ_OVERLAY_H
# define LIZZ_OVERLAY_H

# include "structs.h"

lizz_t 		*lizz;

// lizz.c
int 		lizz_start(bool debug);
void 		lizz_stop(void);
void 		lizz_destroy_all(void);

// buttons/btn_textures.c
void 		lizz_btn_set_texture(btn_t *btn, char *file, sfIntRect *rect);

// buttons/btn_sprites.c
void 		lizz_btn_set_position(btn_t *btn, int x, int y);
void 		lizz_btn_set_texture_rect(btn_t *btn, sfIntRect *rect);
void 		lizz_btn_set_rotation(btn_t *btn, float angle);

// buttons/btn_general.c
void 		lizz_btn_destroy(btn_t *btn);

// threads/thread_general.c
void 		lizz_thread_destroy(thread_t *thread);
void 		lizz_thread_wait(thread_t *thread);
void 		lizz_thread_start(thread_t *thread);
void 		lizz_thread_terminate(thread_t *thread);

// clocks/clock_general.c
void 		lizz_clock_destroy(clk_t *thread);
void 		lizz_clock_restart(clk_t *thread);

// # # # # # # # # # # # # # # //
// #       MANAGERS          # //
// # # # # # # # # # # # # # # //

// Buttons
int 		lizz_btn_create(char *name, menu_e belongsTo);
btn_t		*lizz_get_btn(char *name, menu_e belongsTo);

// Threads
int 		lizz_thread_create(char *name, void (*c)(void *), void *data);
thread_t 	*lizz_get_thread(char *name);

// Clock
int 		lizz_clock_create(char *name);
clk_t		*lizz_get_clock(char *name);

# endif
