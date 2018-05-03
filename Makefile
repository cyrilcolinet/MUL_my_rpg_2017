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

SRC_FILES				= 	main.c 									\
							rpg.c 									\
							game/wait/wait_loop.c 					\
							game/run/run_loop.c						\
							utilities/args_handling.c 				\
							utilities/struct_utils.c 				\
							utilities/options_manager.c 			\
							utilities/fct_pointers.c				\
							utilities/windows_utils.c 				\
							utilities/rect_utils.c 					\
							utilities/sound_manager.c 				\
							events/events_manager.c 				\
							events/mouse_events.c 					\
							assets/buttons_loader.c 				\
							assets/sliders_loader.c 				\
							assets/buttons_manager.c 				\
							assets/sliders_manager.c 				\
							assets/assets_manager.c 				\
							assets/setup/wait_buttons.c 			\
							assets/setup/options_buttons.c 			\
							assets/setup/options_sliders.c 			\
							assets/setup/credits_buttons.c 			\
							assets/sprite_manager.c 				\
							callback/return_callback.c 				\
							callback/sliders/volume_callback.c 		\
							callback/wait/play_btn_callback.c 		\
							callback/wait/settings_btn_callback.c 	\
							callback/wait/credits_btn_callback.c 	\
							callback/wait/quit_btn_callback.c 		\
							callback/default_callback.c 			\
							views/options_view.c 					\
							views/credits_view.c 					\
							debug/logger.c 							\
							debug/buttons_debugger.c 				\
							debug/assets_debugger.c 				\
							debug/sliders_debugger.c

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
