/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lizz library header file
*/

# ifndef LIZZ_OVERLAY_H
# define LIZZ_OVERLAY_H

# include "structs.h"

// lizz.c
int 		lizz_start(lizz_t **, bool);
void 		lizz_stop(lizz_t *);
void 		lizz_destroy_all(lizz_t *);

// buttons/btn_textures.c
void 		lizz_btn_set_texture(btn_t *, char *, sfIntRect *);

// buttons/btn_sprites.c
void 		lizz_btn_set_position(btn_t *, int, int);
void 		lizz_btn_set_texture_rect(btn_t *, sfIntRect *);
void 		lizz_btn_set_rotation(btn_t *, float);

// buttons/btn_general.c
void 		lizz_btn_destroy(btn_t *);

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
int 		lizz_btn_create(lizz_t *, char *, menu_e);
btn_t		*lizz_get_btn(lizz_t *, char *name, menu_e belongsTo);

// Threads
int 		lizz_thread_create(lizz_t *, char *name, void (*c)(void *), void *data);
thread_t 	*lizz_get_thread(lizz_t *, char *name);

// Clock
int 		lizz_clock_create(lizz_t *, char *name);
clk_t		*lizz_get_clock(lizz_t *, char *name);

# endif
