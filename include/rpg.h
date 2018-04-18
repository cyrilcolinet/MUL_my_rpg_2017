/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** RPG functions (header file)
*/

#ifndef _RPG_H
#define _RPG_H

typedef struct game_s game_t;

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif

#ifndef _STDDEF_H
#include <stddef.h>
#endif

#ifndef _UNISTD_H
#include <unistd.h>
#endif

#ifndef _FCNTL_H
#include <fcntl.h>
#endif

#ifndef _LIMITS_H
#include <limits.h>
#endif

#ifndef SFML_GRAPHICS_H
#include <SFML/Graphics.h>
#endif

#ifndef SFML_AUDIO_H
#include <SFML/Audio.h>
#endif

#ifndef SFML_NETWORK_H
#include <SFML/Network.h>
#endif

#ifndef _MATH_H
#include <math.h>
#endif

#ifndef _MY_H
#include "my.h"
#endif

#ifndef _DRAW_H
#include "draw.h"
#endif

#ifndef _STATE_H
#include "state.h"
#endif

#ifndef _GAME_H
#include "game.h"
#endif

#ifndef _EVENT_H
#include "event.h"
#endif

#ifndef lua_h
#include <lua.h>
#endif

#undef MY_ERROR_CODE
#define MY_ERROR_CODE 84

#undef SMALLEST_KEY
#define SMALLEST_KEY sfKeyLeft

#undef BIGGEST_KEY
#define BIGGEST_KEY sfKeyDown

#undef SPRITE_HEIGHT
#define SPRITE_HEIGHT 32

#undef SPRITE_WIDTH
#define SPRITE_WIDTH 32

#undef SPRITESHEET_HEIGHT
#define SPRITESHEET_HEIGHT 4

#undef SPRITESHEET_WIDTH
#define SPRITESHEET_WIDTH 4

#undef WINDOW_HEIGHT
#define WINDOW_HEIGHT 1080

#undef WINDOW_WIDTH
#define WINDOW_WIDTH 1920

#undef WINDOW_TITLE
#define WINDOW_TITLE "my_rpg"

#undef FRAMERATE
#define FRAMERATE 60

#undef NBR_STATES
#define NBR_STATES 1

#endif