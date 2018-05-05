##
## EPITECH PROJECT, 2018
## CPE_corewar_2017
## File description:
## Corewar Folder Makefile
##

## VARIABLES

NAME					= 	my_rpg

UNITS 					= 	units

SRC_DIR 				= 	src/

TEST_DIR				= 	tests/

SRC_FILES				= 	main.c 														\
							rpg.c 														\
							game/wait/wait_loop.c 										\
							game/run/run_loop.c											\
							utilities/args_utils.c 										\
							utilities/struct_utils.c 									\
							utilities/settings_utils.c 									\
							utilities/display_utils.c									\
							utilities/windows_utils.c 									\
							utilities/rect_utils.c 										\
							utilities/sound_utils.c 									\
							utilities/debug_utils.c 									\
							utilities/debug/buttons_debugger.c 							\
							utilities/debug/assets_debugger.c 							\
							utilities/debug/sliders_debugger.c							\
							events/events_manager.c 									\
							events/mouse_events.c 										\
							managers/assets_manager.c		 							\
							managers/assets_loader_manager.c 							\
							managers/assets/buttons_loader.c 							\
							managers/assets/sliders_loader.c 							\
							managers/assets/buttons_manager.c 							\
							managers/assets/sliders_manager.c 							\
							managers/assets/setup/wait_buttons.c 						\
							managers/assets/setup/options_buttons.c 					\
							managers/assets/setup/options_sliders.c 					\
							managers/assets/setup/credits_buttons.c 					\
							managers/assets/sprite_manager.c 							\
							managers/assets/callback/return_callback.c 					\
							managers/assets/callback/sliders/volume_callback.c 			\
							managers/assets/callback/wait/play_btn_callback.c 			\
							managers/assets/callback/wait/settings_btn_callback.c 		\
							managers/assets/callback/wait/credits_btn_callback.c 		\
							managers/assets/callback/wait/quit_btn_callback.c 			\
							managers/assets/callback/default_callback.c 				\
							views/options_view.c 										\
							views/credits_view.c

SRC						= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

TESTS_FILES				=	$(filter-out main.c, $(SRC_FILES))

TESTS_FILES				+=

INCLUDE					= 	include/

LIBRARY_DIR				= 	lib/

CC						=	gcc

CFLAGS					= 	-Wall -Wextra -I $(INCLUDE) -g3 ##-lefence

LFLAGS					= 	-L $(LIBRARY_DIR) -lmy -llizz -lm -lc_graph_prog

UNITS_LFLAGS			= 	$(LFLAGS) -lgcov -lcriterion

## BUILD VARIABLES

BUILD_DIR				= 	build/

BUILD_TESTS_DIR			= 	tests/build/

BUILD_OBJ				= 	$(addprefix $(BUILD_DIR), $(SRC_FILES:.c=.o))

BUILD_TESTS_OBJ			= 	$(addprefix $(BUILD_TESTS_DIR), $(TESTS_FILES:.c=.o))

BUILD_SD				= 	$(shell find $(SRC_DIR) -mindepth 1 -type d -printf '%p\n' | sed -e 's/^src\///')

## COMPRESSION

ASSETS 					= 	assets/

ASSETS_EXISTS 			= 	$(shell [ -e $(ASSETS) ] && echo 1 || echo 0)

ASSETS_COMPRESSED 		=	assets.tar.gz

ASSETS_TGZ_EXISTS 		= 	$(shell [ -e $(ASSETS_COMPRESSED) ] && echo 1 || echo 0)

## RULES

all:					library $(BUILD_DIR) $(NAME)

library:
						$(info [INFO] Compile library)
						make -C $(LIBRARY_DIR)

assets_compress:
ifeq ($(ASSETS_EXISTS), 1)
						$(info [INFO] Compress assets to reduce size)
						tar zcvf $(ASSETS_COMPRESSED) $(ASSETS)
endif

assets_decompress:
ifeq ($(ASSETS_TGZ_EXISTS), 1)
ifeq ($(ASSETS_EXISTS), 0)
						$(info [INFO] Decompress assets)
						tar xvzf $(ASSETS_COMPRESSED)
endif
endif

$(BUILD_DIR):
						mkdir -p $(BUILD_DIR)
						$(foreach SUB_DIR, $(BUILD_SD), $(shell mkdir -p $(BUILD_DIR)$(SUB_DIR)))

$(BUILD_DIR)%.o:		$(SRC_DIR)%.c
						$(CC) $(CFLAGS)   -c -o $@ $<

$(NAME):				$(BUILD_OBJ) assets_decompress
						$(CC) $(CFLAGS)   -o $(NAME) $(BUILD_OBJ) $(LFLAGS)

tests_run:				fclean library $(UNITS)
						find $(BUILD_TESTS_DIR) -name '*.gc*' -exec mv -t ./ {} +
						./$(UNITS)

$(UNITS):				$(BUILD_TESTS_DIR) $(BUILD_TESTS_OBJ)
						$(CC) $(CFLAGS)   -o $(UNITS) $(BUILD_TESTS_OBJ) --coverage $(UNITS_LFLAGS)

$(BUILD_TESTS_DIR):
						mkdir -p $(BUILD_TESTS_DIR)$(TEST_DIR)
						$(foreach SUB_DIR, $(BUILD_SD), $(shell mkdir -p $(BUILD_TESTS_DIR)$(SUB_DIR)))

$(BUILD_TESTS_DIR)%.o:	$(SRC_DIR)%.c
						$(CC) $(CFLAGS) --coverage   -c -o $@ $<

$(BUILD_TESTS_DIR)%.o:	$(TEST_DIR)%.c
						$(CC) $(CFLAGS) --coverage   -c -o $@ $<

clean:
						rm -rf $(BUILD_DIR)
						rm -rf $(BUILD_TESTS_DIR)
						find -name '*.gc*' -delete -or -name 'vgcore.*' -delete -o -name '*.o' -delete
						make clean -C $(LIBRARY_DIR)

fclean:					clean
						rm -rf $(NAME)
						rm -rf $(UNITS)
						make fclean -C $(LIBRARY_DIR)

re:						fclean all

# Just in case those files exist in the root dir
.PHONY					: all library clean fclean re tests_run
