/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** anim
*/

#include "rpg.h"

anim_t *init_anim(void *anim_item, uint32_t delay,
	void (*set_method)(anim_t *anim))
{
	anim_t *anim = NULL;

	anim = cl_calloc(sizeof(anim_t));
	anim->anim_item = anim_item;
	set_method(anim);
	anim->delay = delay;
	anim->time_0 = 0;
	return anim;
}

void del_anim(void *self)
{
	anim_t *_self = NULL;

	_self = (anim_t *)self;
	free(_self);
}