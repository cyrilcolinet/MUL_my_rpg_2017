/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player base settigs
*/

#include "rpg.h"

//TODO replace this by map parsing
static int **configure_layer(void)
{
	char **_layer = NULL;
	int **h_layer = NULL;
	int fd = open("hitbox1", O_RDONLY);

	_layer = malloc(sizeof(char *) * 35);
	h_layer = malloc(sizeof(int *) * 35);
	_layer[34] = NULL;
	h_layer[34] = NULL;
	for (int i = 0; i < 34; i++) {
		_layer[i] = malloc(sizeof(char) * 61);
		_layer[i][60] = '\0';
		h_layer[i] = malloc(sizeof(int) * 60);
	}
	for (int i = 0; i < 34; i++) {
		read(fd, _layer[i], 61);
		_layer[i][60] = '\0';
	}
	for (int i = 0; i < 34; i++)
		for (int j = 0; j < 60; j++)
			h_layer[i][j] = _layer[i][j] - '0';
	for (int i = 0; _layer[i] != NULL; i++)
		free(_layer[i]);
	free(_layer);
	return h_layer;
}

static sfRenderStates *init_render_state(void)
{
	sfRenderStates *render_state = NULL;

	render_state = malloc(sizeof(sfRenderStates));
	render_state->blendMode = sfBlendAlpha;
	render_state->shader = NULL;
	render_state->texture = NULL;
	render_state->transform = sfTransform_Identity;
	render_state->transform = sfTransform_fromMatrix(0.75, 0, 624.0, 0,
		0.75, 0, 0, 0, 1);
	return render_state;
}

void configure_player(rpg_t *rpg)
{
	rpg->player = malloc(sizeof(player_t));
	rpg->player->sprite = (void **)&rpg->battle->hero->form;
	rpg->player->direction = up;
	rpg->player->rect.top = 0;
	rpg->player->rect.left = 0;
	rpg->player->rect.width = 64;
	rpg->player->rect.height = 64;
	rpg->player->time_0 = sfSeconds(0);
	rpg->player->render_state = init_render_state();
	rpg->player->layer = configure_layer();
	info("Player base settings loaded");
}