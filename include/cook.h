/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** cook functions (header file)
*/

# ifndef COOK_H
# define COOK_H

# include "my.h"
# include "structs.h"

// Assets id definition
# define aWaitBg 		(0)
# define aBtnSp		 	(1)
# define aPauseBg 		(2)
# define aOptionsBg		(3)
# define aCreditsBg 	(4)
# define aHoomansSp		(5)

// rpg.c
void 	exit_game(cook_t *cook);
int		rpg_game(cook_t *cook);
int 	rpg_main(int ac, char **av);

// game/wait/wait_loop.c
void 	wait_loop(cook_t *cook);

// game/run/run_loop.c
void 	run_loop(cook_t *cook);

// utilities/args_handling.c
int 	check_arguments(int ac, char **av);

// utilities/struct_utils.c
void 	destroy_buttons(cook_t *cook);
void 	destroy_assets(cook_t *cook);
void 	destroy_slides(cook_t *cook);
cook_t 	*configure_struct(void);

// utilities/debug_utils.c
void 	info(char *msg);
void 	warning(char *msg);

// utilities/options_manager.c
char 	*my_itoa(int nb);
char 	*get_sound_in_str(int nb);

// utilities/rect_utils.c
void 	reset_to_normal_rect(cook_t *cook);

// utilities/fct_pointers.c
void 	fct_pointers(cook_t *cook);

// utilities/sound_manager.c
void 	configure_audio(cook_t *cook);

// events/events_manager.c
void 	mouse_manager(cook_t *cook, sfEvent *event);
void 	poll_event(cook_t *cook, sfEvent *event);

// events/window_utils.c
void 	set_favicon(cook_t *cook);

// events/mouse_events.c
void 	mouse_button_pressed(cook_t *cook, sfMouseButtonEvent mouse);
void 	mouse_button_released(cook_t *cook, sfMouseButtonEvent mouse);
void 	mouse_moved(cook_t *cook, sfMouseMoveEvent mouse);

// assets/assets_manager.c
int 	new_asset(cook_t *cook, texture_t texture);
void 	load_buttons(cook_t *cook);
void 	load_sliders(cook_t *cook);
int 	create_texture(cook_t *cook, int id, char *file);
int 	load_assets(cook_t *cook);

// assets/button_loader.c
void 	load_wait_buttons(cook_t *cook);
void 	load_credits_buttons(cook_t *cook);
void 	load_settings_buttons(cook_t *cook);

// assets/sliders_loader.c
void 	load_options_sliders(cook_t *cook);

// assets/buttons_manager.c
void 	callback_btn(button_t *btn, button_t conf);
void 	add_button(cook_t *cook, button_t conf);
button_t *is_button(cook_t *cook, int x, int y);
void 	draw_buttons(cook_t *cook);
button_t *get_button(cook_t *cook, btnType_e type, state_e state);

// assets/sliders_manager.c
void 	callback_slide(slider_t *slide, slider_t conf);
void 	add_slider(cook_t *cook, slider_t conf);
slider_t *get_slider(cook_t *cook, slideType_e type);

// assets/setup/wait_buttons.c
void 	setup_wait_play_btn(cook_t *cook);
void 	setup_wait_settings_btn(cook_t *cook);
void 	setup_wait_quit_btn(cook_t *cook);
void 	setup_wait_credits_btn(cook_t *cook);

// assets/setup/options_buttons.c
void 	setup_volume_settings_button(cook_t *cook);
void 	setup_return_settings_button(cook_t *cook);

// assets/setup/options_sliders.c
void 	setup_volume_options_slider(cook_t *cook);

// assets/setup/credits_buttons.c
void 	setup_return_credits_button(cook_t *cook);

// assets/sprite_manager.c
sfSprite *get_sprite(cook_t *cook, int id);
sfTexture *get_texture(cook_t *cook, int id);

// callback/play_btn_callback.c
void 	btn_play_released(cook_t *cook, button_t *btn);

// callback/settings_btn_callback.c
void 	btn_settings_released(cook_t *cook, button_t *btn);

// callback/credits_btn_callback.c
void 	btn_credits_released(cook_t *cook, button_t *btn);

// callback/quit_btn_callback.c
void 	btn_quit_released(cook_t *cook, button_t *btn);

// callback/return_callback.c
void 	btn_return_released(cook_t *cook, button_t *btn);

// callback/default_callback.c
void 	default_hover_callback(cook_t *cook, button_t *btn);
void 	default_click_callback(cook_t *cook, button_t *btn);
void 	nothing_callback(cook_t *cook, button_t *btn);

// callback/sliders/volume_callback.c
void 	slider_volume_callback(cook_t *cook, slider_t *slider);

// views/credits_view.c
void 	credits_view(cook_t *cook);

// views/options_view.c
void 	options_view(cook_t *cook);

# endif
