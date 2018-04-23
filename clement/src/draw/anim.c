/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** anim
*/

#include "rpg.h"

anim_t *init_anim(void *anim_item, u_int32_t delay, void (*set_method)(anim_t *anim))
{
	anim_t *anim = NULL;

	anim = my_calloc(sizeof(anim_t));
	anim->anim_item = anim_item;
	set_method(anim);
	anim->delay = delay;
	anim->time_0 = 0;
}

void del_anim(anim_t *anim)
{
	free(anim);
}