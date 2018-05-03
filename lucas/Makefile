##
## EPITECH PROJECT, 2018
## PSU_navy_2017
## File description:
## Makefile for navy project
##

## VARIABLES

NAME 		=	test

UNITS 		= 	units

SRC_DIR 	= 	src/

TEST_DIR	= 	tests/

SRC_FILES	= 	main.c\
			test.c\
			battle/event/event_management.c\
			battle/event/interaction.c\
			battle/event/reset_map_state.c\
			battle/event/deplacement/check_deplacement.c\
			battle/event/deplacement/deplacement.c\
			battle/event/select_or_unselect.c\
			battle/event/attack/attack.c\
			battle/ai_enemy/enemy_turn.c\
			battle/ai_enemy/enemy_attack.c\
			battle/ai_enemy/enemy_attack_anim.c\
			battle/ai_enemy/enemy_deplacement_anim.c\
			init/init_data.c\
			init/init_fight.c\
			init/init_hero.c\
			battle/display/display_map.c\
			battle/display/display_interface.c\
			battle/display/display_enemy_stats.c\
			battle/display/display_current_target.c\
			battle/display/fill_map_state.c\
			lib/create_text.c\
			lib/my_itoa.c\
			free/free_all.c\

SRC		= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

TESTS_FILES	=	$(filter-out main.c, $(SRC_FILES))

TESTS_FILES	+=	""

INCLUDE		= 	include/

LIBRARY_DIR	= 	lib/

CC		=	gcc

CFLAGS		= 	-Wall -Wextra -I $(INCLUDE) -g3

LFLAGS		= 	-L $(LIBRARY_DIR) -lmy -lc_graph_prog

UNITS_LFLAGS	= 	$(LFLAGS) -lgcov -lcriterion

## BUILD VARIABLES

BUILD_DIR		= 	build/

BUILD_TESTS_DIR		= 	tests/build/

BUILD_OBJ		= 	$(addprefix $(BUILD_DIR), $(SRC_FILES:.c=.o))

BUILD_TESTS_OBJ		= 	$(addprefix $(BUILD_TESTS_DIR), $(TESTS_FILES:.c=.o))

BUILD_SD		= 	$(shell find $(SRC_DIR) -mindepth 1 -type d -printf '%p\n' | sed -e 's/^src\///')

## RULES

all:			library $(BUILD_DIR) $(NAME)

library:
			make -C $(LIBRARY_DIR)

$(BUILD_DIR):
			mkdir -p $(BUILD_DIR)
			$(foreach SUB_DIR, $(BUILD_SD), $(shell mkdir -p $(BUILD_DIR)$(SUB_DIR)))

$(BUILD_DIR)%.o:	$(SRC_DIR)%.c
			$(CC) $(CFLAGS)   -c -o $@ $<

$(NAME):		$(BUILD_OBJ)
			$(CC) $(CFLAGS)   -o $(NAME) $(BUILD_OBJ) $(LFLAGS)

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

fclean:			clean
			rm -rf $(NAME)
			rm -rf $(UNITS)
			make fclean -C $(LIBRARY_DIR)

re:			fclean all

# Just in case those files exist in the root dir
.PHONY			: all library clean fclean re tests_run
