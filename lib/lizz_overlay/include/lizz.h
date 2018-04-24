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

// assets/assets_textures.c
void 		lizz_assets_set_texture(assets_t *, char *, sfIntRect *);

// assets/assets_sprites.c
void 		lizz_assets_set_position(assets_t *, int, int);
void 		lizz_assets_set_texture_rect(assets_t *, sfIntRect *);
void 		lizz_assets_set_rotation(assets_t *, float);

// assets/assets_general.c
void 		lizz_assets_destroy(assets_t *);

// buttons/btn_general.c
void 		lizz_btn_create_asset(btn_t *, lizz_t *);
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
btn_t		*lizz_get_btn(lizz_t *, char *, menu_e);

// assets
int 		lizz_assets_create(lizz_t *, char *);
assets_t	*lizz_get_assets(lizz_t *, char *);

// Threads
int 		lizz_thread_create(lizz_t *, char *, void (*)(void *), void *);
thread_t 	*lizz_get_thread(lizz_t *, char *);

// Clock
int 		lizz_clock_create(lizz_t *, char *);
clk_t		*lizz_get_clock(lizz_t *, char *);

# endif
