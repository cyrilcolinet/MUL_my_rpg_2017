/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** function utils vector
*/

#include "rpg.h"

sfVector2f init_vector(float x, float y)
{
	sfVector2f vector = {x, y};

	return vector;
}

sfVector2f add_vector(sfVector2f first, sfVector2f second)
{
	first.x += second.x;
	first.y += second.y;
	return first;
}

sfVector2f multiply_vector(sfVector2f first, sfVector2f second)
{
	first.x *= second.x;
	first.y *= second.y;
	return first;
}

sfVector2f multiply_vector_scalar(sfVector2f vector, float scalar)
{
	vector.x *= scalar;
	vector.y *= scalar;
	return vector;
}