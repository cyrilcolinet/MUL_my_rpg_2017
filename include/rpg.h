/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg functions (header file)
*/

# ifndef PG_H
# define PG_H

# include "my.h"
# include "structs.h"

// Debug global variable
bool 	debug;

typedef struct c_assets_t {
	char 	*name;
	char 	*filename;
}	c_assets_t;

// rpg.c
void 		exit_game(rpg_t *);
int 		rpg_game(rpg_t *);
int			rpg_main(int, char **);


/*
** Events manager
** Management of events (mouse, keyboard, etc...)
*/

// events_manager.c
void 		mouse_manager(rpg_t *, sfEvent *);
void 		poll_event(rpg_t *, sfEvent *);

// events/mouse_events.c
void 		mouse_button_pressed(rpg_t *, sfMouseButtonEvent);
void 		mouse_button_released(rpg_t *, sfMouseButtonEvent);
void 		mouse_moved(rpg_t *, sfMouseMoveEvent);


/*
** Assets manager
** Manage buttons, sliders, views and menus
*/

// assets_manager.c
int 		new_asset(rpg_t *, texture_t);
int			create_texture(rpg_t *, char *, char *);
c_assets_t 	**configure_assets(void);
int 		load_assets(rpg_t *);

// assets_loader_manager.c
void 		load_buttons(rpg_t *);
void 		start_loader(rpg_t *);

// assets/getter.c
sfSprite	*get_sprite(rpg_t *, char *);
sfTexture	*get_texture(rpg_t *, char *);

// assets/button_manager.c
void 		callback_btn(button_t *, button_t);
void 		add_button(rpg_t *, button_t);
button_t	*is_button(rpg_t *, int, int);
void 		draw_buttons(rpg_t *);
button_t 	*get_button(rpg_t *, char *, state_e);

// callback/goto_view_callback.c
void 		cb_goto_credits_view(rpg_t *, button_t *);
void 		cb_goto_play_view(rpg_t *, button_t *);
void 		cb_goto_settings_view(rpg_t *, button_t *);

// callback/actions_callback.c
void 		cb_quit_action(rpg_t *, button_t *);
void 		cb_return_action(rpg_t *, button_t *);
void 		cb_void_action(rpg_t *, button_t *);
void 		cb_click_action(rpg_t *, button_t *);
void 		cb_hover_action(rpg_t *, button_t *);


/*
** Views gesture
** Menu displaying with their actions etc...
*/

// menu_views.c
void 		credits_view(rpg_t *);
void 		settings_view(rpg_t *);
void 		main_view(rpg_t *);

// play_view.c
void 		play_view(rpg_t *);


/*
** Utilities
** Struct utils, pointers utils and more...
*/

// args_utils.c
int 		check_arguments(int, char **);

// debug_utils.c
void 		info(char *);
void 		warning(char *);
void 		print_key_value_str(char *, char *);
void 		print_key_value_int(char *, int);

// display_utils.c
void 		display_view(rpg_t *);

// rect_utils.c
void 		reset_to_normal_rect(rpg_t *);

// settings_utils.c
char 		*my_itoa(int);
char 		*get_sound_in_str(int);

// sound_utils.c
void 		configure_audio(rpg_t *);

// struct_utils.c
void 		destroy_buttons(rpg_t *);
void 		destroy_assets(rpg_t *);
void 		destroy_slides(rpg_t *);
rpg_t 		*configure_struct(void);

// windows_tils.c
void 		set_favicon(rpg_t *);

# endif
