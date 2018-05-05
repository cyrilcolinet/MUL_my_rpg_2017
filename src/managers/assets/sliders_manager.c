/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sliders_manager functions
*/

# include "rpg.h"

static void fill_values(slider_t *node, slider_t conf)
{
	node->name = conf.name;
	node->range = conf.range;
	node->mid_axis = conf.mid_axis;
	node->btn = conf.btn;
	node->text = conf.text;
	node->state = conf.state;
	node->onSlide = conf.onSlide;
	node->next = NULL;
}

void add_slider(rpg_t *rpg, slider_t conf)
{
	slider_t **assets = &rpg->slides;
	slider_t *node = NULL;

	if (rpg->slides == NULL) {
		node = malloc(sizeof(slider_t));
		if (node == NULL)
			return;
		fill_values(node, conf);
		node->next = *assets;
		*assets = node;
		return;
	}
	node = rpg->slides;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(slider_t));
	if (node->next == NULL)
		return;
	fill_values(node->next, conf);
}
