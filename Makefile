##
## EPITECH PROJECT, 2018
## CPE_corewar_2017
## File description:
## Corewar Folder Makefile
##

## VARIABLES

NAME			= 	my_rpg

UNITS 			= 	units

SRC_DIR 		= 	src/

TEST_DIR		= 	tests/

SRC_FILES		= 	main.c 							\
				rpg.c 							\
				sound/sounds_manager.c 					\
				assets/assets_manager.c		 			\
				assets/assets_loader_manager.c 				\
				assets/buttons_manager.c 				\
				assets/sliders_manager.c 				\
				assets/getter.c 					\
				assets/callback/actions_callback.c 			\
				assets/callback/goto_view_callback.c 			\
				assets/callback/goto_view_callback2.c 			\
				assets/callback/play_callback.c 			\
				assets/callback/sliders/volume_callback.c 		\
				events/events_manager.c 				\
				events/mouse_events.c					\
				events/views_events.c					\
				events/play/events.c	 				\
				events/selection/events.c				\
				configurations/views_config.c 				\
				configurations/views/credits/buttons.c 			\
				configurations/views/main/buttons.c 			\
				configurations/views/main/history_button.c 		\
				configurations/views/settings/buttons.c 		\
				configurations/views/settings/sliders.c			\
				configurations/views/pause/buttons.c 			\
				configurations/views/history/buttons.c 			\
				configurations/views/selection/buttons.c		\
				configurations/views/play/buttons.c			\
				parser/parser.c 					\
				parser/battle_fights_parser.c 				\
				parser/battle_character_parser.c			\
				parser/map_parser.c 					\
				parser/parse_map_hitboxes.c 				\
				views/menu_views.c 					\
				views/play_view.c 					\
				views/main_view.c 					\
				views/battle_view.c					\
				views/display_view.c 					\
				battle/battle_management.c				\
				battle/event/event_management.c				\
				battle/event/interaction.c				\
				battle/event/change_turn.c				\
				battle/event/reset_map_state.c				\
				battle/event/deplacement/deplacement.c			\
				battle/event/spell/cast_spell.c				\
				battle/event/attack/attack.c				\
				battle/event/select_or_unselect.c			\
				battle/hero/check_attack.c				\
				battle/hero/check_deplacement.c				\
				battle/hero/hero_attack.c				\
				battle/hero/hero_set_attack.c				\
				battle/hero/hero_deplacement.c				\
				battle/hero/display_enemy_dead_animation.c		\
				battle/hero/display_hero_damage.c			\
				battle/hero/hero_set_deplacement_color.c		\
				battle/spell/cast_spell.c				\
				battle/spell/display_case.c				\
				battle/spell/display_spell_damage.c			\
				battle/spell/cast_heal.c				\
				battle/spell/cast_fire.c				\
				battle/spell/cast_ice.c					\
				battle/spell/cast_storm.c				\
				battle/spell/hit_the_target.c				\
				battle/ai_enemy/enemy_turn.c				\
				battle/ai_enemy/enemy_attack.c				\
				battle/ai_enemy/enemy_attack_anim.c			\
				battle/ai_enemy/enemy_deplacement_left.c		\
				battle/ai_enemy/enemy_deplacement_right.c		\
				battle/ai_enemy/enemy_deplacement_up.c			\
				battle/ai_enemy/enemy_deplacement_down.c		\
				battle/ai_enemy/display_enemy_damage.c			\
				battle/init/configure_battle.c				\
				battle/display/display_map.c				\
				battle/display/display_interface.c			\
				battle/display/display_enemy_stats.c			\
				battle/display/display_current_target.c			\
				battle/display/fill_map_state.c				\
				debug/debugger.c					\
				debug/buttons_debugger.c 				\
				debug/assets_debugger.c 				\
				debug/sliders_debugger.c				\
				utilities/struct_utils.c 				\
				utilities/destroyer/assets.c 				\
				utilities/destroyer/battle.c 				\
				utilities/destroyer/general.c 				\
				utilities/destroyer/player.c 				\
				utilities/csfml/text.c 					\
				utilities/csfml/animations.c 				\
				utilities/csfml/rectangle.c 				\
				utilities/csfml/sound.c					\
				utilities/csfml/windows.c				\
				utilities/parsing/get_next_line.c 			\
				utilities/parsing/arguments.c

SRC			= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

TESTS_FILES		=	$(filter-out main.c, $(SRC_FILES))

TESTS_FILES		+=

INCLUDE			= 	include/

LIBRARY_DIR		= 	lib/

CC			=	gcc

CFLAGS			= 	-g3 -Wall -Wextra -I $(INCLUDE) ##-lefence

LFLAGS			= 	-L $(LIBRARY_DIR) -lmy -lm -lc_graph_prog -Wl,-rpath=$(LIBRARY_DIR) -lconfig

UNITS_LFLAGS		= 	$(LFLAGS) -lgcov -lcriterion

## BUILD VARIABLES

BUILD_DIR		= 	build/

BUILD_TESTS_DIR		= 	tests/build/

BUILD_OBJ		= 	$(addprefix $(BUILD_DIR), $(SRC_FILES:.c=.o))

BUILD_TESTS_OBJ		= 	$(addprefix $(BUILD_TESTS_DIR), $(TESTS_FILES:.c=.o))

BUILD_SD		= 	$(shell find $(SRC_DIR) -mindepth 1 -type d -printf '%p\n' | sed -e 's/^src\///')

## COMPRESSION

ASSETS 			= 	assets/

ASSETS_EXISTS 		= 	$(shell [ -e $(ASSETS) ] && echo 1 || echo 0)

ASSETS_COMPRESSED 	=	assets.tar.gz

ASSETS_TGZ_EXISTS 	= 	$(shell [ -e $(ASSETS_COMPRESSED) ] && echo 1 || echo 0)

## RULES

all:			library $(BUILD_DIR) $(NAME)

library:
			$(info [INFO] Compile library)
			make -C $(LIBRARY_DIR)
			make -C extern_libs/

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
##			rm -rf $(ASSETS_COMPRESSED)
endif
endif

$(BUILD_DIR):
			mkdir -p $(BUILD_DIR)
			$(foreach SUB_DIR, $(BUILD_SD), $(shell mkdir -p $(BUILD_DIR)$(SUB_DIR)))

$(BUILD_DIR)%.o:	$(SRC_DIR)%.c
			$(CC) $(CFLAGS)   -c -o $@ $<

$(NAME):		$(BUILD_OBJ) assets_decompress
			@$(CC) $(CFLAGS)   -o $(NAME) $(BUILD_OBJ) $(LFLAGS)

tests_run:		fclean library $(UNITS)
			find $(BUILD_TESTS_DIR) -name '*.gc*' -exec mv -t ./ {} +
			./$(UNITS)

$(UNITS):		$(BUILD_TESTS_DIR) $(BUILD_TESTS_OBJ)
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
			make clean -C extern_libs

fclean:			clean
			rm -rf $(NAME)
			rm -rf $(UNITS)
			make fclean -C $(LIBRARY_DIR)
			make fclean -C extern_libs

re:			fclean all

# Just in case those files exist in the root dir
.PHONY			: all library clean fclean re tests_run
